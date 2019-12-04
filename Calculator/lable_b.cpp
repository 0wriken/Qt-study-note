#include "lable_b.h"
#include "ui_lable_b.h"

lable_B::lable_B(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lable_B)
{
    ui->setupUi(this);
    QPixmap map("/home/wriken/Pictures/图片/tree.jpg");
    ui->pic_label->setPixmap(map);
    //ui->pic_label->resize(map.width(),map.height());//label符合pic
    ui->pic_label->setScaledContents(1);
    qDebug()<<"图片加载完成";
    QMovie *m=new QMovie("/home/wriken/GIF/car.gif");
    ui->gif_label->setMovie(m);
    ui->gif_label->setScaledContents(1);
    m->start();
    qDebug()<<"动图加载完成";
    qDebug()<<m->speed();

}

lable_B::~lable_B()
{
    delete ui;
}

void lable_B::on_statr_push_clicked()
{
    ui->gif_label->movie()->start();
}

void lable_B::on_stop_pushBtn_clicked()
{
    ui->gif_label->movie()->stop();
}

void lable_B::on_quit_pushBtn_clicked()
{
    reject();
}

void lable_B::on_verticalSlider_valueChanged(int value)
{
    ui->gif_label->movie()->setSpeed(value);
}
