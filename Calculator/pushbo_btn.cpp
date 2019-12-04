#include "pushbo_btn.h"
#include "ui_pushbo_btn.h"

PushBo_Btn::PushBo_Btn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PushBo_Btn)
{
    ui->setupUi(this);
    QMenu *menu=new QMenu(this);
    menu->addAction("打开");
    menu->addAction("设置");
    menu->addAction("游戏");
    menu->addSeparator();
    menu->addAction("退出");
    ui->menu_pushButton->setMenu(menu);
}

PushBo_Btn::~PushBo_Btn()
{
    delete ui;
}

void PushBo_Btn::on_q_pushButton_clicked()
{
      reject();
}
