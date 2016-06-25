#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVariantMap>
#include <QMap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mpQNman = new QNetworkAccessManager(this);
    nextPagePosts.append("-");
}

MainWindow::~MainWindow()
{
    delete mpQNman;
    delete ui;
}


void MainWindow::on_lineToken_returnPressed()
{
    QString access_token = ui->lineToken->text();
//    ui->GetRequest->setText(access_token); //change name of button
}

void MainWindow::on_getRequest_clicked()
{

    if(nextPagePosts.last() == "-")
    {
        QString access_token = ui->lineToken->text();
        QString user_id = ui->apiID->text();

     /*
     * temporary access_token = EAACEdEose0cBAKrc5tITNZAEhUc6JVki9pEHWTueEjE1iOO3XBrZBlwgXRPdZBvcZBCrQr1pfH9BmMsSGxLlbng1ujpnU2gCVZCwlEEunc2i0ePymZBxX7ScwwgZBlZABgZB6lPrN8fNZBO8bsP3ZCAIPoFlMKmaEH8FmPEfezNRBPAswZDZD
     * limit temporary insert "2"
     */

        //apolon
        //    user_id = "120666655013303";
        //    access_token = "EAACEdEose0cBAExcb32rK9VdBmLSPAIdIZBZAmZAhoZCEI6w3nGuONin7zhZCvfjkUlUnUxf8ZBlMiStrchpWFTD1uKWYF0vPSUAYQ2fZBWXYwUoH517h3iz2fvm6hx1ZAVTTgRBXGySbPG16MXkBI2uGdK5K1oQoEENavrQuOfG91ZCKxYBKdkvB";

        //litvak

        user_id = "1707734546174172";
        access_token = "EAACEdEose0cBALUHOB1ydxzbPZAKv4H6EFuocEKjmfV48dwior0LjEvWmZBU5F8LiZAX5WyuMwUhO9ZB7uH3uQgzZA4QCeu17siq5XtQ5AK7okZBlj7vrwFsWkUA8iBbHrvCZBZBfbTTz8Cv4MgzCYy9WvCmcMVzWB4ZBGTPbZC0bAnQZDZD";

        QString base_http_url = "https://graph.facebook.com/v2.0/";
        QString what_request = "/feed?access_token=";
        QString limit_json ="&limit=25";
        nextPagePosts.append( base_http_url + user_id + what_request + access_token + limit_json );
    }


    url = QUrl(nextPagePosts.last());

    mNetRequest.setUrl(url);

    mpNetReplay = mpQNman->get(mNetRequest);

    connect(mpNetReplay, SIGNAL(finished()), this, SLOT(requestFinished()));

    //if(nextPagePosts.last() != NULL)
    //    connect(mpNetReplay, SIGNAL(finished()), this, SLOT(requestFinished()));

    connect(mpNetReplay, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(requestError(QNetworkReply::NetworkError)));

    ui->outJson->appendPlainText("Request send!\n");


}

void MainWindow::requestError( QNetworkReply::NetworkError error )
{
    int debug;
    debug = 0;
}

