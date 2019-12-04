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



void Dialog::on_sign_in_clicked()
{
    qDebug()<<"clicked";
    if(ui->lineEdit->text()==QString("1")&&ui->comboBox->currentText()==QString("1"))
    {
        accept();
    }


    else
    {
        if(ui->comboBox->currentText()!="1")
        {
            ui->message_label->setText("账号错误");
        }
        else if(ui->lineEdit->text()!="1")
        {
            ui->message_label->setText("密码有误");
        }
    }
}
