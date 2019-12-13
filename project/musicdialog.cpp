#include "musicdialog.h"
#include "ui_musicdialog.h"

MusicDialog::MusicDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MusicDialog)
{
    ui->setupUi(this);
    music_Init();
}

MusicDialog::~MusicDialog()
{
    delete ui;
}

void MusicDialog::on_Local_song_clicked()
{
    QString path=QFileDialog::getExistingDirectory(this,"本地文件",
                                                      "/home/wriken/QTtest/音乐文件夹"
                                                );
    qDebug()<<"路径"<<path;
    if(!path.count())
    {
        QMessageBox::information(this,"error","open music fail");
        return ;
    }
    QDir dir(path);
    QFileInfoList list= dir.entryInfoList();
    for(int i=0;i<list.count()-1;i++)
    {
        showToUser->addItem(list[i].fileName());
        songList->addMedia(QMediaContent(QUrl(list[i].filePath())));
    }
    qDebug()<<"获取音乐文件";
    //songPlay->play();



}
void MusicDialog:: music_Init()
{
    showToUser=new QListWidget;
    songPlay  =new QMediaPlayer(this);
    songList= new QMediaPlaylist(this);
    showToUser->move(200,200);
    showToUser->setMinimumSize(200,800);
    showToUser->setMaximumSize(200,800);


}

void MusicDialog::on_getSong_clicked()
{
        showToUser->show();
}
