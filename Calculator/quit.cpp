#include "quit.h"
#include "ui_quit.h"

quit::quit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::quit)
{
    ui->setupUi(this);
}

quit::~quit()
{
    delete ui;
}

void quit::on_pushButton_2_clicked()
{
    accept();
}



void quit::on_quit_puBtn_clicked()
{
    qDebug()<<"quit_pushobont";
    reject();
}
