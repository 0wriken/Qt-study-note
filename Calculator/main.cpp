#include "mainwindow.h"
#include <QApplication>
#include <dialog.h>
#include "function.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog h;
    h.show();
    if(h.exec()==Dialog::Rejected)
    {
        return 0;
    }
    function f;
    if(f.exec()==function::Rejected)
    {
        return 0;
    }
    MainWindow w;
    w.show();
    return a.exec();
}
