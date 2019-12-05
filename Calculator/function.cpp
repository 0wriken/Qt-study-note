#include "function.h"
#include "ui_function.h"
#include "mainwindow.h"
#include "sty_dialog.h"
#include "lable_b.h"
#include "pushbo_btn.h"
#include "quit.h"
#include "pic_show.h"
function::function(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::function)
{
    ui->setupUi(this);
}

function::~function()
{
    delete ui;
}




void function::on_Dialog_Btn_clicked()
{

      sty_Dialog s(this);
    qDebug()<<"进入框架";
    if(s.exec()==sty_Dialog::Rejected)
    {
       s.close();
    }
}
void function::on_bb_pushButton_clicked()
{
    PushBo_Btn b(this);
    if(b.exec()==PushBo_Btn::Rejected)
    {
         b.close();
    }
}

void function::on_label_Btn_clicked()
{
    lable_B b(this);

    if(b.exec()==lable_B::Rejected)
    {
     b.close();

    }
}

void function::on_quit_Botton_clicked()
{
    quit d(this);
    qDebug()<<"get i";
    if(d.exec()==quit::Rejected)
    {
        qDebug()<<"get in quit";
        this->close();
    }
}

void function::on_coulum_Btn_clicked()
{
    accept();
}

void function::on_picshow_Btn_clicked()
{
    pic_show d(this);
    qDebug()<<"图片文件";
    if(d.exec()==pic_show::Rejected)
    {
        d.close();
    }
}
