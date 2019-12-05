#ifndef PIC_SHOW_H
#define PIC_SHOW_H

#include <QDialog>
#include <QFileDialog>
#include <QPixmap>
#include <QDebug>
#include <QStringList>
#include <QMessageBox>
namespace Ui {
class pic_show;
}

class pic_show : public QDialog
{
    Q_OBJECT

public:
    explicit pic_show(QWidget *parent = 0);
    void show();
    void update();
    bool is_reset(QString &);
    ~pic_show();

private slots:
    void on_file_Btn_clicked();

    void on_quit_Btn_clicked();

    void on_pre_picBtn_clicked();

    void on_next_picBtn_clicked();

    void on_add_Btn_clicked();

    void on_delete_Btn_clicked();

private:
    Ui::pic_show *ui;
    int index;
    QStringList Filename;
};

#endif // PIC_SHOW_H
