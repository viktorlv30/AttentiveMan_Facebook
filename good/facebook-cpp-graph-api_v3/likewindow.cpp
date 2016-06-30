#include "likewindow.h"
#include "ui_likewindow.h"


#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVariantMap>
#include <QMap>


#include <windows.h>

/*
 * constructor for new class which create new UI window for plasing likes
 */

LikeWindow::LikeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LikeWindow)
{
    //initialize the instance
	ui->setupUi(this);
	
	//create my own NetworkManager to access the Network
    mpQNman = new QNetworkAccessManager(this);
    
	//constructor creates default first element in pageList to know that we don't send request yet
	nextPagePosts.append("-");
}

/*
 * destructor of my likewindow class
 */
LikeWindow::~LikeWindow()
{
    delete mpQNman;
    delete ui;
}

/*
 *method of likewindow class where we input token from Facebook Graph API
 *return string from lineEdit field to access_token in QString format
 */
void LikeWindow::on_lineEdit_token_returnPressed()
{

    QString access_token = ui->lineEdit_token->text();

}



void LikeWindow::on_RequestButton_clicked()
{
	/*
	 *check whether request sent or not to Facebook
	 *If your request already sent - you will jump to else block
	 */
    if(nextPagePosts.last() == "-")
    {

		//get access token in local variable from ui window
        QString access_token = ui->lineEdit_token->text();
        
		//get user_id in local variable from ui window
		QString user_id = ui->lineEdit_user_id->text();

		//create url link for GET request no Facebook page
        QString base_http_url = "https://graph.facebook.com/v2.0/";
        QString what_request = "/feed?access_token=";
        QString limit_json ="&limit=25";
		
		//including first link into list of your Facebook pages
        nextPagePosts.append( base_http_url + user_id + what_request + access_token + limit_json );
		
		//create url link in QUrl format from last page of list pages in QString format 
        url = QUrl(nextPagePosts.last());
		
		//initialize my own request with created url
        mNetRequest.setUrl(url);

		//send GET request to Facebook on your page
        mpNetReplay = mpQNman->get(mNetRequest);

        //connect slots of my request to likewindow's class method for data processing when request is finished
		connect(mpNetReplay, SIGNAL(finished()), this, SLOT(requestFinished()));
		
		//connect slots of my request to likewindow's class method for error processing when request is not done
        connect(mpNetReplay, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(requestError(QNetworkReply::NetworkError)));
		
		//show on ui window confirmation to sent GET request
        ui->info_window->append("Request send!\n");
    }
    else
    {
        //if you already have got all information from Facebook page the program will do this code
		ui->info_window->append("\nYou have got all posts id already!!!");
    }

}

//error processing
void LikeWindow::requestError( QNetworkReply::NetworkError error )
{
    int debug;
    debug = 0;
}


