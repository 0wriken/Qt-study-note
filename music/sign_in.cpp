#include "sign_in.h"
#include "ui_sign_in.h"

sign_in::sign_in(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign_in)
{
    ui->setupUi(this);
}

sign_in::~sign_in()
{
    delete ui;
}

void sign_in::on_sign_inBtn_clicked()
{
    if(ui->Account->text()==QString("1")&&ui->pass_lineEdit->text()==QString("1"))
    {
        accept();
    }
    else
    {
        QMessageBox::information(this,"错误提示","密码错误，请检查账号与密码是否正确!");
        return ;
    }
}

void sign_in::on_quit_Btn_clicked()
{
    this->close();
}
