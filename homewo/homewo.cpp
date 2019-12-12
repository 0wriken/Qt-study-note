#include "homewo.h"
#include "ui_homewo.h"

homewo::homewo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::homewo)
{
    ui->setupUi(this);
    QTimer *timer= new  QTimer(this);
    connect(timer ,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);

    stime= new  QTimer(this);
    connect(ui->sendTimeCheckBox,SIGNAL(clicked(bool)),this,SLOT(sendTime(bool)));

    connect(stime ,SIGNAL(timeout()),this,SLOT(sendTimeData()));
    setWindowTitle("XCOM   V2.0");
    ltime= new  QTimer(this);
    connect(ltime ,SIGNAL(timeout()),this,SLOT(timeLoopSendCheckBox()));
    this->Xcom_init();
    //setWindowIcon(QIcon("/home/wriken/QTtest/图片/1.jpg"));
    connect(ui->portNameComboBox,SIGNAL(activated(int)),this,SLOT(flushPortName()));
    connect(ui->hexSendCheckBox,SIGNAL(clicked(bool)),this,SLOT(sendDataHex(bool)));
    //ltime->start(1000);
}

homewo::~homewo()
{
    delete ui;
}
/*************************************************************
函数名称：void show_time()
函数功能：显示时钟
函数参数：无
函数返回值：
函数说明：
************************************************************/
void homewo::showTime()
{
    QTime time = QTime ::currentTime();
    QString txtTime =time.toString("hh:mm:ss");
    ui->lcdNumber_2->display(txtTime);
}

/*************************************************************
函数名称：void on_openFilePushButton_clicked
函数功能：打开文件
函数参数：无
函数返回值：
函数说明：打开文件
************************************************************/
void homewo::on_openFilePushButton_clicked()
{

    if(!QString(ui->filePathLineEdit->text()).isEmpty())
    {
        QString filepath=QFileDialog::getOpenFileName(this,"本地文件",QString(ui->filePathLineEdit->text()),
                                                      "所有文件( *);;文本文件( *txt)");
        if(filepath.isEmpty())
        {
            QMessageBox::information(this,"错误提示","选择文件夹");
            return ;
        }

        QFile file(filepath);
        if(!file.open(QIODevice::ReadWrite))
        {
            QMessageBox::information(this,"错误提示","打开文件失败");
            return ;
        }

    }
    else
    {
        QString filepath=QFileDialog::getOpenFileName(this,"本地文件","/home/wriken/QTtest",
                                                      "所有文件( *);;文本文件( *txt)");
        if(filepath.isEmpty())
        {
            QMessageBox::information(this,"错误提示","选择文件夹");
            return ;
        }
        ui->filePathLineEdit->setText(filepath);
        QFile file(filepath);
        if(!file.open(QIODevice::ReadWrite))
        {
            QMessageBox::information(this,"错误提示","打开文件失败");
            return ;
        }


    }

}

void homewo::on_netCommandLinkButton_clicked()
{
    webDialog A;
    A.show();
}
/*************************************************************
函数名称：void
函数功能：显示网页
函数参数：无
函数返回值：
函数说明：
************************************************************/
void homewo::on_commandLinkButton_clicked()
{
    web2Dialog A;
    A.show();
}

/*************************************************************
函数名称：void
函数功能：发送数据槽函数
函数参数：无
函数返回值：
函数说明：按下发送按键
************************************************************/
void homewo::on_sendPushButton_clicked()
{
        if(myport->isOpen())
        {
        QString str=ui->sendBuflineEdit->text();
        if(ui->sendNewLineCheckBox->isChecked()==1)
        {
            str+="/r/n";
            //myport->write(str.toLocal8Bit());
            //ui->receiveBufTextBrowser->setPlainText(str);
            if(ui->orderHexSendCheckBox->isChecked())
                myport->write(str.toLocal8Bit().toHex());
            else
                myport->write(str.toLocal8Bit());
        }
        else
        {
            myport->write(str.toLocal8Bit());
        }

    }
    else
    {
        QMessageBox::information(this,"错误提示","请打开串口");
        return;
    }
}
/*************************************************************
函数名称：void
函数功能：清空槽函数
函数参数：无
函数返回值：
函数说明：清空内容
*********************************************************/
void homewo::on_cleanSendPushButton_clicked()
{
    ui->sendBuflineEdit->clear();
}

