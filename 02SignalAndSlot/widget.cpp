#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
//Teacher 类 老师类
//Student 类 学生类
//下课后 老师会触发一个信号：饿了， 学生会响应信号：请客吃饭


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师对象
    this->zt=new Teacher(this);

    //创建一个学生对象
    this->st=new Student(this);

    //***************版本1*************************
    //连接
    //connect(zt,&Teacher::hungry,st,&Student::treat);

    //调用下课函数
    //classIsOver();

    //***************版本2*************************
    //连接带参数的信号和槽
    //使用函数指针指向有参数的重载函数
    //函数指针->函数

    void(Teacher::*teacherSignal)(QString)=&Teacher::hungry;

    void(Student::*studentSignal)(QString)=&Student::treat;
    connect(zt,teacherSignal,st,studentSignal);

    //classIsOver();

    //***************版本3*************************
    //点击一个下课按钮，然后触发事件
    QPushButton * btn = new QPushButton("下课",this);

    //重置大小
    this->resize(600,400);

    //连接
//    connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);


    //无参信号和槽连接
    void (Teacher::*teacherVoidSignal)(void) = &Teacher::hungry;
    void (Student::*studentVoidSignal)(void) = &Student::treat;
    connect(zt,teacherVoidSignal,st,studentVoidSignal);

    //信号和信号的连接
    connect(btn,&QPushButton::clicked,zt,teacherVoidSignal);

    //断开信号
    //disconnect(btn,&QPushButton::clicked,zt,teacherVoidSignal);
}

void Widget::classIsOver()
{
    //下课后，触发老师饿了的信号
    //emit zt->hungry();
    emit zt->hungry("宫保鸡丁");
}

Widget::~Widget()
{
    delete ui;
}

