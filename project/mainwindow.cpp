#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_portBtn_clicked()
{
    PortDialog a;
    a.move(300,100);
    if(a.exec()==QDialog::Rejected)
    {
        qDebug()<<"关闭串口窗口";
        return ;
    }
    else
    {
        qDebug()<<"串口信息更改";
        return ;
    }
}

void MainWindow::on_musicBTN_clicked()
{
    MusicDialog b;
    if(b.exec()==QDialog::Rejected)
    {
        qDebug()<<"退出音乐播放器";
        return;
    }


}
