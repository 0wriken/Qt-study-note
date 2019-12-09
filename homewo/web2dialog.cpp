#include "web2dialog.h"
#include "ui_web2dialog.h"

web2Dialog::web2Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::web2Dialog)
{
    ui->setupUi(this);
    ui->setupUi(this);
    QDesktopServices::openUrl(QUrl("http://www.openedv.com"));
}

web2Dialog::~web2Dialog()
{
    delete ui;
}
