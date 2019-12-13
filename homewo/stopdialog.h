#ifndef STOPDIALOG_H
#define STOPDIALOG_H

#include <QDialog>

namespace Ui {
class stopDialog;
}

class stopDialog : public QDialog
{
    Q_OBJECT

public:
    explicit stopDialog(QWidget *parent = 0);
    ~stopDialog();

private slots:
    void on_sureBtn_clicked();

    void on_clenBtn_clicked();

private:
    Ui::stopDialog *ui;
};

#endif // STOPDIALOG_H
