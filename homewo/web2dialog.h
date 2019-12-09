#ifndef WEB2DIALOG_H
#define WEB2DIALOG_H

#include <QDialog>
#include <QDesktopServices>

#include <QUrl>
namespace Ui {
class web2Dialog;
}

class web2Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit web2Dialog(QWidget *parent = 0);
    ~web2Dialog();

private:
    Ui::web2Dialog *ui;
};

#endif // WEB2DIALOG_H
