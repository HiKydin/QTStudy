#include "widget.h"
#include "ui_widget.h"
#include<QPainter>//画家类
#include<QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    //点击移动按钮，移动图片
    connect(ui->btn,&QPushButton::clicked,[=](){
        posX+=20;
        //如果要手动调用绘图事件，用updata
        update();
    });
}


//绘图事件
void Widget::paintEvent(QPaintEvent *)
{
    //实例化画家类 this指定的是绘图的设备
    QPainter painter(this);

    //设置画笔
    QPen pen(QColor(255,0,0));

    //设置画笔宽度
    pen.setWidth(3);

    //设置画笔风格
    pen.setStyle(Qt::DotLine);

    //让画家使用这个笔
    painter.setPen(pen);

    //设置画刷
    //QBrush brush(QColor(0,255,0));
    QBrush brush(Qt::green);
    //设置画刷的风格
    brush.setStyle(Qt::Dense7Pattern);

    //让画家使用画刷
    painter.setBrush(brush);

    painter.drawLine(QPoint(0,0),QPoint(100,100));


    //画圆/椭圆
    painter.drawEllipse(QPoint(100,100),50,50);

    //画矩形
    painter.drawRect(100,100,20,30);
    painter.drawRect(QRect(20,20,50,50));

    //画文字
    painter.drawText(QRect(10,200,150,50),"好好学习，天天向上");



    /////////////////////////高级设置/////////////////////

    QPainter painter2(this);
    painter2.drawEllipse(QPoint(200,200),50,50);
    //设置 抗锯齿能力 效率低
    painter2.setRenderHint(QPainter::Antialiasing);
    painter2.drawEllipse(QPoint(300,200),50,50);


    //画矩形
    painter2.drawRect(QRect(200,200,50,50));

    //移动画家
    painter2.translate(100,0);

    //保存画家状态
    painter2.save();

    painter2.drawRect(QRect(200,200,50,50));

    //还原画家保存状态
    painter.restore();


    ///////////////////利用画家 画资源图片/////////
    QPainter painter3(this);
    //painter3.drawPixmap(50,100,QPixmap(":/Image/edit.png"));


    //点击移动按钮，移动图片
    if(posX>this->width())
    {
        posX=0;
    }
    painter3.drawPixmap(posX,100,QPixmap(":/Image/edit.png"));

}

Widget::~Widget()
{
    delete ui;
}

