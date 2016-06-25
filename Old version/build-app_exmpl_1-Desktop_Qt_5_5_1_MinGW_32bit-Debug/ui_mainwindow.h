/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionClose;
    QAction *actionQuit;
    QWidget *centralWidget;
    QPlainTextEdit *outJson;
    QPushButton *GetRequest;
    QPushButton *makelike;
    QLineEdit *lineToken;
    QLabel *label;
    QPushButton *dislike;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuViktor_Window;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        outJson = new QPlainTextEdit(centralWidget);
        outJson->setObjectName(QStringLiteral("outJson"));
        outJson->setGeometry(QRect(10, 60, 291, 181));
        GetRequest = new QPushButton(centralWidget);
        GetRequest->setObjectName(QStringLiteral("GetRequest"));
        GetRequest->setGeometry(QRect(320, 20, 75, 20));
        makelike = new QPushButton(centralWidget);
        makelike->setObjectName(QStringLiteral("makelike"));
        makelike->setGeometry(QRect(320, 60, 71, 23));
        makelike->setCursor(QCursor(Qt::PointingHandCursor));
        lineToken = new QLineEdit(centralWidget);
        lineToken->setObjectName(QStringLiteral("lineToken"));
        lineToken->setGeometry(QRect(10, 20, 291, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 181, 16));
        dislike = new QPushButton(centralWidget);
        dislike->setObjectName(QStringLiteral("dislike"));
        dislike->setGeometry(QRect(320, 100, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuViktor_Window = new QMenu(menuBar);
        menuViktor_Window->setObjectName(QStringLiteral("menuViktor_Window"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuViktor_Window->menuAction());
        menuViktor_Window->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as...", 0));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        GetRequest->setText(QApplication::translate("MainWindow", "GET request", 0));
        makelike->setText(QApplication::translate("MainWindow", "make like", 0));
        label->setText(QApplication::translate("MainWindow", "Insert access token from facebook", 0));
        dislike->setText(QApplication::translate("MainWindow", "dislike", 0));
        menuViktor_Window->setTitle(QApplication::translate("MainWindow", "Facebook request", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