void homewo::on_cleanReceivePushButton_clicked()
{
     ui->receiveBufTextBrowser->clear();
}
/*************************************************************
函数名称：void Xcom_init()
函数功能：初始化
函数参数：无
函数返回值：
函数说明：初始化波特率，奇偶。。周期，图片，搜索可用串口号
************************************************************/
void homewo::Xcom_init()
{
    QStringList baudlist;
    baudlist<<"300"<<"200";
    ui->baudComboBox->addItems(baudlist);
    qDebug()<<"running";
    ui->baudComboBox->setMaxVisibleItems(6);
    ui->periodLineEdit->setText("1000");
    ui->orderPerio1LineEdit->setText("1000");
    //ui->picLabel->setPixmap(QPixmap(QString(":/resuorce/image/close/png")));

    //ui->openClosePushButton->
    ui->sendTimeCheckBox->setChecked(0);
    ui->openClosePushButton->setIcon(QIcon(QString(":/resuorce/image/close.png")));
    open_falg=0;
    flushPortName();
    myport=new QSerialPort;
    ui->backgroundCheckBox->setChecked(1);
}

/*************************************************************
函数名称：void on_openClosePushButton_clicked()
函数功能：搜索串口
函数参数：无
函数返回值：
函数说明：
************************************************************/
void homewo::on_openClosePushButton_clicked()
{


    if(QString(ui->portNameComboBox->currentText()).isEmpty())
    {
        QMessageBox::information(this,"错误提示","搜索串口失败");
        return ;
    }
    else
    {
    if(open_falg==0)
        {
            if(openPort())
            {
            ui->openClosePushButton->setIcon(QIcon(QString(":/resuorce/image/open.png")));
            ui->openClosePushButton->setText(QString("关闭串口"));
            open_falg=1;

            }
            else
                return;
         }
    else
        {
            closePort();
            ui->openClosePushButton->setIcon(QIcon(QString(":/resuorce/image/close.png")));
            ui->openClosePushButton->setText(QString("打开串口"));
            open_falg=0;
            stime->stop();
        }
    }
}
/*************************************************************
函数名称：void timeLoopSendCheckBox()
函数功能：多条发送 自动循环发送
函数参数：无
函数返回值：
函数说明：
************************************************************/
void homewo::timeLoopSendCheckBox()
{

    if(ui->timeLoopSendCheckBox->isChecked()==1)
    {
    ui->orderPerio1LineEdit->setEnabled(0);
    ui->sendTimeCheckBox->setEnabled(0);
    if(ui->sendCheckBox_0->isChecked()==1)
    {
        //qDebug()<<"自动循环检测0";
        //ui->receiveBufTextBrowser->appendPlainText(ui->orderLineEdit_0->text());
        sendMulData(ui->orderLineEdit_0->text());
    }
    if(ui->sendCheckBox_1->isChecked()==1)
    {
        //qDebug()<<"自动循环检测1";
    //    ui->receiveBufTextBrowser->appendPlainText(ui->orderLineEdit_1->text());
        //ui->receiveBufTextBrowser->setPlainText(ui->orderLineEdit_1->text());
        sendMulData(ui->orderLineEdit_1->text());
    }
    if(ui->sendCheckBox_2->isChecked()==1)
    {
        //ui->receiveBufTextBrowser->appendPlainText(ui->orderLineEdit_2->text());
       // ui->receiveBufTextBrowser->setPlainText(ui->orderLineEdit_2->text());
        sendMulData(ui->orderLineEdit_2->text());
    }
    if(ui->sendCheckBox_3->isChecked()==1)
    {
        //ui->receiveBufTextBrowser->appendPlainText(ui->orderLineEdit_3->text());
            sendMulData(ui->orderLineEdit_3->text());
    }
    if(ui->sendCheckBox_4->isChecked()==1)
    {
        //ui->receiveBufTextBrowser->appendPlainText(ui->orderLineEdit_4->text());
            sendMulData(ui->orderLineEdit_4->text());
    }
    if(ui->sendCheckBox_5->isChecked()==1)
    {
        //ui->receiveBufTextBrowser->appendPlainText(ui->orderLineEdit_5->text());
            sendMulData(ui->orderLineEdit_5->text());
    }
    if(ui->sendCheckBox_6->isChecked()==1)
    {
       // ui->receiveBufTextBrowser->appendPlainText(ui->orderLineEdit_6->text());
            sendMulData(ui->orderLineEdit_6->text());
    }
    if(ui->sendCheckBox_7->isChecked()==1)
    {
       // ui->receiveBufTextBrowser->appendPlainText(ui->orderLineEdit_8->text());
            sendMulData(ui->orderLineEdit_7->text());
    }
    if(ui->sendCheckBox_8->isChecked()==1)
    {
        //ui->receiveBufTextBrowser->appendPlainText(ui->orderLineEdit_8->text());
            sendMulData(ui->orderLineEdit_8->text());
    }
    if(ui->sendCheckBox_9->isChecked()==1)
    {
       // ui->receiveBufTextBrowser->appendPlainText(ui->orderLineEdit_9->text());
            sendMulData(ui->orderLineEdit_9->text());
    }

    }
    else
    {
        ui->orderPerio1LineEdit->setEnabled(1);
        ui->sendTimeCheckBox->setEnabled(1);
    }

}
/*************************************************************
函数名称：QStringList getPortName()
函数功能：获取串口号
函数参数：无
函数返回值：
函数说明：
************************************************************/
QStringList homewo::getPortName()
{
    QStringList Portname;
    foreach(QSerialPortInfo map,QSerialPortInfo::availablePorts())
    {
        Portname<<map.portName();
        qDebug()<<map.portName();
    }
    qDebug()<<"get port";
    return Portname;
}
/*************************************************************
函数名称：void flushPortName()
函数功能：刷新串口
函数参数：无
函数返回值：
函数说明：
************************************************************/
void homewo::flushPortName()
{
    QStringList portname=getPortName();
    if(portname.isEmpty())
    {
        ui->portNameComboBox->clear();
        ui->portNameComboBox->addItem(QString(""));
    }
    else
    {
        ui->portNameComboBox->clear();
        ui->portNameComboBox->addItems(portname);
    }

}
void homewo::on_orderPerio1LineEdit_textChanged(const QString &arg1)
{
    //ltime->stop();
    qDebug()<<arg1.toInt();
    ltime->start(arg1.toInt());
}
/*************************************************************
函数名称：void on_orderPerio1LineEdit_textChanged(const QString &arg1)
函数功能：多条发送按键控制
函数参数：无
函数返回值：
函数说明：
************************************************************/

