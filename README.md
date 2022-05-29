# QTStudy
学习QT的学习笔记

## 第一天

#### 命名规范

```
类名 首字母大写，单词和单词之间首字母大写
函数名 变量名称 首字母小写，单词和单词之间首字母大写
```

#### 快捷键

```c++
快捷键
注释 ctrl + /
运行 ctrl + r
编译 ctrl + b
整行移动 ctrl + shift + ↑
自动对齐 ctrl + i
同名之间.h和.cpp切换 F4
```

#### 添加一个按钮

在头文件中引用

~~~c++
#include<QPushbutton>
~~~

在Widget::Widger()的构造函数中创建

~~~c++
QPushbutton *btn = new QPushbutton("First_button",this);
//创建一个名叫btn的按钮，按钮上显示“First_button”，按钮位于this窗口(也就是主窗口中)
~~~

重设按钮位置

~~~c++
btn->move(100,0)
//将按钮btn的位置坐标设为(100,0)
~~~

#### 添加一个窗体

~~~c++
QWidget win1 = new QWidget;
~~~

设置固定窗口大小

~~~c++
win1->setFixedSize(600,400);
//将固定窗口大小设置为600*400
~~~

重设窗口大小

~~~c++
win1->resize(400,600);
//重设窗口大小为400*600
~~~

设置窗口标题

~~~c++
win1->setWindowTitle("MyFirstWindow");
//将窗口标题设置为“MyFirstWindow”
~~~

## 第二天

#### 信号和槽

情景：下课了，老师肚子饿了，学生得知后要请老师吃饭

创建两个类，Teacher类和Student类

在Student.h中编写槽

~~~C++
class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:
    //早期qt版本要写在这里，高级版本可以写在public下
    //返回值 void ，需要声明 ，也需要实现
    //可以有参数，可以重载
    void treat();
};

~~~

在Teacher.h中编写信号

~~~C++
class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    //自定义信号 写道signals下
    //返回值是void，只需要声明，不需要实现
    //可以有参数，可以重载
    void hungry();

};
~~~

并在widget.h中定义了一个函数

~~~C++
class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Teacher *zt;
    Student *st;

    void classIsOver();
};
~~~

上面的代码在老师类中定义了一个信号，为hungry()，用于发送信号

在学生类中定义了一个槽，为treat(),用于处理信号

因此，我们的情景可以抽象为：

~~~
下课了（classIsOver()），老师（zt）肚子饿了（hungry()），学生（st）得知后要请老师吃饭（treat()）
~~~

#### 连接 connect

我们需要将以上事件连接起来，

使得：当下课时，老师肚子饿，学生请老师吃饭

~~~
connect(zt,&Teacher::hungry,st,&Student::treat)
connect(发出信号的人,信号函数地址,响应信号的人,槽函数地址)
~~~

Widget.h中这部分代码为

~~~c++
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个老师对象
    this->zt=new Teacher(this);

    //创建一个学生对象
    this->st=new Student(this);

    //连接
    connect(zt,&Teacher::hungry,st,&Student::treat);

    //调用下课函数
    classIsOver();
}

void Widget::classIsOver()
{
    下课后，触发老师饿了的信号
    emit zt->hungry();
}
~~~

同时还要在Student.h中实现treat函数

~~~
void Student::treat()
{
    qDebug()<<"请老师吃饭";
}
~~~

#### 连接带参数的信号和槽

现在我们已经实现了简单的连接，每次程序运行时，会输出”请老师吃饭“

但是，我们想要自定义更多内容时怎么办呢？

比如老师想吃宫爆鸡丁，我们希望程序输出时可以是：请老师吃xxxx

为此，我们需要重载我们的hungry()和treat()

在Teacher.h中

~~~c++
class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    //自定义信号 写道signals下
    //返回值是void，只需要声明，不需要实现
    //可以有参数，可以重载
    void hungry();
    
    void hungry(QString fooName);
	//重构一个带参数的hungry，
    //参数为QString类型的foodName代表老师想吃的菜
};

~~~

在Student.h中

~~~c++
class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:
    //早期qt版本要写在这里，高级版本可以写在public下
    //返回值 void ，需要声明 ，也需要实现
    //可以有参数，可以重载
    void treat();

    void treat(QString foodName);
    //重构一个带参数的treat，
    //参数为QString类型的foodName代表老师想吃的菜
};
~~~

因此我们需要在Student.cpp中写一个重载版本的treat()

~~~c++
//重载 带参数版本
void Student::treat(QString foodName)
{
    //qDebug()<<"请老师吃"<<foodName;
}
~~~

在widget.cpp中更新这部分代码

~~~c++
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
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
    //连接
    connect(zt,teacherSignal,st,studentSignal);
    //调用下课函数
    classIsOver();
}

void Widget::classIsOver()
{
    下课后，触发老师饿了的信号
    emit zt->hungry();
}
~~~

