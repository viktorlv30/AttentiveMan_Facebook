#include "mainwindow.h"
#include <QApplication>
//#include <iostream>
//#include <stdio.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    std::cout << "Hello world" << "\n";

    return a.exec();
}
