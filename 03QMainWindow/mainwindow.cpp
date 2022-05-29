#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMenuBar>
#include<QToolBar>
#include<QDebug>
#include<QMenu>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //重置窗口大小
    this->resize(600,400);

    //菜单栏  最多只能有一个
    //菜单栏的创建
    QMenuBar *bar = menuBar();
    //将菜单栏放置到窗口中
    setMenuBar(bar);

    //创建菜单
    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");

    //创建菜单项
    fileMenu->addAction("新建");
    //添加分隔符
    fileMenu->addSeparator();
    fileMenu->addAction("打开");

    //工具栏 可以有多个
    QToolBar * toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,toolBar);

    //设置是否可以浮动
    toolBar->setFloatable(false);

    //设置只允许左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    //工具栏中可以设置内容
    toolBar->addAction(fileMenu);

}

MainWindow::~MainWindow()
{
    delete ui;
}

