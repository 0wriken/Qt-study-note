#include "file_widget.h"
#include "ui_file_widget.h"

File_widget::File_widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::File_widget)
{
    ui->setupUi(this);
}

File_widget::~File_widget()
{
    delete ui;
}


void File_widget::update()
{
    QString str;
    if(!Has_file)
    {
        if(Change_file)
        {
            str="无标题.txt-记事本*";
            this->File_widget::setWindowTitle(str);
        }
        else
        {
            str="无标题.txt-记事本";
            this->File_widget::setWindowTitle(str);
        }
    }
    else
    {
        if(Change_file)
        {

            str=this->File_name+"-记事本"+"*";
            qDebug()<<str;
           // this->centralWidget()->
           File_widget::setWindowTitle(str);
        }
        else
        {
            str=this->File_name+"-记事本";
              qDebug()<<str;
            File_widget::setWindowTitle(str);
        }
    }
    this->Change_file=false;

}
void File_widget::on_action_S_triggered()
{

    QString map =QFileDialog::getOpenFileName(this,"本地文件","/home/wriken/QTtest/文件夹",
                                                   "所有文件(*);;文本文件(* txt)");
    if(map.isEmpty())
    {
        QMessageBox::information(this,"错误提示","打开文件路径错误");
        return ;
    }

    QFile name(map);
    if(!name.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this,"错误提示","打开文件失败");
        return ;
    }
    QString str;
    QTextStream stream(&name);
    ui->TextEdit->setPlainText(stream.readAll());
    QFileInfo info(name);
    qDebug()<<"open file succes";
    this->Has_file=1;
    this->Change_file=0;
    this->new_file=0;
    this->File_name=info.fileName();
    this->File_path=info.filePath();
    update();
}

void File_widget::on_TextEdit_textChanged()
{
    qDebug()<<"文本改变";
    this->Change_file=1;
    update();
}

void File_widget::on_action_A_triggered()
{
    QString str;
    QString map=QFileDialog::getSaveFileName(this,"另存为路径","/home/wriken/QTtest/文件夹",
                                             "所有文件 (*);;文本文件(* txt)");
    if(map.isEmpty())
    {
        QMessageBox::information(this,"error","the file is empty");
        return ;
    }
    QFile name(map);
    if(!name.open(QIODevice::ReadWrite |QIODevice::Text))
    {
        QMessageBox::information(this,"error","the file open fail");
        return ;
    }
    QTextStream out(&name);
    str=ui->TextEdit->toPlainText();
    out<<str;
    QFileInfo mes(name);
    this->File_name=mes.fileName();
    this->File_path=mes.filePath();
    this->Has_file=1;
    qDebug()<<"文本流";


}
void File_widget::on_action_S_2_triggered()
{
    if(this->new_file)
    {
           QMessageBox::information(this,"提示",
                                    "当前为文件，请选择保存路径");

        on_action_A_triggered();

        update();

       this->new_file=0;
        return ;
    }
    QFile name(this->File_path);
    if(!name.open(QIODevice ::ReadWrite))
    {
        QMessageBox::information(this,"error","the file open fail");
        return ;
    }
    QTextStream save(&name);
    save<<ui->TextEdit->toPlainText();
    this->Change_file=0;
    update();
    qDebug()<<"保存成功";
}




void File_widget::on_action_N_triggered()
{
    File_widget *file= new File_widget;
    file->show();
}

void File_widget::on_action_Q_triggered()
{
    this->close();
}

void File_widget::on_action_F_2_triggered()
{
    QFontDialog *log=new  QFontDialog;
    log->show();

}
