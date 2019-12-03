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
    if(ui->lineEdit->text()==QString("123456789")&&ui->comboBox->currentText()==QString("2467756298"))
    {
        accept();
    }
}