void homewo::on_oderPushButton_0_clicked()
{
    sendMulData(ui->orderLineEdit_0->text());
}

void homewo::on_oderPushButton_1_clicked()
{
     sendMulData(ui->orderLineEdit_1->text());
}

void homewo::on_oderPushButton_2_clicked()
{
    sendMulData(ui->orderLineEdit_2->text());
}

void homewo::on_oderPushButton_3_clicked()
{
     sendMulData(ui->orderLineEdit_3->text());
}

void homewo::on_oderPushButton_4_clicked()
{
     sendMulData(ui->orderLineEdit_4->text());
}

void homewo::on_oderPushButton_5_clicked()
{
     sendMulData(ui->orderLineEdit_5->text());
}

void homewo::on_oderPushButton_6_clicked()
{
     sendMulData(ui->orderLineEdit_6->text());
}

void homewo::on_oderPushButton_7_clicked()
{
     sendMulData(ui->orderLineEdit_7->text());
}

void homewo::on_oderPushButton_8_clicked()
{
     sendMulData(ui->orderLineEdit_8->text());
}

void homewo::on_oderPushButton_9_clicked()
{
     sendMulData(ui->orderLineEdit_9->text());
}





/*************************************************************
函数名称：void openPort()
函数功能：打开串口设备
函数参数：无
函数返回值：
函数说明：
************************************************************/
bool homewo::openPort()
{
    if(myport==NULL)
    {
        myport=new QSerialPort;
    }
    myport->setPortName(ui->portNameComboBox->currentText());
    if(!myport->open(QIODevice::ReadWrite))
    {
        QMessageBox::information(this,"错误提示","打开串口失败");
        return 0;
    }
    myport->setBaudRate(ui->baudComboBox->currentText().toInt());
    //myport->setStopBits(ui->stopBitComboBox->currentText().toInt());
    myport->setDataBits(QSerialPort::DataBits(ui->dataBitComboBox->currentText().toInt()));
    getCheckStop();
    myport->setStopBits(QSerialPort::StopBits(stopData));
    myport->setParity(QSerialPort::Parity(checkData));
    myport->setFlowControl(QSerialPort::NoFlowControl);
    connect(myport,SIGNAL(readyRead()),this,SLOT(recievePort));
    return 1;
}
void homewo::closePort()
{
    myport->clear(QSerialPort::AllDirections);
    myport->close();


}
void homewo::getCheckStop()
{
    if(ui->stopBitComboBox->currentText()=="1")
    {
        stopData=QSerialPort::OneStop;
    }
    else if(ui->stopBitComboBox->currentText()=="1.5")
    {
        stopData=QSerialPort::OneAndHalfStop;
    }
    else if(ui->stopBitComboBox->currentText()=="2")
    {
        stopData=QSerialPort::TwoStop;
    }
    QString str=ui->checkBitComboBox->currentText();
    if(str=="奇校验")
    {
        checkData=QSerialPort::OddParity;
    }
    else if(str=="偶校验")
    {
        checkData=QSerialPort::EvenParity;
    }
    else if(str=="无")
    {
        checkData=QSerialPort::NoParity;
    }
}
/*************************************************************
函数名称：void recievePort()
函数功能：接受下位机数据并显示
函数参数：无
函数返回值：
函数说明：
**********************************************************/
void homewo::recievePort()
{
    if(myport->bytesAvailable()<=0)
    {
        return ;
    }
    else
    {
        if(!ui->hexDisplayCheckBox->isChecked())
        {
            if(!ui->hexSendCheckBox->isChecked())
               ui->receiveBufTextBrowser->appendPlainText(QString::fromLocal8Bit(myport->readAll()));
            else
            {
                ui->receiveBufTextBrowser->appendPlainText(QString::fromLocal8Bit(QByteArray::fromHex(myport->readAll())));
            }
        }
        else
        {       
            if(ui->hexSendCheckBox->isChecked())
                ui->receiveBufTextBrowser->appendPlainText(getHexDisplay(QString::fromLocal8Bit(myport->readAll())));
            else
                ui->receiveBufTextBrowser->appendPlainText(getHexDisplay(QString::fromLocal8Bit(((myport->readAll())).toHex())));

        }
    }
}
/*************************************************************
函数名称：void sendMulData(QString str)
函数功能：多条发送服务函数
函数参数：发送的数据
函数返回值：
函数说明：
**********************************************************/
void homewo::sendMulData(QString str)
{
        if(myport->isOpen())
        {
        if(ui->orderNewLineCheckBox->isChecked()==1)
        {
            str+="/r/n";
            if(ui->orderHexSendCheckBox->isChecked())
                myport->write(str.toLocal8Bit().toHex());
            else
                myport->write(str.toLocal8Bit());
            //ui->receiveBufTextBrowser->setPlainText(str);
        }
        else
        {
            if(ui->orderHexSendCheckBox->isChecked())
                myport->write(str.toLocal8Bit().toHex());
            else
                myport->write(str.toLocal8Bit());
        }
        }


    else
    {
        QMessageBox::information(this,"错误提示","请打开串口");
        return;
    }
}
/*************************************************************
函数名称：void
函数功能:设置背景
函数参数：bool
函数返回值：
函数说明：勾选内容
*********************************************************/
void homewo::on_backgroundCheckBox_clicked(bool checked)
{
    if(checked==1)
    {

        ui->receiveBufTextBrowser->setStyleSheet("background-color: rgb(255, 255, 255);"
                                                 "color: rgb(0, 0, 0);");
    }
    else
    {
       ui->receiveBufTextBrowser->setStyleSheet("background-color: rgb(0, 0, 0);"
                                                "  color: rgb(85, 170, 0);");

    }
}
/*************************************************************
函数名称：void
函数功能:定时器使能函数
函数参数：bool
函数返回值：
函数说明：
*********************************************************/
void homewo::sendTime(bool checked)
{
    if(checked)
    {
     ui->timeLoopSendCheckBox->setEnabled(0);
     stime->start();
     stime->setInterval(ui->periodLineEdit->text().toInt());
    ui->periodLineEdit->setEnabled(0);
    }
     else
    {
        ui->timeLoopSendCheckBox->setEnabled(1);
        stime->stop();
         ui->periodLineEdit->setEnabled(1);
    }
}
/*************************************************************
函数名称：void
函数功能:定时器发送数据函数
函数参数：
函数返回值：
函数说明：按下发送按键
*********************************************************/
void homewo::sendTimeData()
{
    if(myport !=NULL)
   {
        if(myport->isOpen())
        {
        QString str=ui->sendBuflineEdit->text();
        if(ui->sendNewLineCheckBox->isChecked()==1)
        {
            str+="/r/n";
            myport->write(str.toLocal8Bit());
            //ui->receiveBufTextBrowser->setPlainText(str);

        }
        else
        {
            myport->write(str.toLocal8Bit());
        }
        }

    }
    else
    {
        QMessageBox::information(this,"错误提示","请打开串口");
        return;
    }
}
/*************************************************************
函数名称：void
函数功能:16进制好看的显示
函数参数：bool
函数返回值：
函数说明：按下发送按键
*********************************************************/
QString homewo::getHexDisplay(QString hex)
{
    QString str=hex;
    qDebug()<<str.count();
    int j=2;
    for(int i=0;i<(hex.count()/2);i++)
    {
         //01 2 34 5 67 8 910 11  12 13  4i

        str=str.insert(j," ");
        j+=3;
     //   qDebug()<<str;
    }
     str=str.toUpper();
    return  str;
}
/*************************************************************
函数名称：void
函数功能:16进制的显示发送区域
函数参数：bool
函数返回值：
函数说明
*********************************************************/
void homewo::sendDataHex(bool checked)
{
    if(ui->sendBuflineEdit->text().isEmpty())
        return ;
   else
    {
    if(checked)
    {
        ui->sendBuflineEdit->setText(getHexDisplay(QString::fromLocal8Bit(ui->sendBuflineEdit->text().toLocal8Bit().toHex())));
    }
    else
    {

        ui->sendBuflineEdit->setText(QString::fromLocal8Bit(QByteArray::fromHex(ui->sendBuflineEdit->text().toLocal8Bit())));
    }
    }
}
/*************************************************************
函数名称：void
函数功能:校验发送数据正确性
函数参数：bool
函数返回值：
函数说明
*********************************************************/
void homewo::on_sendBuflineEdit_textChanged(const QString &arg1)
{
    const QString str=arg1;
    if(ui->hexSendCheckBox->isChecked())
    {
        Hex_flag=1;

        for(int i=0;i<str.count();i++)
        {
            qDebug()<<str[i].toLatin1();
            if(!((str[i].toLatin1() ==32 )||(str[i].toLatin1()>='a'&&str[i].toLatin1()<='f') ||(str[i].toLatin1()>='A'&&str[i].toLatin1()<='F') ||( str[i].toLatin1()>='0'&&str[i].toLatin1()<='9')))
            {

                QMessageBox::information(this,"错误提示","请输入16进制格式数据");
                return ;
            }
        }

    }
}

