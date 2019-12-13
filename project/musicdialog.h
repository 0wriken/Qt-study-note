#ifndef MUSICDIALOG_H
#define MUSICDIALOG_H

#include <QDialog>
#include <QDir>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QListWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QMessageBox>
#include <QFileInfoList>
namespace Ui {
class MusicDialog;
}

class MusicDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MusicDialog(QWidget *parent = 0);
    ~MusicDialog();
    void music_Init();

private slots:
    void on_Local_song_clicked();

    void on_getSong_clicked();

private:
    Ui::MusicDialog *ui;
    QMediaPlayer *songPlay;
    QMediaPlaylist *songList;
    QListWidget *showToUser;
};

#endif // MUSICDIALOG_H
