#include "mainwindow.h"
#include <QApplication>
#include "sign_in.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    sign_in s;
    if(s.exec()==sign_in::Rejected)
    {
        return 0;
    }
    w.show();

    return a.exec();
}
