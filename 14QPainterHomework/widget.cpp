#include "widget.h"
#include "ui_widget.h"
#include<QTimer>
#include<QPainter>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //需求：图片跑马灯

    QTimer *timer = new QTimer(this);

    timer->start(1000);

    connect(timer,&QTimer::timeout,[=](){
        posX+=20;
        update();
    });


}

void Widget::paintEvent(QPaintEvent *)
{
    //新建一个画家
    QPainter painter(this);
    //画图
    if(posX>this->width())
    {
        posX=0;
    }
    painter.drawPixmap(posX,100,QPixmap(":/Image/new.png"));
}

Widget::~Widget()
{
    delete ui;
}