/*************************************************************
函数名称：void
函数功能:保存窗口
函数参数：bool
函数返回值：
函数说明
*********************************************************/
void homewo::on_saveDataPushButton_clicked()
{
    QString map=QFileDialog::getSaveFileName(this,"保存路径","home/wriken/QTtest/文件夹",
                                            "所有文件( *);;文本文件( *txt,* doc)");
    if(map.isEmpty())
    {
        QMessageBox::information(this,"错误提示","the file is on found");
        return;
    }
    QFile name(map);
    if(!name.open(QIODevice::ReadWrite)|QIODevice::Text|QIODevice::Append)
    {
        QMessageBox::information(this,"错误提示","the file open fail");
        return;
    }
    QTextStream in(&name);
    in<<ui->receiveBufTextBrowser->toPlainText();
    name.close();
}
/*************************************************************
函数名称：void
函数功能:发送文件-
函数参数：bool
函数返回值：
函数说明
*********************************************************/
void homewo::on_sendFilePushButton_clicked()
{
    if(myport->isOpen())
   {

        QString filename=ui->filePathLineEdit->text();
        QFile file(filename);
        if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            QMessageBox::information(this,"错误提示","the send file open fail");
            return;
        }
        QTextStream str(&file);
        ui->sendFileProgressBar->setMaximum(file.size());
        while(!str.atEnd())
        {
            myport->write(str.readLine().toLocal8Bit());
            ui->sendFileProgressBar->setValue(str.pos());
        }
        file.close();

    }
}
