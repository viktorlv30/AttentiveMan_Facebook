#-------------------------------------------------
#
# Project created by QtCreator 2016-05-10T11:15:23
#
#-------------------------------------------------

#involve core for qApp
#involve gui interfase for ui
#involve posibility to work in network
#involve posibility to work with widgets in ui

QT       += core gui network webkit

#include widgets of QT-4 if your version Qt is higher
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app_exmpl_onWork_1
TEMPLATE = app

#description sourse files in projecct
SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp

#description users headers
HEADERS  += mainwindow.h \
    dialog.h

#description users ui interfase
FORMS    += mainwindow.ui \
    dialog.ui
