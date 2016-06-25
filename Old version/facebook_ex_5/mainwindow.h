#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>


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
    void on_btnGet_clicked();

    void requestFinished();
    void requestError(QNetworkReply::NetworkError error);

private:
    Ui::MainWindow *ui;

    QUrl url;
    //QNetworkReply *reply;
    QNetworkAccessManager *mpQNman;
};

#endif // MAINWINDOW_H
