#include "pic_show.h"
#include "ui_pic_show.h"

pic_show::pic_show(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pic_show)
{
    ui->setupUi(this);
    ui->pre_picBtn->setEnabled(0);
    ui->next_picBtn->setEnabled(0);
    ui->delete_Btn->setEnabled(0);
    ui->add_Btn->setEnabled(0);
}

pic_show::~pic_show()
{
    delete ui;
}

void pic_show::on_file_Btn_clicked()
{
    this->index=0;
    Filename=QFileDialog::getOpenFileNames(this,"本地文件","/home/wriken/图片",
                                                       "所有文件( *);;图片文件(* jpg * png)");
    if(Filename.count()==0)
    {
        QMessageBox::information(this,"错误提示","未检测到图片文件");
        return ;
    }
    ui->delete_Btn->setEnabled(1);
    ui->add_Btn->setEnabled(1);
    show();
    update();

}
void pic_show::show()
{

    ui->pic_label->setPixmap(QPixmap(Filename[index]));
    qDebug()<<index;
    ui->pic_label->setScaledContents(1);

}
void pic_show::update()
{
    if(index==0)
    {
        ui->pre_picBtn->setEnabled(0);
        qDebug()<<"看到上一张按键失效";
        ui->next_picBtn->setEnabled(1);
        ui->delete_Btn->setEnabled(0);
    }
    if(index==Filename.count()-1)
    {
        ui->pre_picBtn->setEnabled(1);
        ui->next_picBtn->setEnabled(0);
        ui->delete_Btn->setEnabled(1);
    }
    else
    {
        ui->pre_picBtn->setEnabled(1);
        ui->next_picBtn->setEnabled(1);
        ui->delete_Btn->setEnabled(1);
    }
}

void pic_show::on_quit_Btn_clicked()
{
    reject();
}

void pic_show::on_pre_picBtn_clicked()
{
   if(this->index==0)
    {
       QMessageBox::information(this,"错误提示","上个屁啊,都他妈第一张还上！！");
        return ;
    }
    else
        this->index--;
    show();
        update();
}
bool pic_show::is_reset(QString & map)
{
    for(int i=0;i<Filename.count()-1;i++)
    {
        if(this->Filename[i]==map)
            return 1;
    }
    return 0;
}
void pic_show::on_next_picBtn_clicked()
{
    if(this->index==this->Filename.count()-1)
    {
        QMessageBox ::information(this,"错误提示","下个皮啊，都他妈最后一张还下？");
        return ;
    }
    else
        this->index++;
    show();
    update();

}

void pic_show::on_add_Btn_clicked()
{

    QStringList map1= QFileDialog::getOpenFileNames(this,"添加图片","/home/wriken/图片","所有文件(*);;图片( *jpg *png)");
    if(map1.count()==0)
    {
        QMessageBox::information(this,"错误提示","你丫的倒是快点添加文件啊");
        return ;
    }
    for(int i=0;i<map1.count()-1;i++)
    {
        if(!this->is_reset(map1[i]))//如果没有重复出现的情况下
        Filename.insert(Filename.count()-1+i,map1[i]);

    }
    update();
    show();
}

void pic_show::on_delete_Btn_clicked()
{
    if(index==0)
    {
         Filename.removeAt(index);
         ui->pre_picBtn->setEnabled(0);
         ui->next_picBtn->setEnabled(0);
         ui->delete_Btn->setEnabled(0);
         ui->pic_label->clear();
    }
    else {
        Filename.removeAt(index);
        index--;
        show();
        update();
    }


}
