#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::MusicIint()
{
    QMediaPlaylist *songList=new QMediaPlaylist(this);
    QMediaPlayer *songPlayer=new QMediaPlayer(this);


}
void MainWindow::on_Local_song_clicked()
{
    MusicIint();
    qDebug() << "文件路径"<<QCoreApplication::libraryPaths();
    QString dirname=QFileDialog::getExistingDirectory(this,"本地文件",
                                                      "/home/wriken/QTtest/音乐文件夹"
                                            );


    if(!dirname.count())
    {
        QMessageBox::information(this,"错误提示","选择音乐文件");
        return ;
    }
    QDir dir(dirname);
    QFileInfoList dirlist=dir.entryInfoList();
    for(int i=0;i<dirlist.count();i++)
    {
        //qDebug()<<"文件名"<<dirlist[i].fileName();
        ui->ShowToUser->addItem(dirlist[i].fileName());
        songList.addMedia(QMediaContent(QUrl(dirlist[i].filePath())));
        //qDebug()<<"文件路径"<<dirlist[i].filePath();
    }
    songPlayer.setPlaylist(&songList);
    songPlayer.play();
    PlayFlag=1;
}


void MainWindow::on_play_Btn_clicked()
{
    if(PlayFlag==0)
    {
        ui->play_Btn->setStyleSheet("border-image: url(:/desinger/QTtest/QT图片/icon/icons8-pause-48.png);");
        songPlayer.play();
        PlayFlag=1;
    }
    else
    {
        ui->play_Btn->setStyleSheet("border-image: url(:/desinger/QTtest/QT图片/icon/icons8-resume-button-48.png);");
        songPlayer.stop();
        PlayFlag=0;
    }
}

void MainWindow::on_getSong_clicked()
{
    if(ShowFlag==0)
    {

        ShowFlag=1;
    }
    else
    {

        ShowFlag=0;

    }
}


void MainWindow::on_Btn_voice_clicked()
{
    if(this->voice_flag==0)
    {
        ui->Btn_voice->setStyleSheet("QPushButton{border-image: url(:/QTtest/QT图片/icon/icons8-no-audio-48.png);}");
        voice_flag=1;
    }
    else
    {

        ui->Btn_voice->setStyleSheet("QPushButton{"
                                     "border-image: url(:/desinger/QTtest/QT图片/icon/icons8-voice-48.png);}");
        voice_flag=0;
    }
}
//默认循环播放
void MainWindow::on_pushButton_2_clicked()
{



    switch (this->PlayWay_flag%3)
    {
        case 0:
        {
            //随机播放
            ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(:/desinger/QTtest/QT图片/icon/icons8-ice-cream-48.png);}");
            songList.setPlaybackMode(QMediaPlaylist::Random);
            songPlayer.setPlaylist(&songList);
            songPlayer.play();
            PlayFlag=1;
            PlayWay_flag++;
            break;
        }
        case 1:
        {
            //单曲循环
            ui->pushButton_2->setStyleSheet("QPushButton{border-image:url(:/QTtest/QT图片/icon/单曲循环_32.png)}");
            songList.setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
            songPlayer.setPlaylist(&songList);
            songPlayer.play();
            PlayFlag=1;
            PlayWay_flag++;
            break;
        }
        case 2:
        {
            //循环播放
            ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(:/QTtest/QT图片/icon/顺序循环.png);}");
            songList.setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
            songPlayer.setPlaylist(&songList);
            songPlayer.play();
            PlayFlag=1;
            PlayWay_flag++;
            break;
        }
        default:
        {
            printf("错误的播放方式");
            break;
        }
    }

}

void MainWindow::on_next_Btn_pressed()
{
    QSize mysize(ui->next_Btn->height()+10,
            ui->next_Btn->width()+10);

}
