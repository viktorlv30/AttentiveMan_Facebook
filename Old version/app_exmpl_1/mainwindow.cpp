#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QMap>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mpQNman = new QNetworkAccessManager(this);
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

void MainWindow::on_GetRequest_clicked()
{
    QString access_token = ui->lineToken->text();
    /*
     * temporary access_token = EAACEdEose0cBABlnSmFaByKjU9JaniCNUHzDaaJOKioy07xYgDvs7kovZBjlC2Wqj2kfjIZBNzN1loIh4PMcPh9mPLLynZAnl5w51Jqc7LZAyh9WIMF8UcIEjKCZBY7uQbSqU3fN9m1c0sFeGzTnLnKhVqxh8DERBgIWhRqf4ZBwZDZD
     * limit temporary insert "2"
     */

//    access_token = "EAACEdEose0cBADTSALlUP4vI33y69RGoVFkbdzuNsx9no7tzuvf7AHZAPjrtZBWx5z5nhUOmb5B9WUFG1aWmDEZCh3FZCjJUiTe6MDwmv3igUlr17934oDMTMOx0EpndqnzkIU09YTMolomudPopWtq963FmeU8MstSuZBywccQZDZD";

    QString base_http_url = "https://graph.facebook.com/1707734546174172/feed?access_token=";
    QString limit_json ="&limit=2";
    QString full_url = base_http_url + access_token + limit_json;


    QNetworkRequest request;
    request.setUrl(QUrl(full_url));

    QNetworkReply *replay;
    replay = mpQNman->get(request);
    connect(replay, SIGNAL(finished()), this, SLOT(requestFinished()));
    connect(replay, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(requestError(QNetworkReply::NetworkError)));

    ui->outJson->appendPlainText("Request send!\n");
}

void MainWindow::requestError( QNetworkReply::NetworkError error)
{
    int debug;
    debug = 0;
}

void MainWindow::requestFinished()
{
    QJsonParseError error;

    QNetworkReply *replay = qobject_cast<QNetworkReply*>(sender());
    QByteArray byteArr = replay->readAll();

    QJsonDocument doc = QJsonDocument::fromJson(byteArr, &error);

    QVariantMap qmap;

    if(doc.isObject())
    {
        QJsonObject obj = doc.object();
        QStringList qsList;
        QMap <QString, QVariant> qm1;

        qmap = obj.toVariantMap();
        qsList = obj.keys();
        qm1 = qmap["paging"].toMap();
        ui->outJson->appendPlainText(qm1.firstKey());
        ui->outJson->appendPlainText(" : ");
        ui->outJson->appendPlainText(qm1.value(qm1.firstKey()).toString());

        QJsonObject::iterator itr = obj.find("id");
        if(itr != obj.end())
        {
            ui->outJson->appendPlainText(itr.key());
            ui->outJson->appendPlainText(itr.value().toString());


           
        }


    }

    replay->deleteLater();
}

void MainWindow::on_makelike_clicked()
{
    ui->outJson->appendPlainText("makes Like");
    system("curl \"https://www.facebook.com/ufi/reaction/?dpr=1\" -H \"Cookie: c_user=100008129298080; xs=146%3AL7fWxXhulnhyBQ%3A2%3A1462287274%3A15808\" --data \"client_id=1462704710897&ft_ent_identifier=1718155975132029&reaction_type=1&fb_dtsg=AQEiit0i9HQS%3AAQGHD3uXVGZw\"");

}

void MainWindow::on_dislike_clicked()
{
    ui->outJson->appendPlainText("dislike");
    system("curl \"https://www.facebook.com/ufi/reaction/?dpr=1\" -H \"Cookie: c_user=100008129298080; xs=146%3AL7fWxXhulnhyBQ%3A2%3A1462287274%3A15808\" --data \"client_id=1462704779718&ft_ent_identifier=1718155975132029&reaction_type=0&fb_dtsg=AQFCUF_eZkT3%3AAQEhUDtNKPEw\"");
}
