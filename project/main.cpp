#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    signDialog c;
    MainWindow w;
    if(c.exec()==QDialog::Accepted)
    {
    w.show();
    }



    return a.exec();
}
