#ifndef LIKEWINDOW_H
#define LIKEWINDOW_H

#include <QWidget>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPlainTextEdit>

namespace Ui {
class LikeWindow;
}

class LikeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LikeWindow(QWidget *parent = 0);
    ~LikeWindow();

    //complete cUrl format link from example which we get from Firebug
    char* createCUrlLink(
            const QString ,
            const char* ,
            const char* ,
            const char* ,
            QStringList::iterator ,
            bool isLike,
            const char*
            );


private slots:
	//processing errors
    void requestError( QNetworkReply::NetworkError error);

	//data processing from Facebook page after GET request to Facebook
    void requestFinished();

	//slot for insert access_token
    void on_lineEdit_token_returnPressed();

	//slot for button which send GET request to Facebook to get information about all your posts
    void on_RequestButton_clicked();

    //slot for button which send POST request to Facebook to placing likes in all your posts
	void on_LikeButton_clicked();

	//slot for button which send POST request to Facebook to remove likes in all your posts
    void on_DislikeButton_clicked();

private:
    
	//class for new window which placing likes
	Ui::LikeWindow *ui;

	//private variables to work in program
    QUrl url;

    QNetworkAccessManager *mpQNman;

    QStringList strPosts_id;

    QStringList nextPagePosts;

    QNetworkRequest  mNetRequest;

    QNetworkReply   *mpNetReplay;

    QStringList propertyNames;
    QStringList propertyValues;
    QStringList myPostIdList;

	//private methods fo data processing - parse the example of cUrl request
	
    char* qStrIteratorToConstChar(QStringList::iterator itr);

    char* takeInfoFromCUrlCommand(const QString source, const char* marker);

    char* takeClientId(const QString source, const char* marker);

    char* takeDTGScodeFromCUrlCommand(const QString source, const char* marker);

    const char* takeIsLike(bool);

};

#endif // LIKEWINDOW_H
