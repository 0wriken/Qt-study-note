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
#include <QModelIndex>
#include <QProcess>
#include <QTimer>
#include <QByteArray>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void play_music(int index);         //开始播放音乐
    void play_stop();                   //停止播放音乐
    void forward(int lenth);            //向前拉伸进度
    void backward(int lenth);           //向后拉伸进度
    void playway();                     //播放方式
private slots:
    void on_Local_song_clicked();     //获取本地音乐文件
    void MusicIint();                 //初始化
    void on_play_Btn_clicked();       //按下播放音乐按钮时
    void on_getSong_clicked();        
    void on_Btn_voice_clicked();      //音量开启/关闭
    void on_pushButton_2_clicked();  
    void on_next_Btn_pressed();       
    void on_next_Btn_clicked();       //下一首歌
    void on_pre_Btn_clicked();        //上一首歌
    void on_ShowToUser_itemSelectionChanged();   //显示的音乐列表有误
    void Started();                              //启动音乐进程
    void Finished();                             //音乐进程结束
    void Error();                                //音乐进程出现错误
    void MusicRead();                            //进程从标准输入读取内容
    void onTimeout();                            //定时时间到服务函数
    void on_volume_sliderMoved(int position);

    void on_musicPlan_sliderMoved(int position);

    void on_musicPlan_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QMediaPlaylist songList;
    QMediaPlayer songPlayer;
    QListWidget ShowToUser;
    int PlayFlag=0;
    int ShowFlag=0;
    int voice_flag=0;
    int PlayWay_flag=0;
    QProcess *play_process;             //创建音乐播放器进程
    QStringList SongPathList;           //存放音乐文件路径的列表
    QFileInfoList dirlist;              //文件列表信息
    int song_index=0;                   //音乐列表下标
    QStringList args;                   //进程创建时的参数
    QString program;                    //创建进程需要的程序
    QTimer *timer;                      //定时器控制播放进度条
    bool Firstplay=true;                //第一次播放
    int pos;                            //进度条所在的位置
    bool lock_music=false;                    //锁住结束与开始

};

#endif // MAINWINDOW_H