//processing of replays from the Internet (your Facebook page)
void LikeWindow::requestFinished()
{
    //write to replay variable data from Facebook page
    QNetworkReply *replay = qobject_cast<QNetworkReply*>(sender());
	
	//remove connection to the Internet after get the replay
    disconnect(replay, SIGNAL(finished()), this, SLOT(requestFinished()));

	//Insert into string the replay from the Internet in json format
    QString strReplay = (QString)replay->readAll();

	//create json document with all data from the Internet in UTF8 code
    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReplay.toUtf8());
    
	//Create json object which can be parsing
	QJsonObject jsonObject = jsonResponse.object();
	
	//create json array only from "data" fields
    QJsonArray jsonArray = jsonObject["data"].toArray();
	
	//choose from each json data block - id and name of posts
	foreach (const QJsonValue &value, jsonArray)
    {
        QJsonObject obj = value.toObject();
        if(obj["story"].toString() != NULL)
			//inclube names of posts into propertyNames array in QString format
            propertyNames.append(obj["story"].toString());
        else if(obj["name"].toString() != NULL)
            propertyNames.append(obj["name"].toString());
        else
            propertyNames.append(obj["message"].toString());

		//inclube all id of posts into propertyValues array in QString format
        propertyValues.append(obj["id"].toString());
        //choose from complete id of post that part who is only identificator the same post(without user part identificator)
		myPostIdList.append(obj["id"].toString().section("_", 1, 2));
		
		//show all posts name and posts id on UI window
        ui->info_window->append(propertyNames.last());
        ui->info_window->append(propertyValues.last());
    }
	
	/*
	 *create container for pages of posts if your page has more than 25 posts.
	 *each 25 posts will have it own page
	 */
    QVariantMap qmap;
    if(jsonResponse.isObject())
    {
        QStringList qsList;
        QMap <QString, QVariant> qm1;

        qmap = jsonObject.toVariantMap();
        //choose from json info about main keys
		qsList = jsonObject.keys();
		//chose from array of main keys the pages what marked as "pagin"
        qm1 = qmap["paging"].toMap();

        if( qm1.value("next").toString() != NULL )
        {
            //choose from block "paging" value opposite to "next" field
			nextPagePosts.append(qm1.value("next").toString());
			
			//recursion sends GET requests to Facebook to get all information portions of 25 pieces of posts
            mNetRequest.setUrl(qm1.value("next").toString());
            mpNetReplay = mpQNman->get(mNetRequest);
            connect(mpNetReplay, SIGNAL(finished()), this, SLOT(requestFinished()));
			
			//show in counter how many posts this program processed
			ui->lcd_count_post->display(propertyValues.count());
        }
    }
	
	//increment during processing portions of posts
    strPosts_id += propertyValues;
    replay->deleteLater();

}


//convert each id number of post from iterator format to char* format
char* LikeWindow::qStrIteratorToConstChar( QStringList::iterator itr )
{
    QString current = *itr;

    char* pChar = new char[current.length()+1];
    strcpy(pChar, current.toStdString().c_str());
    return pChar;
}


//we specify marker. From example of cUrl POST request this method chooses value for that marker which split ";" symbol
char* LikeWindow::takeInfoFromCUrlCommand(const QString cUrlFromMozilla, const char* marker)
{

    QString str = cUrlFromMozilla.section(marker,1,2);
    str = str.split(";").first();
    char* value = new char[str.length()+1];
    strcpy(value, str.toStdString().c_str());

    return value;
}


//we specify marker. From example of cUrl POST request this method chooses value for that marker which split "%" symbol
char* LikeWindow::takeClientId(const QString cUrlFromMozilla, const char* marker)
{

    QString str = cUrlFromMozilla.section(marker,1,2);
    str = str.split("%").first();
    char* value = new char[str.length()+1];
    strcpy(value, str.toStdString().c_str());

    return value;
}


//we specify marker. From example of cUrl POST request this method chooses value for that marker which split "&" symbol
char* LikeWindow::takeDTGScodeFromCUrlCommand(const QString cUrlFromMozilla, const char* marker)
{

    QString str = cUrlFromMozilla.section(marker,1,2);
    str = str.split("&").first();
    char* value = new char[str.length()+1];
    strcpy(value, str.toStdString().c_str());

    return value;
}


//we specify what command we want to do - either like - 1 or dislike - 0
const char* LikeWindow::takeIsLike(bool isLike)
{
    const char* like = isLike ? "1" : "0";
    return like;
}


/*
 *create cUrl link for POST request, what we have got from previous methods
 *Base, param_1 to param_6 - is standart parts on 25/05/2016 
 */
