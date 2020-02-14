#ifndef SIGN_IN_H
#define SIGN_IN_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
namespace Ui {
class sign_in;
}

class sign_in : public QDialog
{
    Q_OBJECT

public:
    explicit sign_in(QWidget *parent = 0);
    ~sign_in();

private slots:
    void on_sign_inBtn_clicked();

    void on_quit_Btn_clicked();

private:
    Ui::sign_in *ui;
};

#endif // SIGN_IN_H
