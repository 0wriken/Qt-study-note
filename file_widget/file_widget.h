#ifndef FILE_WIDGET_H
#define FILE_WIDGET_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QIODevice>
#include <QTextStream>
#include <QFileInfo>
#include <QFontDialog>
namespace Ui {
class File_widget;
}

class File_widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit File_widget(QWidget *parent = 0);
    void update();
    ~File_widget();

private slots:


    void on_action_S_triggered();
    void on_TextEdit_textChanged();

    void on_action_A_triggered();

    void on_action_S_2_triggered();

    void on_action_N_triggered();

    void on_action_Q_triggered();

    void on_action_F_2_triggered();

public:
    QString File_name;
    QString File_path;
    bool Has_file;
    bool new_file=1;
    bool Change_file;
private:
    Ui::File_widget *ui;
};

#endif // FILE_WIDGET_H
