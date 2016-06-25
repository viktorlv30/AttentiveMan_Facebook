#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


QString Dialog::getMyLineEdit()
{
    return ui->lineEdit->text();
}

void Dialog::setValueStr(QString aValue)
{
    ui->lineEdit->setText(aValue);
}


