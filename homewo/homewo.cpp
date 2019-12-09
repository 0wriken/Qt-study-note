#include "homewo.h"
#include "ui_homewo.h"

homewo::homewo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::homewo)
{
    ui->setupUi(this);
    QTimer *timer= new  QTimer(this);
    connect(timer ,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);
    setWindowTitle("XCOM   V2.0");
    //setWindowIcon(QIcon("/home/wriken/QTtest/图片/1.jpg"));

}

homewo::~homewo()
{
    delete ui;
}
void homewo::showTime()
{
    QTime time = QTime ::currentTime();
    QString txtTime =time.toString("hh:mm:ss");
    ui->lcdNumber_2->display(txtTime);
}

void homewo::on_pushButton_6_clicked()
{
    webDialog A;
    A.show();
}

void homewo::on_pushButton_50_clicked()
{
    web2Dialog A;
    A.show();
}
