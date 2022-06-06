#include "widget.h"
#include "ui_widget.h"
#include<QTimer>//定时器的类
#include<QPushButton>
#include<QDebug>
#include<QMouseEvent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动定时器
    //参数1 间隔 单位是毫秒
    id1 = startTimer(1000);

    id2 = startTimer(2000);

    //定时器的第二种方式
    QTimer * timer = new QTimer(this);
    //启动定时器
    timer->start(500);

    connect(timer,&QTimer::timeout,[=](){
        //lbltimer3每隔0.5秒+1
        static int num = 1;
        ui->lbltimer3->setText(QString::number(num++));
    });

    //点击暂停按钮实现停止定时器
    connect(ui->btn,&QPushButton::clicked,[=](){
       timer->stop();
    });


    //给lblTimer安装事件过滤器
    //步骤1 安装事件过滤器
    ui->lblTimer->installEventFilter(this);
}
//步骤2 重写 eventfilter
bool Widget::eventFilter(QObject * obj,QEvent * e)
{
    if(obj == ui->lblTimer)
    {
        if(e->type() == QEvent::MouseButtonPress)
        {
            //静态类型转换 static_cast<待转换的类型>(目标类型)
            QMouseEvent *ev = static_cast<QMouseEvent *>(e);
            QString str = QString("事件过滤器中 鼠标按下了  x=%1  y=%2 gx=%3 gy=%4 ").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
            qDebug()<<str;

            return true;//true代表用户自己处理，不向下分发
        }
    }

    //其他默认处理
    return QWidget::eventFilter(obj,e);
}

//重写定时器的事件
void Widget::timerEvent(QTimerEvent *ev)
{
//    //lblTimer每隔1秒+1
//    static int num = 1;
//    ui->lblTimer->setText(QString::number(num++));

//   //lbltimer2 每个2秒+1
//    static int num2 = 1;
//    ui->lbltimer2->setText(QString::number(num2++));


    if(ev->timerId()==id1)
    {
        //lblTimer每隔1秒+1
        static int num = 1;
        ui->lblTimer->setText(QString::number(num++));
    }
    if(ev->timerId()==id2)
    {
        //lbltimer2 每个2秒+1
         static int num2 = 1;
         ui->lbltimer2->setText(QString::number(num2++));
    }
}


Widget::~Widget()
{
    delete ui;
}