void MainWindow::requestFinished()
{
    //from http://stackoverflow.com/questions/19822211/qt-parsing-json-using-qjsondocument-qjsonobject-qjsonarray

    QStringList propertyNames;
    QStringList propertyValues;
    QNetworkReply *replay = qobject_cast<QNetworkReply*>(sender());

    QString strReplay = (QString)replay->readAll();
//    ui->outJson->appendPlainText(strReplay);
    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReplay.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QJsonArray jsonArray = jsonObject["data"].toArray();

    foreach (const QJsonValue &value, jsonArray)
    {
        QJsonObject obj = value.toObject();
        if(obj["story"].toString() != NULL)
            propertyNames.append(obj["story"].toString());
        else if(obj["name"].toString() != NULL)
            propertyNames.append(obj["name"].toString());
        else
            propertyNames.append(obj["message"].toString());

        propertyValues.append(obj["id"].toString());

        ui->outJson->appendPlainText(propertyNames.last());
        ui->outJson->appendPlainText(propertyValues.last());

    }


    QVariantMap qmap;
    if(jsonResponse.isObject())
    {

        QStringList qsList;
        QMap <QString, QVariant> qm1;

        qmap = jsonObject.toVariantMap();
        qsList = jsonObject.keys();
        qm1 = qmap["paging"].toMap();

        //ui->outJson->appendPlainText("next");
        //ui->outJson->appendPlainText(" : ");
        //ui->outJson->appendPlainText(qm1.value("next").toString());

        if( qm1.value("next").toString() != NULL )
        {
            nextPagePosts.append(qm1.value("next").toString());

            mNetRequest.setUrl(qm1.value("next").toString());
            mpNetReplay = mpQNman->get(mNetRequest);
            connect(mpNetReplay, SIGNAL(finished()), this, SLOT(requestFinished()));
        }
    }

    strPosts_id += propertyValues;
    replay->deleteLater();

}


void MainWindow::on_like_clicked()
{
    ui->outJson->appendPlainText("makes Like");


//    system("curl \"https://www.facebook.com/ufi/reaction/?dpr=1\" -H \"Cookie: c_user=100008129298080; xs=146%3AL7fWxXhulnhyBQ%3A2%3A1462287274%3A15808\" --data \"client_id=1462982417216&ft_ent_identifier=1718884045059222&reaction_type=1&fb_dtsg=AQGlogJogJ6k%3AAQH12pD8vKWl\"");
    system("curl \"https://www.facebook.com/ufi/reaction/?dpr=1\" -H \"Cookie: c_user=100008129298080; xs=146%3AL7fWxXhulnhyBQ%3A2%3A1462287274%3A15808\" --data \"client_id=1462982417216&ft_ent_identifier=1719466898334270&reaction_type=1&fb_dtsg=AQGlogJogJ6k%3AAQH12pD8vKWl\"");

    //apolon
//    system("curl \"https://www.facebook.com/ufi/reaction/?dpr=1\" -H \"Cookie: c_user=100012099074969; xs=179%3APjuTW_y-zoBg0Q%3A2%3A1462956467%3A-1\" --data \"client_id=1462955354362&ft_ent_identifier=120541551692480&reaction_type=1&fb_dtsg=AQEDuuBVlTt_%3AAQHeuQXwuN6W\"");

}


void MainWindow::on_dislike_clicked()
{
    ui->outJson->appendPlainText("dislike");

//    system("curl \"https://www.facebook.com/ufi/reaction/?dpr=1\" -H \"Cookie: c_user=100008129298080; xs=146%3AL7fWxXhulnhyBQ%3A2%3A1462287274%3A15808\" --data \"client_id=1462982417216&ft_ent_identifier=1718884045059222&reaction_type=0&fb_dtsg=AQGlogJogJ6k%3AAQH12pD8vKWl\"");
    system("curl \"https://www.facebook.com/ufi/reaction/?dpr=1\" -H \"Cookie: c_user=100008129298080; xs=146%3AL7fWxXhulnhyBQ%3A2%3A1462287274%3A15808\" --data \"client_id=1462982417216&ft_ent_identifier=1719466898334270&reaction_type=0&fb_dtsg=AQGlogJogJ6k%3AAQH12pD8vKWl\"");

    //apolon
//    system("curl \"https://www.facebook.com/ufi/reaction/?dpr=1\" -H \"Cookie: c_user=100012099074969; xs=179%3APjuTW_y-zoBg0Q%3A2%3A1462956467%3A-1\" --data \"client_id=1462955354362&ft_ent_identifier=120541551692480&reaction_type=0&fb_dtsg=AQEDuuBVlTt_%3AAQHeuQXwuN6W\"");

}
