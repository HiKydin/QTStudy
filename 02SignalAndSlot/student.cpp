#include "student.h"
#include<QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug()<<"请老师吃饭";
}

//重载 带参数版本
void Student::treat(QString foodName)
{
    //qDebug()<<"请老师吃饭，老师要吃"<<foodName;

    //将QString转为 char*
    //先转为QByteArray ( .toUtf8() ) 再用.data()转为char*
    qDebug()<<"请老师吃饭，老师要吃"<<foodName.toUtf8().data();
}
