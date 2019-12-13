#include "portdialog.h"
#include "ui_portdialog.h"

PortDialog::PortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PortDialog)
{
    ui->setupUi(this);
    protInit();
}

PortDialog::~PortDialog()
{
    delete myport;
    delete ui;
}

void PortDialog::on_sureBtn_clicked()
{
    accept();
}

void PortDialog::on_quitBtn_clicked()
{
    reject();
}
 QStringList PortDialog:: getPortname()
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
 void PortDialog::flushname()
 {
     QStringList portname=getPortname();
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
 void  PortDialog:: protInit()
 {
    ui->openClosePushButton->setIcon(QIcon(":/new/prefix1/close.png"));
    flushname();
    open_falg=0;
    myport=new QSerialPort;
 }
void PortDialog::on_portNameComboBox_activated(int index)
{
    this->flushname();
}


void PortDialog::on_openClosePushButton_clicked()
{

    if(open_falg==0)
    {
        if(myport->isOpen())
        {
            qDebug()<<"open port";
            openPort();

            ui->openClosePushButton->setText("关闭串口");
            open_falg=1;
        }
        else
        {
            QMessageBox::information(this,"error","搜索不到串口");
            return ;
        }
    }
    else
    {
        myport->close();
        ui->openClosePushButton->setText("打开串口");
        open_falg=0;
    }
}
void PortDialog::openPort()
{
    if(!myport->open(QIODevice::ReadWrite))
    {
        QMessageBox::information(this,"error","port open fail");
        return ;
    }
    else
    {
        myport->setBaudRate(ui->baudComboBox->currentText().toInt());
        myport->setDataBits(QSerialPort::DataBits(ui->dataBitComboBox->currentText().toInt()));
        getCheckStop();
        myport->setStopBits(QSerialPort::StopBits(stopData));
        myport->setParity(QSerialPort::Parity(checkData));
        myport->setFlowControl(QSerialPort::NoFlowControl);
        connect(myport,SIGNAL(readyRead()),this,SLOT(recieveData()));
    }
}
void PortDialog::getCheckStop()
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
void PortDialog:: recieveData()
{
    this->recieve=QString::fromLocal8Bit(myport->readAll());
    qDebug()<<"串口读取到的数据"<<recieve;

}
