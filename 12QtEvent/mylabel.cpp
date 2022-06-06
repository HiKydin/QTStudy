#include "mylabel.h"
#include<QDebug>
#include<QMouseEvent>
Mylabel::Mylabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标追踪
    setMouseTracking(true);
}


//鼠标进入事件
void Mylabel::enterEvent(QEvent *event)
{
    //qDebug()<<"鼠标进入了";
}

//鼠标离开事件
void Mylabel::leaveEvent(QEvent *)
{
    //qDebug()<<"鼠标离开了";
}
//鼠标按下
void Mylabel::mousePressEvent(QMouseEvent *ev)
{
    //Qt中的格式化输出
//    QString str = QString("鼠标按下了  x=%1  y=%2 gx=%3 gy=%4 ").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
//    qDebug()<<str;

    //当鼠标左键按下，提示信息
    if(ev->button()==Qt::LeftButton)
    {
        QString str = QString("鼠标按下了  x=%1  y=%2 gx=%3 gy=%4 ").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug()<<str;
    }
}
//鼠标释放
void Mylabel::mouseReleaseEvent(QMouseEvent *ev)
{

    qDebug()<<"鼠标释放了";
}
//鼠标移动
void Mylabel::mouseMoveEvent(QMouseEvent *ev)
{
    //qDebug()<<"鼠标移动了";

    //联合按键 全真判断 &
    if(ev->buttons() & Qt::LeftButton)
    {
        QString str = QString("鼠标移动了  x=%1  y=%2 gx=%3 gy=%4 ").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug()<<str;
    }
}

//通过event事件分发器 拦截 鼠标按下事件
bool Mylabel::event(QEvent *e)
{
    //如果是鼠标按下，在event事件分发中设置拦截
    if(e->type()==QEvent::MouseButtonPress)
    {
        //静态类型转换 static_cast<待转换的类型>(目标类型)
        QMouseEvent *ev = static_cast<QMouseEvent*>(e);
        QString str = QString("Event中 鼠标按下了  x=%1  y=%2 gx=%3 gy=%4 ").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug()<<str;

        return true;//true代表用户自己处理
    }

    //其他事件 交给父类出来 默认处理
    return QLabel::event(e);
}
