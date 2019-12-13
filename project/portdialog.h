#ifndef PORTDIALOG_H
#define PORTDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QIcon>
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
class PortDialog;
}

class PortDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PortDialog(QWidget *parent = 0);
    ~PortDialog();
    void protInit();
    void flushname();
    QStringList getPortname();
    void openPort();
    void getCheckStop();


private slots:
    void on_sureBtn_clicked();

    void on_quitBtn_clicked();
    void on_portNameComboBox_activated(int index);

    void on_openClosePushButton_clicked();
    void recieveData();

private:
    Ui::PortDialog *ui;
    QSerialPort *myport;
    qint32 open_falg;
    qint32 stopData;
    qint32 checkData;
    QString recieve;

};

#endif // PORTDIALOG_H
