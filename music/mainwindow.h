#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QListWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfoList>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSize>
#include <QPainter>
#include <QLinearGradient>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Local_song_clicked();
    void MusicIint();

    void on_play_Btn_clicked();

    void on_getSong_clicked();


    void on_Btn_voice_clicked();

    void on_pushButton_2_clicked();

    void on_next_Btn_pressed();

private:
    Ui::MainWindow *ui;
    QMediaPlaylist songList;
    QMediaPlayer songPlayer;
    QListWidget ShowToUser;
    int PlayFlag=0;
    int ShowFlag=0;
    int voice_flag=0;
    int PlayWay_flag=0;
};

#endif // MAINWINDOW_H
