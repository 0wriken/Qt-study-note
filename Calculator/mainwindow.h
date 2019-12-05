#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDebug>
#include <QDialog>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int value1;
    int value2;
    int mul_flag;
    int Div_flag;
    int Add_flag;
    int Sub_flag;
    char flag;
    explicit MainWindow(QWidget *parent = 0);
    void check_mul(void);
    void check_Div(void);
    void check_Add(void);
    void check_Sub(void);
    void check(void);
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

    void on_quit_pushbotton_clicked();

  /*  void on_dialog_Btn_clicked();

    void on_Label_Btn_clicked();

    void on_PushBootn_Btn_clicked();
*/
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
