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
    QAction *actionQuit_Alt_F4;
    QAction *actionBolt;
    QWidget *centralWidget;
    QPushButton *getRequest;
    QPushButton *like;
    QPushButton *dislike;
    QLineEdit *lineToken;
    QPlainTextEdit *outJson;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *apiID;
    QLabel *label_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(560, 456);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionQuit_Alt_F4 = new QAction(MainWindow);
        actionQuit_Alt_F4->setObjectName(QStringLiteral("actionQuit_Alt_F4"));
        actionBolt = new QAction(MainWindow);
        actionBolt->setObjectName(QStringLiteral("actionBolt"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        getRequest = new QPushButton(centralWidget);
        getRequest->setObjectName(QStringLiteral("getRequest"));
        getRequest->setGeometry(QRect(460, 20, 75, 23));
        like = new QPushButton(centralWidget);
        like->setObjectName(QStringLiteral("like"));
        like->setGeometry(QRect(460, 70, 75, 23));
        dislike = new QPushButton(centralWidget);
        dislike->setObjectName(QStringLiteral("dislike"));
        dislike->setGeometry(QRect(460, 110, 75, 23));
        lineToken = new QLineEdit(centralWidget);
        lineToken->setObjectName(QStringLiteral("lineToken"));
        lineToken->setGeometry(QRect(20, 20, 121, 21));
        outJson = new QPlainTextEdit(centralWidget);
        outJson->setObjectName(QStringLiteral("outJson"));
        outJson->setGeometry(QRect(20, 70, 421, 331));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 0, 71, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 50, 101, 16));
        apiID = new QLineEdit(centralWidget);
        apiID->setObjectName(QStringLiteral("apiID"));
        apiID->setGeometry(QRect(150, 20, 131, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(150, 0, 91, 16));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 560, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit_Alt_F4);

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
        actionQuit_Alt_F4->setText(QApplication::translate("MainWindow", "Quit (Alt+F4)", 0));
        actionBolt->setText(QApplication::translate("MainWindow", "Bolt", 0));
        getRequest->setText(QApplication::translate("MainWindow", "Request", 0));
        like->setText(QApplication::translate("MainWindow", "like", 0));
        dislike->setText(QApplication::translate("MainWindow", "dislike", 0));
        label->setText(QApplication::translate("MainWindow", "Access token", 0));
        label_2->setText(QApplication::translate("MainWindow", "Info window", 0));
        label_3->setText(QApplication::translate("MainWindow", "API Graph user id", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
