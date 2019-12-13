#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "portdialog.h"
#include "musicdialog.h"
#include <QDebug>
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
#include "signdialog.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_portBtn_clicked();

    void on_musicBTN_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
