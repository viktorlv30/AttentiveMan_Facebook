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
    delete ui;
}

void MainWindow::on_btnGet_clicked()
{
    /*
    QEventLoop loop;
    connect(mpQNman, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    QNetworkReply * reply = mpQNman->post(request, jsonString);
    loop.exec();
    QByteArray response = reply->readAll();
    QString stringData(response);
    ui->plainTextEdit->appendPlainText(stringData);
    */

    // NO JSON
    QNetworkRequest request;
    request.setUrl(QUrl("https://www.google.com"));

    QNetworkReply *reply = mpQNman->get(request);
    connect(reply, SIGNAL(finished()), this, SLOT(requestFinished()));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(requestError(QNetworkReply::NetworkError)));
    ui->plainTextEdit->appendPlainText("Request send!");
}

void MainWindow::requestFinished()
{
    QJsonParseError err;

    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    QByteArray bytes = reply->readAll();

    QJsonDocument doc = QJsonDocument::fromJson(bytes, &err);

    QVariantMap qmap;

    if(doc.isObject())
    {
        QJsonObject obj = doc.object();
        QStringList qslist;
        QMap<QString, QVariant> qm1;

        qmap = obj.toVariantMap();
        qslist = obj.keys();
        qm1 = qmap["data"].toMap();
        ui->plainTextEdit->appendPlainText(obj["full_name"].toString());

        QJsonObject::iterator itr = obj.find("full_name");
        if(itr != obj.end())
        {
            ui->plainTextEdit->appendPlainText(itr.key());
            ui->plainTextEdit->appendPlainText(itr.value().toString());


            //itr.
            // object not found.
        }

        // do something with the found object...
    }
    reply->deleteLater();
}

void MainWindow::requestError(QNetworkReply::NetworkError error)
{
    int debug;
    debug = 0;
}
