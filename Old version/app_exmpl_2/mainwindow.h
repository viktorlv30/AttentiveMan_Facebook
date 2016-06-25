#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPlainTextEdit>

#include "dialog.h"

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

    void requestError( QNetworkReply::NetworkError error);
    void requestFinished();

    void on_lineToken_returnPressed();

    void on_getRequest_clicked();

    void on_like_clicked();

    void on_dislike_clicked();

    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
    QUrl url;
    QNetworkAccessManager *mpQNman;
    QStringList strPosts_id;
    QStringList nextPagePosts;

    QNetworkRequest  mNetRequest;
    QNetworkReply   *mpNetReplay;

    QStringList propertyNames;
    QStringList propertyValues;

    Dialog mDialog;
};

#endif // MAINWINDOW_H
