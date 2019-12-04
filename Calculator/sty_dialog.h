#ifndef STY_DIALOG_H
#define STY_DIALOG_H

#include <QDialog>
#include  <QColorDialog>
#include <QFileDialog>
#include <QString>
#include <QDebug>
namespace Ui {
class sty_Dialog;
}

class sty_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit sty_Dialog(QWidget *parent = 0);
    ~sty_Dialog();

private slots:
    void on_color_Btn_clicked();

    void on_file_Btn_clicked();

    void on_quit_BTn_clicked();

private:
    Ui::sty_Dialog *ui;
};

#endif // STY_DIALOG_H
