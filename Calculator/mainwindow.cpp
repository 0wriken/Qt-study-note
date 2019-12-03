#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushBtn1_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"1");
}

void MainWindow::on_pushBtn2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"2");
}

void MainWindow::on_pushBtn3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"3");
}
void MainWindow::on_pushBtn4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"4");
}
void MainWindow::on_pushBtn5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"5");
}
void MainWindow::on_pushBtn6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"6");
}
void MainWindow::on_pushBtn7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"7");
}
void MainWindow::on_pushBtn8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"8");
}
void MainWindow::on_pushBtn9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"9");
}
void MainWindow::on_pushBtn0_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"0");
}

void MainWindow::on_pushBtn_point_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+".");
}

void MainWindow::on_pushBtn_clear_clicked()
{
    ui->lineEdit->clear();
}


void MainWindow::on_pushBtn_delect_clicked()
{
    QString str =ui->lineEdit->text();
    int value =str.toInt();
    value = value/10;
    if(value ==0)
    {
        ui->lineEdit->clear();
    }
    else
    {
        ui->lineEdit->setText(QString("%1").arg(value));
    }

}

void MainWindow::on_pushBtn_add_clicked()
{
    QString str=ui->lineEdit->text();
    this->value1=str.toInt();
    qDebug()<<this->value1;
    ui->lineEdit->setText(ui->lineEdit->text()+"+");
}

void MainWindow::on_pushBtn_sub_clicked()
{
    QString str=ui->lineEdit->text();
    this->value1=str.toInt();
    qDebug()<<this->value1;
    //ui->lineEdit->setText(ui->lineEdit->text()+"+");
    ui->lineEdit->setText(ui->lineEdit->text()+"-");
}

void MainWindow::on_pushBtn_Div_clicked()
{
    QString str=ui->lineEdit->text();
    this->value1=str.toInt();
    qDebug()<<this->value1;
    ui->lineEdit->setText(ui->lineEdit->text()+"/");
}

void MainWindow::on_pushBtn_Mul_clicked()
{
    QString str=ui->lineEdit->text();
    this->value1=str.toInt();
    qDebug()<<this->value1;
    ui->lineEdit->setText(ui->lineEdit->text()+"*");
}

void MainWindow::on_pushBtn_sure_clicked()
{
    QString str =ui->lineEdit->text();
    QByteArray ba = str.toLatin1(); // must
   // qDebug()<<str;
    char*  ch =new char(100);
    ch=ba.data();

    while(ch!=NULL)
    {
        if(*ch=='+')
        {
            this->flag='+';
            ch++;
            QString str1 = QString(QLatin1String(ch));//char *转换为QString
            qDebug()<<str1;
            this->value2=str1.toInt();//接受被加数
            qDebug()<<this->value2;
            int sum=this->value1+this->value2;
            ui->lineEdit->setText(QString("%1").arg(sum));
            break;

        }
        if(*ch=='-')
        {
            this->flag='-';
            ch++;
            QString str1 = QString(QLatin1String(ch));//char *转换为QString
            qDebug()<<str1;
            this->value2=str1.toInt();//接受被加数
            qDebug()<<this->value2;
            int sum=this->value1-this->value2;
            ui->lineEdit->setText(QString("%1").arg(sum));
            break;

        }
        if(*ch=='*')
        {
            this->flag='*';
            ch++;
            QString str1 = QString(QLatin1String(ch));//char *转换为QString
            qDebug()<<str1;
            this->value2=str1.toInt();//接受被加数
            qDebug()<<this->value2;
            uint32_t sum=(this->value1)*(this->value2);
            ui->lineEdit->setText(QString("%1").arg(sum));
            break;

        }
        if(*ch=='/')
        {
            this->flag='/';
            ch++;
            QString str1 = QString(QLatin1String(ch));//char *转换为QString
            qDebug()<<str1;
            this->value2=str1.toInt();//接受被加数
            qDebug()<<this->value2;
            float sum=(this->value1)/(this->value2);
            ui->lineEdit->setText(QString("%1").arg(sum));
            break;
        }
        ch++;
    }
    ch++;

}
