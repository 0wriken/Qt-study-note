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
    this->time1=new QTimer(this);
    connect(play_process,SIGNAL(started()),this,SLOT(Started())); //进程的起始程序
    connect(play_process,SIGNAL(finished(int)),this,SLOT(Finished())); //进程的结束
    connect(play_process,SIGNAL(error(QProcess::ProcessError)),this,SLOT(Error())); //关联错误
    connect(play_process,SIGNAL(readyReadStandardOutput()),this,SLOT(MusicRead())); //读取进程的标准输出
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimeout()));
    connect(time1,SIGNAL(timeout()),this,SLOT(song_Timeout()));
    ui->volume->setMaximum(200);
    ui->volume->setMinimum(0);
    time1->start(1000);

    //ui->ShowToUser->verticalScrollBar()->setStyleSheet("QScrollBar:vertical width:8px; background:rgba(0,0,0,0%);margin:0px,0px,0px,0px; padding-top:9px;  padding-bottom:9px;}");
}
/*定时实现滚轮歌曲名*/
void MainWindow::song_Timeout()
{
    //qDebug()<<ui->label_song->text().length();
    qDebug()<<song_name.length();
    if(this->song_name.length()>12)
    {
        if(++index_n>(song_name.length()-12))
            index_n=0;
        ui->label_song->setText(song_name.mid(index_n,12));
        qDebug()<<index_n;
        qDebug()<<song_name.mid(index_n,12);
    }  //循环滚动歌曲名*/
    qDebug()<<song_name;

    //qDebug()<<song_name.mid(index_n,4);
}
/*播放音乐*/
void MainWindow::play_music(int index)
{
    play_process->close();
    args.clear();
    program = "mplayer";   //mplayer 如果不是安装在系统环境变量的默认目录，则需要写全路径
    args << "-slave"; //使用slave模式
    args << "-quiet"; //不要输出冗余信息
    args<<SongPathList[index];     //添加播放音乐文件的路径
    play_process->start(program, args); //启动该进程，并传入参数args
    play_process->open();                 //开启读写功能
    play_process->write("volume 70 1\n");  //音量大小为70
    ui->volume->setValue(70);
    timer->start(80);                  //定时器800毫秒
    PlayFlag=1;                         //当前正在播放音乐   
    Firstplay=false;                    //允许暂停
    qDebug()<<"duiyhadsaos";
    ui->play_Btn->setStyleSheet("border-image: url(:/new/icon/图片/icon/icons8-pause-48.png);");  //图标为暂停
}
/*停止播放*/
void MainWindow::play_stop()
{
    play_process->write("pause\n");  //暂停/取消暂停

    PlayFlag=!PlayFlag;
}
/*播放方式切换歌曲*/
void MainWindow::playway()
{
    //play_process->write("");
     ui->play_Btn->setStyleSheet("border-image: url(:/new/icon/图片/icon/icons8-resume-button-48.png);");
     switch(this->PlayWay_flag%3)
     {
         case 0:
         {
             if((dirlist.length()-1)==song_index)
             {
                 song_index=-1;
             } //达到最后一首时
             this->song_index++;
             play_music(song_index);
             qDebug()<<"循环播放";
             break;
         }
         case 1:
         {
             int i=(rand()%SongPathList.length());
             qDebug()<<"随机数"<<i;
             song_index=i;
             play_music(song_index);
             qDebug()<<"随机播放";
             break;

         }
         case 2:
         {

             play_music(song_index);
             qDebug()<<"单曲循环";
             break;

         }
         default :
         {
             qDebug()<<"输出结果播放模式有误"<<PlayWay_flag;
             break;
         }
     }
     ui->ShowToUser->setCurrentRow(song_index);

}
void MainWindow::Started()
{
    qDebug() << "准备播放";
    //获取播放文件的长度以毫秒为单位
    play_process->write("get_time_length\n");
    qDebug() << "开始播放";
}
/*播放结束后的处理*/
void MainWindow::Finished()
{

        qDebug()<<"Music is finished\n";
        timer->stop();

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
            double t= QString(str.split("=").at(1)).toDouble();
            int m=(int)t/60;
            int s=(int)t%60;
            qDebug()<<m<<"::"<<s;
            QString str1=QString::number(m);
            str1+="::";
            str1+=QString::number(s);
            qDebug()<<str1;
            ui->labelLen->setText(str1);
            //显示时间到label并设置进度条
            int lenth=m*60+s;
            ui->musicPlan->setMinimum(0);
            ui->musicPlan->setMaximum(lenth);
		}//文件的总时间
		if(str.contains("ANS_TIME_POSITION"))
		{
            //qDebug()<<"播放位置"<<str;
            str.remove("\r");
            str.remove("\n");
            double t= QString(str.split("=").at(1)).toDouble();
            int m=(int)t/60;
            int s=(int)t%60;
            //qDebug()<<m<<"::"<<s;
            QString str1=QString::number(m);
            str1+="::";
            str1+=QString::number(s);
            ui->labelPos->setText(str1);
           //进度条位置
            this->pos=m*60+s;
            ui->musicPlan->setValue(pos);
		}//文件的位置	
    }
}
/*定时器处理函数*/
void MainWindow::onTimeout()
{
    play_process->write("get_time_pos\n");   //定时获取当前播放位置
}
/*获取文件列表信息*/
void MainWindow::on_Local_song_clicked()
{
    if(SongPathList.isEmpty())
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
       // play_music(this->song_index);
    }
    /*有音乐文件*/
    else
    {

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
       //play_music(this->song_index);

    }

}

