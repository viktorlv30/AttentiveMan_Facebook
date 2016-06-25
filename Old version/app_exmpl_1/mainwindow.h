#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QNetworkAccessManager>
#include <QNetworkReply>
//#include <qnetworkreply.h>
//#include <QUrl>
#include <QPlainTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_lineToken_returnPressed();

    void on_GetRequest_clicked();

    void requestError( QNetworkReply::NetworkError error);
    void requestFinished();

    void on_makelike_clicked();

    void on_dislike_clicked();

private:
    Ui::MainWindow *ui;
    QUrl url;
    QNetworkAccessManager *mpQNman;

};

#endif // MAINWINDOW_H
