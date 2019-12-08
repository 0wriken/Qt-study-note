#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer= new  QTimer(this);
    connect(timer ,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showTime()
{
    QTime time = QTime ::currentTime();
    QString txtTime =time.toString("hh:mm:ss");
    ui->lcdNumber->display(txtTime);
}
