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

    play_process=new  QProcess(this);  
    this->timer=new QTimer(this);
    connect(play_process,SIGNAL(start),this,SLOT(Started())); //进程的起始程序
    connect(play_process,SIGNAL(finished(int)),this,SLOT(Finished())); //进程的结束
    connect(play_process,SIGNAL(error(QProcess::ProcessError)),this,SLOT(Error())); //关联错误
    connect(play_process,SIGNAL(readyReadStandardOutput()),this,SLOT(MusicRead())); //读取进程的标准输出
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimeout()));
    //ui->ShowToUser->verticalScrollBar()->setStyleSheet("QScrollBar:vertical width:8px; background:rgba(0,0,0,0%);margin:0px,0px,0px,0px; padding-top:9px;  padding-bottom:9px;}");
}
void MainWindow::play_music()
{
    program = "mplayer";   //mplayer 如果不是安装在系统环境变量的默认目录，则需要写全路径
    args << "-slave"; //使用slave模式
    args << "-quiet"; //不要输出冗余信息
    args<<SongPathList[song_index];     //添加播放音乐文件的路径
    play_process->write("volume 70 1\n");  //音量大小为70
    play_process->start(program, args); //启动该进程，并传入参数args
    timer->start(800);                  //定时器800毫秒
    PlayFlag=1;                         //当前正在播放音乐   
}
void MainWindow::play_stop()
{
    play_process->write("pause\n");  //暂停
    PlayFlag=0;
}
void MainWindow::Started()
{
    qDebug() << "准备播放";
    //获取播放文件的长度以毫秒为单位
    play_process->write("get_time_length\n");
}
void MainWindow::Finished()
{
    qDebug()<<"Music is finished\n";
    timer->stop();
   //play_process->write("");
    ui->play_Btn->setStyleSheet("border-image: url(:/new/icon/图片/icon/icons8-resume-button-48.png);");
}
void MainWindow::Error()
{
     qDebug() << "报错: " << play_process->errorString();
}
void MainWindow::MusicRead()
{
    while(play_process->bytesAvailable())
    {
        QByteArray arr=play_process->readLine();
        QString str= QString::fromLocal8Bit(arr);
        if(str.contains("ANS_LENGTH"))
		{
            qDebug()<<"音乐总时间"<<str;
            str.remove("\n");
            str.remove("\r");
            str.remove("ANS_LENGTH");
            double t=str.toDouble();
            int m=(int)t/60;
            int s=(int)t%60;
            qDebug()<<m<<"::"<<s;
            //显示时间到label并设置进度条
		}//文件的总时间
		if(str.contains("ANS_TIME_POSITION"))
		{
            qDebug()<<"播放位置"<<str;
            str.remove("\r");
            str.remove("\n");
            double t= QString(str.split("=").at(1)).toDouble();
            int m=(int)t/60;
            int s=(int)t%60;
            qDebug()<<m<<"::"<<s;
            //进度条位置
		}//文件的位置	
    }
}
void MainWindow::onTimeout()
{
    play_process->write("get_time_pos\n");   //定时获取当前播放位置
}
/*获取文件列表信息*/
void MainWindow::on_Local_song_clicked()
{
    if(songList.isEmpty())
    {
        MusicIint();
        qDebug() << "文件路径"<<QCoreApplication::libraryPaths();
        QString dirname=QFileDialog::getExistingDirectory(this,"本地文件",
                                                          "/mnt/hgfs/GIT2/music/音乐文件"
                                                );

        if(!dirname.count())
        {
            QMessageBox::information(this,"错误提示","选择音乐文件");
            return ;
        }
        QDir dir(dirname);
        QStringList FilStr;
        FilStr<<"*.mp3";
        FilStr<<"*.mp4"<<"*.wav";

        //音乐文件列表
        dirlist=dir.entryInfoList(FilStr);
        for(int i=0;i<dirlist.count();i++)
        {
            //qDebug()<<"文件名"<<dirlist[i].fileName();
            ui->ShowToUser->addItem(dirlist[i].fileName());
            /*添加音乐文件径*/
            SongPathList<<dirlist[i].filePath();
            //qDebug()<<"文件路径"<<dirlist[i].filePath();
        }
        /*启动进程*/
        play_music();
    }
    /*有音乐文件*/
    else
    {
        songList.mediaRemoved(0,dirlist.count()); //清除音乐文件
        for(int i=0;i<dirlist.count();i++)
        {
            QListWidgetItem *item =ui->ShowToUser->takeItem(0)  ;
            delete item;
        }  //清除显示的Qwidgetlist
        qDebug() << "文件路径"<<QCoreApplication::libraryPaths();
        QString dirname=QFileDialog::getExistingDirectory(this,"本地文件",
                                                          "/mnt/hgfs/GIT2/music/音乐文件"
                                                );
        if(!dirname.count())
        {
            QMessageBox::information(this,"错误提示","选择音乐文件");
            return ;
        }
        QDir dir(dirname);
        //音乐文件列表
        dirlist=dir.entryInfoList();
        for(int i=2;i<dirlist.count();i++)
        {
            //qDebug()<<"文件名"<<dirlist[i].fileName();
            ui->ShowToUser->addItem(dirlist[i].fileName());
            /*播放文件路径*/
            SongPathList<<dirlist[i].filePath();
            //qDebug()<<"文件路径"<<dirlist[i].filePath();
        }
        play_music();

    }

}


