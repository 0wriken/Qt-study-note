#ifndef FUNCTION_H
#define FUNCTION_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class function;
}

class function : public QDialog
{
    Q_OBJECT

public:
    explicit function(QWidget *parent = 0);
    ~function();

private slots:

    void on_pushButton_clicked();

    void on_Dialog_Btn_clicked();

    void on_bb_pushButton_clicked();

    void on_label_Btn_clicked();

    void on_quit_Botton_clicked();

    void on_coulum_Btn_clicked();

    void on_picshow_Btn_clicked();

private:
    Ui::function *ui;
};

#endif // FUNCTION_H
