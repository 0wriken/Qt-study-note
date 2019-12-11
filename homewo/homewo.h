#ifndef HOMEWO_H
#define HOMEWO_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QString>
#include <QDebug>
#include <QMenu>
#include <QIcon>
#include <QPixmap>
#include "webdialog.h"
#include "web2dialog.h"
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QIODevice>
#include <QTextStream>
#include <QStringList>
#include <QPixmap>
#include <QChar>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QIODevice>
namespace Ui {
class homewo;
}

class homewo : public QWidget
{
    Q_OBJECT

public:
    explicit homewo(QWidget *parent = 0);
    bool openPort();
    void closePort();
    ~homewo();
    QStringList getPortName();
    void getCheckStop();
    void sendMulData(QString str);
    QString getHexDisplay(QString hex);
    void sendHexMode(QString str);
private:
    Ui::homewo *ui;
    int open_falg;
    QTimer *ltime;
    QTimer *stime;
    QSerialPort *myport;
    qint32 stopData;
    qint32 checkData;




public slots:
    void showTime();
    void flushPortName();
    void timeLoopSendCheckBox();
    void recievePort();
    void sendTime(bool checked);
    void sendTimeData();


private slots:

    void on_openFilePushButton_clicked();
    void on_netCommandLinkButton_clicked();
    void on_commandLinkButton_clicked();
    void on_sendPushButton_clicked();
    void on_cleanSendPushButton_clicked();
    void on_cleanReceivePushButton_clicked();
    void Xcom_init();
    void on_openClosePushButton_clicked();

    void on_orderPerio1LineEdit_textChanged(const QString &arg1);
    void on_oderPushButton_0_clicked();
    void on_oderPushButton_1_clicked();
    void on_oderPushButton_2_clicked();
    void on_oderPushButton_3_clicked();
    void on_oderPushButton_4_clicked();
    void on_oderPushButton_5_clicked();
    void on_oderPushButton_6_clicked();
    void on_oderPushButton_7_clicked();
    void on_oderPushButton_8_clicked();
    void on_oderPushButton_9_clicked();
    void on_backgroundCheckBox_clicked(bool checked);
};

#endif // HOMEWO_H
