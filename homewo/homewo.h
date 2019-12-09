#ifndef HOMEWO_H
#define HOMEWO_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QString>
#include <QDebug>
#include <QMenu>
#include <QIcon>
#include <QPixmap>
#include "webdialog.h"
#include "web2dialog.h"
namespace Ui {
class homewo;
}

class homewo : public QWidget
{
    Q_OBJECT

public:
    explicit homewo(QWidget *parent = 0);
    ~homewo();

private:
    Ui::homewo *ui;
public slots:
    void showTime();
private slots:
    void on_pushButton_6_clicked();
    void on_pushButton_50_clicked();
};

#endif // HOMEWO_H
