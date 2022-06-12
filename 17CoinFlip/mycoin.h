#ifndef MYCOIN_H
#define MYCOIN_H

#include <QMainWindow>
#include <QPushButton>
#include<QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    //参数代表 传入金币路径还是银币路径
    MyCoin(QString BtnImg);

    //金币的属性
    int posX;//x坐标
    int posY;//y坐标
    bool flag;//正反面

    //改变标志的方法
    void changFlag();

    QTimer *timer1;//正面翻反面的定时器
    QTimer *timer2;//反面翻正面的定时器
    int min=1;
    int max=8;

    //执行动画 标志
    bool isAnimation = false;

    //重写 按下
    void mousePressEvent(QMouseEvent *e);

    //win标志
    bool isWin=false;


signals:

};

#endif // MYCOIN_H