上面的代码涉及到函数指针，

我们用两个函数指针分别指向了重载的带参数的hungry(QString foodName)和treat(QString foodName)

#### 信号连接信号

现在我们又有新的问题，每当程序运行，就会触发下课函数，老师就会饿。

我们希望添加一个按钮，当点击按钮时，才会下课。

因此我们要在widget.cpp中引用头文件

~~~c++
#include<QPushbutton>
~~~

然后新建一个按钮对象

~~~
QPushbutton *btn = new QPushbutton("下课",this)
~~~

连接

~~~
connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);
~~~

此时widget.cpp中这部分的代码为

~~~c++
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
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
    //连接
    connect(zt,teacherSignal,st,studentSignal);
    //调用下课函数
    //classIsOver();
        
    //***************版本3*************************
    //点击一个下课按钮，然后触发事件
    QPushButton * btn = new QPushButton("下课",this);

    //重置主窗体大小
    this->resize(600,400);

    //连接
 connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);
}

void Widget::classIsOver()
{
    下课后，触发老师饿了的信号
    emit zt->hungry();
}
~~~

要注意，此时我们已经将版本2中的调用下课函数注释了，所以只有当点击按钮时，才会调用下课函数

但是这种方式显得繁琐，我们可以将按钮btn的点击事件连接到老师的teacherSignal函数指针中，这样我们点击按钮（代表下课了），老师的teacherSignal函数指针就会调用Teachar::hungry

~~~c++
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
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
    //连接
    connect(zt,teacherSignal,st,studentSignal);
    //调用下课函数
    //classIsOver();
        
    //***************版本3*************************
    //点击一个下课按钮，然后触发事件
    QPushButton * btn = new QPushButton("下课",this);

    //重置主窗体大小
    this->resize(600,400);

    //连接
	connect(btn,&QPushButton::clicked,zt,teacherSignal);
}

void Widget::classIsOver()
{
    下课后，触发老师饿了的信号
    emit zt->hungry();
}
~~~

看上去简洁不少呢...

现在还有一个小bug，就是程序输出的时候，会显示

~~~
请老师吃”宫爆鸡丁“
~~~

为什么宫爆鸡丁会有引号，而‘请老师吃’没有引号呢？

原因在于我们在定义变量的时候，foodName是QString类型的，而‘请老师吃’是char* 类型的，因此我们可以将foodName进行格式转换

~~~
//重载 带参数版本
void Student::treat(QString foodName)
{
    //qDebug()<<"请老师吃"<<foodName;

    //将QString转为 char*
    //先转为QByteArray ( .toUtf8() ) 再用.data()转为char*
    qDebug()<<"请老师吃"<<foodName.toUtf8().data();
}
~~~

## 第三天

#### 关于信号和槽的知识点概括

```
1、信号是可以连接信号的
2、一个信号可以连接多个槽函数
3、多个信号可以连接同一个槽函数
4、信号和槽函数的参数类型必须一一对应
5、信号和槽的参数个数 是不是要一致？信号的参数个数可以多于槽函数个数
```

```
QT4版本以前的信号和槽连接方式
    //利用QT4信号槽 连接无参版本
    connect(zt,SIGNAL(hungry()),st,SLOT(treat()));
    //QT4版本优点：参数直观 ， 缺点：类型不做检测
```

#### Lambda表达式

主要语法：

~~~
[](){}
中括号、小括号、大括号。一般中括号里填 = ，小括号里不填，大括号里写函数体
~~~

且看例子

```c++
//新建一个按钮，用lambda表达式实现点击事件

    QPushButton *btn2 = new QPushButton("关闭",this);
    btn2->move(100,0);
    connect(btn2,&QPushButton::clicked,this,[=](){
         emit zt->hungry("宫保鸡丁");
    });
    //如果第三参数是this，第四个参数是lambda表达式，可以省略this
```

#### 前几天的小练习

```
需求:有一个按钮open，按下时会显示一个子窗口，同时按钮变成"close"，按下会关闭子窗口
```

代码

~~~c++
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);



    //需求:有一个按钮open，按下时会显示一个子窗口，同时按钮变成"close"，按下会关闭子窗口
    //创建一个按钮
    QPushButton *btn = new QPushButton("open",this);
    //设置主窗体大小
    this->resize(600,400);
    //设置按钮父亲
    btn->setParent(this);
    //创建一个子窗口
    QWidget *win = new QWidget;
    //设置窗口名称
    this->setWindowTitle("主窗口");
    win->setWindowTitle("子窗口");
    //连接
    connect(btn,&QPushButton::clicked,win,[=](){
        if(btn->text()=="open")
        {
            win->show();
            btn->setText("close");
        }
        else
        {
            win->close();
            btn->setText("open");
        }
    });
}

~~~

