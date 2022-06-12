#include "mypushbutton.h"
#include<QDebug>
#include<QPropertyAnimation>
MyPushButton::MyPushButton(QString normalImg,QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret = pix.load(normalImg);
    if(!ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }

    //设置图片固定大小
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));


}

//弹跳动画
void MyPushButton::zoom1()
{
    //创建动画对象
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //设置动画的事件间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

    //设置曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();



}
void MyPushButton::zoom2()
{
    //创建动画对象
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //设置动画的事件间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //设置曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();
}
//重写鼠标按下事件
void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressImgPath !="")//传入的按下图片不为空，说明需要有切换图片的操作
    {
        QPixmap pix;
        bool ret = pix.load(this->pressImgPath);
        if(!ret)
        {
            qDebug()<<"按钮按下，图片加载失败";
            return;
        }
        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }

    //让父类执行其他内容
    return QPushButton::mousePressEvent(e);
}

//重写鼠标释放事件
void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->pressImgPath!="")//传入的按下图片不为空，说明需要有切换图片的操作
    {
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        if(!ret)
        {
            qDebug()<<"按钮释放，图片加载失败";
            return;
        }

        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }

    //让父类执行其他内容
    return QPushButton::mouseReleaseEvent(e);
}
