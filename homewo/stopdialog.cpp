#include "stopdialog.h"
#include "ui_stopdialog.h"

stopDialog::stopDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stopDialog)
{
    ui->setupUi(this);
}

stopDialog::~stopDialog()
{
    delete ui;
}

void stopDialog::on_sureBtn_clicked()
{
    accept();
}

void stopDialog::on_clenBtn_clicked()
{
    reject();
}