void MainWindow::on_play_Btn_clicked()
{
    if(PlayFlag==0)
    {
        ui->play_Btn->setStyleSheet("border-image: url(:/new/icon/图片/icon/icons8-pause-48.png);");
        play_music();
    }
    else
    {
        ui->play_Btn->setStyleSheet("border-image: url(:/new/icon/图片/icon/icons8-resume-button-48.png);");
        play_stop();
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
        play_process->write("volume 0 1\n");   //静音
        ui->Btn_voice->setStyleSheet("QPushButton{border-image: url(:/new/icon/图片/icon/icons8-no-audio-48.png);}");
        voice_flag=1;
    }
    else
    {
        play_process->write("volume 70 1\n");  //恢复音量
        ui->Btn_voice->setStyleSheet("QPushButton{"
                                     "border-image: url(:/new/icon/图片/icon/icons8-voice-48.png);}");
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
            ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(:/new/icon/图片/icon/icons8-ice-cream-48.png);}");
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
            ui->pushButton_2->setStyleSheet("QPushButton{border-image:url(:/new/icon/图片/icon/单曲循环_32.png)}");
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
            ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(:/new/icon/图片/icon/顺序循环.png);}");
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

//切换下一首
void MainWindow::on_next_Btn_clicked()
{
    /*点击时自动切换*/
    int i=ui->ShowToUser->currentIndex().row();
    if((dirlist.length()-1)==i)
    {
        i=-1;
    } //达到最后一首时
    i++;
    ui->ShowToUser->setCurrentRow(i);
    qDebug()<<ui->ShowToUser->currentRow();
   // QListWidgetItem *Q= ui->ShowToUser->takeItem(ui->ShowToUser->currentRow()+1);  //takeitem获取列表信息
}

void MainWindow::on_pre_Btn_clicked()
{
    /*点击时自动切换*/
    int i=ui->ShowToUser->currentIndex().row();
    if(0==i)
    {
        i=dirlist.length();
    }//回到第一张时
    ui->ShowToUser->setCurrentRow(i);
}
//从列表中选择歌曲
void MainWindow::on_ShowToUser_itemSelectionChanged()
{
    QString str= ui->ShowToUser->currentItem()->text();
    QStringList list=str.split("-");
    //qDebug()<<list[0];  //获取作者名
    if(list[0]==str)
    {
        QStringList list1=str.split(".");
        ui->label_singer->setText("未知音乐家");
        ui->label_song ->setText(list1[0]);
    } //当没有获取到作者名时
    else
    {
        ui->label_singer->setText(list[0]);
        QStringList list1=list[1].split(".");
        ui->label_song->setText(list1[0]);
    }//将获取到的信息填充于信息栏
}

