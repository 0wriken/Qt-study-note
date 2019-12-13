#include "signdialog.h"
#include "ui_signdialog.h"

signDialog::signDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signDialog)
{
    ui->setupUi(this);
}

signDialog::~signDialog()
{
    delete ui;
}

void signDialog::on_sign_inBtn_clicked()
{
    if(ui->pass_lineEdit->text()=="1")
    {
        accept();
    }
    else
    {
        QMessageBox::information(this,"error","密码错误");
        return;
    }
}
