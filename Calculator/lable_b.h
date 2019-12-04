#ifndef LABLE_B_H
#define LABLE_B_H

#include <QDialog>
#include <QMovie>
#include <QPixmap>
#include <QDebug>

namespace Ui {
class lable_B;
}

class lable_B : public QDialog
{
    Q_OBJECT

public:
    explicit lable_B(QWidget *parent = 0);
    ~lable_B();

private slots:
    void on_statr_push_clicked();

    void on_stop_pushBtn_clicked();
    void on_quit_pushBtn_clicked();
    void on_verticalSlider_valueChanged(int value);

private:
    Ui::lable_B *ui;
};

#endif // LABLE_B_H
