//include main class of app
#include "mainwindow.h"
//main lib for ui app
#include <QApplication>

int main(int argc, char *argv[])
{
    //initialize main arguments of app
    QApplication a(argc, argv);
    //initialization main class ui
    MainWindow w;
    //show ui and all operations on ui window
    w.show();

    return a.exec();
}
