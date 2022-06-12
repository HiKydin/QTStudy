#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyPushButton(QWidget *parent = nullptr);

    //构造函数 参数1 正常显示的图片路径 参数2 按下后显示的图片路径 默认为空
    MyPushButton(QString normalImg,QString pressImg = "");
    QString normalImgPath;
    QString pressImgPath;

    //弹跳动画
    void zoom1();//向下跳
    void zoom2();//向上跳

    //重写鼠标按下事件
    void mousePressEvent(QMouseEvent *e);

    //重写鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *e);

signals:

};

#endif // MYPUSHBUTTON_H
