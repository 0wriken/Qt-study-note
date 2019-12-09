#include "webdialog.h"
#include "ui_webdialog.h"

webDialog::webDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::webDialog)
{
    ui->setupUi(this);
    QDesktopServices::openUrl(QUrl("http://www.baidu.com"));
}

webDialog::~webDialog()
{
    delete ui;
}
