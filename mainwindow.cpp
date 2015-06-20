#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Windows.h>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("自动关机");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString hour,minute,sec;
    hour.setNum(ui->timeEdit->time().hour());
    minute.setNum(ui->timeEdit->time().minute());
    sec.setNum(ui->timeEdit->time().second());
    QString time = hour+":"+minute+":"+sec;
    QString str = "at "+time+" shutdown -s -f";
    system(str.toStdString().c_str());
}

void MainWindow::on_pushButton_2_clicked()
{
    QString time;
    int seconds = ui->timeEdit_2->time().hour()*3600+ui->timeEdit_2->time().minute()*60+ui->timeEdit_2->time().second();
    time.setNum(seconds);
    QString str = "shutdown -s -f -t "+time;
    system(str.toStdString().c_str());
}

void MainWindow::on_pushButton_3_clicked()
{
    QString str1 = "shutdown -a";
    QString str2 = "at /d /yes";
    system(str1.toStdString().c_str());
    system(str2.toStdString().c_str());
}
