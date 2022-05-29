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
//    QPushButton * btn = new QPushButton("下课",this);

//    //重置大小
//    this->resize(600,400);

//    //连接
//    //connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);


//    //无参信号和槽连接
//    void (Teacher::*teacherVoidSignal)(void) = &Teacher::hungry;
//    void (Student::*studentVoidSignal)(void) = &Student::treat;
//    connect(zt,teacherVoidSignal,st,studentVoidSignal);

//    //信号和信号的连接
//    connect(btn,&QPushButton::clicked,zt,teacherVoidSignal);

    //断开信号
    //disconnect(btn,&QPushButton::clicked,zt,teacherVoidSignal);


    //***************版本4*************************
    //拓展
    //1、信号是可以连接信号的
    //2、一个信号可以连接多个槽函数
    //3、多个信号可以连接同一个槽函数
    //4、信号和槽函数的参数类型必须一一对应
    //5、信号和槽的参数个数 是不是要一致？信号的参数个数可以多于槽函数个数

    //QT4版本以前的信号和槽连接方式
    //利用QT4信号槽 连接无参版本
    //connect(zt,SIGNAL(hungry()),st,SLOT(treat()));
    //QT4版本优点：参数直观 ， 缺点：类型不做检测

    //新建一个按钮，用lambda表达式实现点击事件
    QPushButton *btn2 = new QPushButton("关闭",this);
    btn2->move(100,0);
    connect(btn2,&QPushButton::clicked,this,[=](){
         emit zt->hungry("宫保鸡丁");
    });
    //如果第三参数是this，第四个参数是lambda表达式，可以省略this
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

