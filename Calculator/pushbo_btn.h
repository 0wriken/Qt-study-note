#ifndef PUSHBO_BTN_H
#define PUSHBO_BTN_H

#include <QDialog>
#include <QMovie>
#include <QIcon>
#include <QDebug>
#include <QLabel>
#include <QMenu>
namespace Ui {
class PushBo_Btn;
}

class PushBo_Btn : public QDialog
{
    Q_OBJECT

public:
    explicit PushBo_Btn(QWidget *parent = 0);
    ~PushBo_Btn();

private slots:

    void on_q_pushButton_clicked();

private:
    Ui::PushBo_Btn *ui;
};

#endif // PUSHBO_BTN_H
