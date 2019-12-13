#ifndef SIGNDIALOG_H
#define SIGNDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QDebug>
namespace Ui {
class signDialog;
}

class signDialog : public QDialog
{
    Q_OBJECT

public:
    explicit signDialog(QWidget *parent = 0);
    ~signDialog();

private slots:
    void on_sign_inBtn_clicked();

private:
    Ui::signDialog *ui;
};

#endif // SIGNDIALOG_H
