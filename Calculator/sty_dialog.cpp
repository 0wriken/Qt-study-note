#include "sty_dialog.h"
#include "ui_sty_dialog.h"

sty_Dialog::sty_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sty_Dialog)
{
    ui->setupUi(this);
}

sty_Dialog::~sty_Dialog()
{
    delete ui;
}

void sty_Dialog::on_color_Btn_clicked()
{

    QColor color =QColorDialog::getColor(Qt::red,this,tr("颜色编辑框"));
    qDebug()<<color;
}

void sty_Dialog::on_file_Btn_clicked()
{
   QString  file=QFileDialog::getOpenFileName(this,tr("选择要打开的文件"),"/home/wriken",
                                            tr("文本(*txt *doc);;图片(*jpg *png);;程序代码(*c *cpp)"));

}

void sty_Dialog::on_quit_BTn_clicked()
{
    reject();
}
