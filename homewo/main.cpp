#include "homewo.h"
#include <QApplication>
#include <webdialog.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    homewo w;
    w.show();

    return a.exec();
}
