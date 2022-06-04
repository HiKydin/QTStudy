#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->actionnew->setIcon(QIcon("路径"))

    //使用添加Qt资源 : 前缀名 + 文件名
    ui->actionnew->setIcon(QIcon(":/Image/new.png"));
    ui->actionopen->setIcon(QIcon(":/Image/edit.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

