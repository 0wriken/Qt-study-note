#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int value1;
    int value2;
    char flag;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushBtn0_clicked();
    void on_pushBtn1_clicked();
    void on_pushBtn2_clicked();
    void on_pushBtn3_clicked();
    void on_pushBtn4_clicked();
    void on_pushBtn5_clicked();
    void on_pushBtn6_clicked();
    void on_pushBtn7_clicked();
    void on_pushBtn8_clicked();
    void on_pushBtn9_clicked();
    //void on_pushBtn0_clicked();


    void on_pushBtn_point_clicked();

    void on_pushBtn_clear_clicked();

    void on_pushButton_clicked();

    void on_pushBtn_delect_clicked();

    void on_pushBtn_add_clicked();

    void on_pushBtn_sub_clicked();

    void on_pushBtn_Div_clicked();

    void on_pushBtn_Mul_clicked();

    void on_pushBtn_sure_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