/*播放与暂停的切换*/
void MainWindow::on_play_Btn_clicked()
{
    if(SongPathList.count()==0)
    {
        QMessageBox::information(this,"错误提示","音乐列表为空");
        return ;
    }
    if(PlayFlag==0)
    {
        if(Firstplay)
        {
            play_music(this->song_index);
            ui->play_Btn->setStyleSheet("border-image: url(:/new/icon/图片/icon/icons8-pause-48.png);");
            return ;
        }
        ui->play_Btn->setStyleSheet("border-image: url(:/new/icon/图片/icon/icons8-pause-48.png);");
        play_stop();
        timer->start(80);
    }
    else
    {
        ui->play_Btn->setStyleSheet("border-image: url(:/new/icon/图片/icon/icons8-resume-button-48.png);");
        play_stop();
        timer->stop();
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
/*音量切换*/
void MainWindow::on_Btn_voice_clicked()
{
    if(this->voice_flag==0)
    {
        play_process->write("volume 0 1\n");   //静音
        ui->Btn_voice->setStyleSheet("QPushButton{border-image: url(:/new/icon/图片/icon/icons8-no-audio-48.png);}");
        ui->volume->setValue(0);    //音量设置为0
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
            PlayFlag=1;
            PlayWay_flag++;
            break;
        }
        case 1:
        {
            //单曲循环
            ui->pushButton_2->setStyleSheet("QPushButton{border-image:url(:/new/icon/图片/icon/单曲循环_32.png)}");
            PlayFlag=1;
            PlayWay_flag++;
            break;
        }
        case 2:
        {
            //循环播放
            ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(:/new/icon/图片/icon/顺序循环.png);}");

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

/*
 * 切换下一首
*/
void MainWindow::on_next_Btn_clicked()
{
    playway();

}
/*切换上一首*/
void MainWindow::on_pre_Btn_clicked()
{
    /*点击时自动切换*/
    int i=ui->ShowToUser->currentIndex().row();
    if(0==i)
    {
        i=dirlist.length();
    }//回到第一张时
    i--;
    song_index=i;
    play_music(song_index);
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
        this->song_name=list1[0] ;
        ui->label_song->setText(list1[0]);
        index_n=0;
    }//将获取到的信息填充于信息栏
    song_index=ui->ShowToUser->currentRow();
    play_music(song_index);
}

/*控制音量*/
void MainWindow::on_volume_sliderMoved(int position)
{
    qDebug()<<"音量大小"<<position;
    if(position==0)
    {
        play_process->write("volume 0 1\n");   //静音
        ui->Btn_voice->setStyleSheet("QPushButton{border-image: url(:/new/icon/图片/icon/icons8-no-audio-48.png);}");
        return ;
    }
    QString str="volume ";
    str+=QString::number(position);
    str+=" 1\n";
    qDebug()<<str;
    play_process->write(str.toLocal8Bit());   //静音
    ui->Btn_voice->setStyleSheet("QPushButton{"
                                 "border-image: url(:/new/icon/图片/icon/icons8-voice-48.png);}");
}
/*向前拉伸进度*/
void MainWindow::forward(int lenth)
{
    QString str="seek +";
    str+=QString::number(lenth);
    str+=" 2\n";
    this->play_process->write(str.toLocal8Bit());
}
/*向后拉伸进度*/
void MainWindow::backward(int lenth)
{
    QString str="seek -";
    str+=QString::number(lenth);
    str+=" 2\n";
    this->play_process->write(str.toLocal8Bit());

}
/*拉伸进度条*/
void MainWindow::on_musicPlan_sliderMoved(int position)
{
    this->play_process->write(QString("seek "+QString::number(position)+" 2\n").toUtf8());
}
/*进度条的位置*/
void MainWindow::on_musicPlan_valueChanged(int value)
{
    if(value>=ui->musicPlan->maximum()-1)
    {
        playway();
        qDebug()<<"自动播放下一首";
    }
}


//界面逐渐淡出
void MainWindow::on_Btnclose_clicked()
{
      //QTimer *animation=new QTimer();
      QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
      animation->setDuration(1000);
      animation->setStartValue(1);
      animation->setEndValue(0);
      animation->start();
      saveLastMusic();
      ReadSaveMusic();
      connect(animation, SIGNAL(finished()), this, SLOT(close()));
}

//音乐播放结束后写入文件保存信息
void MainWindow::saveLastMusic()
{
        QString flagSave ="1|";
        QString strMusicSave=ui->ShowToUser->currentItem()->text()+"|";
        QString songStrIndex=QString(song_index)+"|";
        QString e=strMusicSave+songStrIndex+flagSave;
        //QFile file("/new/icon/图片/icon/savemusic.txt");
        QFile file("/mnt/hgfs/GIT2/music/savemusic.txt");
        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            file.write(e.toUtf8());  //把数据存储进文档中
            file.close();
        }
        else
        {
            qDebug()<<"写操作打不开文件";
        }

}

void MainWindow::ReadSaveMusic()
{
    QFile file("/mnt/hgfs/GIT2/music/savemusic.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QByteArray t;
        while(!file.atEnd())
        {
            t += file.readLine(); //逐行存储文件信息
        }
        qDebug()<<"存储的音乐文件信息"<<(QString(t));
        file.close();
    }
    else
    {
        qDebug()<<"读取打不开文件";
    }
}