char* LikeWindow::createCUrlLink(const QString cUrlFromMozilla,
                                 const char* number,
                                 const char* xs,
                                 const char* client_id,
                                 QStringList::iterator itr,
                                 bool doMakeLike,
                                 const char* fb_dtsg
                                 )
{

    const char* base_curl = "curl \"https://www.facebook.com/ufi/reaction/?dpr=1\" -H \"Cookie: c_user=";

    const char* user_number = takeInfoFromCUrlCommand(cUrlFromMozilla, number);

    const char* param_1 = "; xs=";

    const char* xs_code = takeInfoFromCUrlCommand(cUrlFromMozilla, xs);

    const char* param_2 = "\" --data \"client_id=";

    const char* client_id_fromCurl = takeClientId(cUrlFromMozilla, client_id);

    const char* param_3 = "&ft_ent_identifier=";

    const char* identifier_fromCurl = qStrIteratorToConstChar(itr);

    const char* param_4 = "&reaction_type=";

    const char* isLike = takeIsLike(doMakeLike);

    const char* param_5 = "&fb_dtsg=";

    const char* fb_dtsg_fromCurl = takeDTGScodeFromCUrlCommand(cUrlFromMozilla, fb_dtsg);

    const char* param_6 = "\"";

    int length = strlen(base_curl) + strlen(user_number) + strlen(param_1) +
            strlen(xs_code) + strlen(param_2) + strlen(client_id_fromCurl) +
            strlen(param_3) + strlen(identifier_fromCurl) + strlen(param_4) +
            strlen(isLike) + strlen(param_5) + strlen(fb_dtsg_fromCurl) + strlen(param_6);

    char* cUrlLike = new char[length+1];

    strcpy(cUrlLike, base_curl);
    strcat(cUrlLike, user_number);
    strcat(cUrlLike, param_1);
    strcat(cUrlLike, xs_code);
    strcat(cUrlLike, param_2);
    strcat(cUrlLike, client_id_fromCurl);
    strcat(cUrlLike, param_3);
    strcat(cUrlLike, identifier_fromCurl);
    strcat(cUrlLike, param_4);
    strcat(cUrlLike, isLike);
    strcat(cUrlLike, param_5);
    strcat(cUrlLike, fb_dtsg_fromCurl);
    strcat(cUrlLike, param_6);

    return cUrlLike;

}


//method placing likes to all posts
void LikeWindow::on_LikeButton_clicked()
{
	//show in UI window conrimation to placing likes
    ui->info_window->append("\n Makes Like\n");

	//initialize of counter of posts quantity
    int count = 0;

	//get example of cUrl POST request from Mozilla brouser duy to Firebug
    const QString cUrlFromMozilla = ui->qText_cUrlFromMozilla->toPlainText();

	//start placing likes from first post to last one
    for(QStringList::iterator itr = myPostIdList.begin();
        itr != myPostIdList.end(); ++itr)
    {
		//show info about post on UI window
        ui->info_window->append(*itr);

        char* cUrlLike = createCUrlLink(
                    cUrlFromMozilla,
                    "c_user=",
                    "; xs=",
                    "client_id=",
                    itr,
                    true,
                    "fb_dtsg="
                    );

        //hide console window during "system" command work
		HWND Hide;
        AllocConsole();
        Hide = FindWindowA("ConsoleWindowClass", NULL);
        ShowWindow(Hide,0);

		//make curl POST request to Facebook from system console
        system(cUrlLike);

		//show confirmation if all likes OK
        ui->info_window->append("like OK");

		//show quantity 
        ui->lcd_count_liked->display(++count);

        delete cUrlLike;
    }

}


//the same that previous method but dislike
void LikeWindow::on_DislikeButton_clicked()
{

    ui->info_window->append("\ndislike\n");

    int count = 0;

    const QString cUrlFromMozilla = ui->qText_cUrlFromMozilla->toPlainText();


    for(QStringList::iterator itr = myPostIdList.begin();
        itr != myPostIdList.end(); ++itr)
    {

        ui->info_window->append(*itr);

        char* cUrlLike = createCUrlLink(
                    cUrlFromMozilla,
                    "c_user=",
                    "; xs=",
                    "client_id=",
                    itr,
                    false,
                    "fb_dtsg="
                    );
        HWND Hide;
        AllocConsole();
        Hide = FindWindowA("ConsoleWindowClass", NULL);
        ShowWindow(Hide,0);

        system(cUrlLike);

        ui->info_window->append("Dislike OK");

        ui->lcd_count_liked->display(++count);

        delete cUrlLike;
    }

}
