#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);



    //需求:有一个按钮open，按下时会显示一个子窗口，同时按钮变成"close"，按下会关闭子窗口
    //创建一个按钮
    QPushButton *btn = new QPushButton("open",this);
    //设置主窗体大小
    this->resize(600,400);
    //设置按钮父亲
    btn->setParent(this);
    //创建一个子窗口
    QWidget *win = new QWidget;
    //设置窗口名称
    this->setWindowTitle("主窗口");
    win->setWindowTitle("子窗口");
    //连接
    connect(btn,&QPushButton::clicked,win,[=](){
        if(btn->text()=="open")
        {
            win->show();
            btn->setText("close");
        }
        else
        {
            win->close();
            btn->setText("open");
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

