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

## 第四天

#### MainWindow的创建

mainwindow可以添加工具栏、菜单栏

~~~c++
//菜单栏  最多只能有一个
    //菜单栏的创建
    QMenuBar *bar = menuBar();
    //将菜单栏放置到窗口中
    setMenuBar(bar);

    //创建菜单
    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");

    //创建菜单项
    fileMenu->addAction("新建");
    //添加分隔符
    fileMenu->addSeparator();
    fileMenu->addAction("打开");

    //工具栏 可以有多个
    QToolBar * toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,toolBar);

    //设置是否可以浮动
    toolBar->setFloatable(false);

    //设置只允许左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    //工具栏中可以设置内容
    toolBar->addAction(fileMenu);
~~~

#### Qt中资源文件的添加

为什么要添加资源文件？

~~~c++
如果我们需要在程序中添加一个Icon文件：
ui->actionnew->setIcon(QIcon("路径"))
很容易看出，当别人下载运行我们的程序的时候，每个人的路径都是不一样的，所以无法确保Icon文件的正常使用。因此，我们需要引用Qt中的资源文件。
~~~

在Qt中使用资源文件有如下步骤：

* 将本地资源文件复制到Qt项目的工程目录下
* 点击当前工程目录，Add New...
* 选择Qt-Qt Resource File ，会生成res.qrc文件
* 点击res.qrc文件，添加前缀，一般使用"/"
* 然后添加文件，将同目录下的资源文件添加到res中

~~~
    //使用添加Qt资源 : 前缀名 + 文件名
    ui->actionnew->setIcon(QIcon(":/Image/new.png"));
    ui->actionopen->setIcon(QIcon(":/Image/edit.png"));
~~~

#### Dialog对话框的使用

对话框的分类：模态对话框和非模态对话框

* 模态对话框：不可以对其他窗口进行操作
* 非模态对话框：可以对其他窗口进行操作

~~~c++
//点击新建按钮，弹出一个对话框
connect(ui->actionnew,&QAction::triggered,[=](){
    //...创建对话框
}；
~~~



模态创建 阻塞

~~~c++
//在主窗口创建一个对话框
QDialog dlg(this);
//设置对话框大小为200*100
dlg.resize(200,100);
//显示对话框（阻塞）
dlg.exec();
~~~

非模态对话框

~~~c++
QDialog dlg2(this);
//非模态显示
dlg2.show();
~~~

我们会发现，dlg2对话框一闪而过就消失了，是因为在匿名函数中，dlg2在栈上，执行完`dlg2.show()`就被释放了

~~~c++
//在堆上创建
QDialog * dlg3 = new QDialog(this);
dlg3->resize(200,100);
dlg3->setAttribute(Qt::WA_DeleteOnClose);//设置属性：在被关闭时释放对象
dlg3->show();
~~~

#### 消息对话框

##### 错误对话框

~~~c++
QMessageBox::critical(this,"critical","错误");
~~~

##### 信息对话框

~~~c++
QMessageBox::information(this,"information","信息");
~~~

##### 问题对话框

~~~c++
QMessageBox::question(this,"question","问题",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel)
~~~

如果要接收用户的选项：

~~~c++
//参数1 父亲 参数2 标题 参数3 提示内容 参数4 按键类型 参数5 默认关联回车的按键
if(QMessageBox::Save == QMessageBox::question(this,"question","问题",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel))
{
     qDebug()<<"选择的是保存";
}
else
{
     qDebug()<<"选择的是取消";
}
~~~

##### 警告对话框

```c++
QMessageBox::warning(this,"warning","警告");
```

## 第五天

#### 控件

##### 单选框

~~~c++
//设置按钮男默认被选中
ui->rBtnMan->setChecked(true);
~~~

~~~c++
//选中女后打印信息
connect(ui->rBtnWoman,&QRadioButton::clicked,[=](){
        qDebug()<<"选择了女";
});
~~~

##### 多选框

```c++
//多选按钮  2是选择 0是未选中
connect(ui->cBox,&QCheckBox::stateChanged,[=](){
        qDebug()<<"选择3";
});
```

##### 列表框

```c++
//利用listWidget写一首诗
//QListWidgetItem *item = new QListWidgetItem("锄禾日当午");
//将一行诗放入到QListWidgetItem
ui->listWidget->addItem(item);
item->setTextAlignment(Qt::AlignHCenter);

//QStringList  QList<QString>
QStringList list ;
list << "锄禾日当午" << "汗滴禾下土";
ui->listWidget->addItems(list);
```

#### Tree控件

```c++
 //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");

	QTreeWidgetItem * liitem = new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem * mingitem = new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem * zhiitem = new QTreeWidgetItem(QStringList()<<"智力");
//添加顶部节点
    ui->treeWidget->addTopLevelItem(liitem);
    ui->treeWidget->addTopLevelItem(mingitem);
    ui->treeWidget->addTopLevelItem(zhiitem);

//添加子节点
    QStringList lihero1;
    lihero1<<"gangbeizhu"<<"henrou";
    QTreeWidgetItem *l1 = new QTreeWidgetItem(lihero1);
    liitem->addChild(l1);

```

##### TableWidget

```c++
    //TableWidget
    //设置列数
    ui->tableWidget->setColumnCount(3);
    //设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"name"<<"gender"<<"age");
    //设置行数
    ui->tableWidget->setRowCount(5);
    //设置正文
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("张三"));


    QStringList namelist;
    namelist<<"张三"<<"李四"<<"王五"<<"赵六"<<"田七";
    QList<QString> sexlist;
    sexlist<<"男"<<"女"<<"男"<<"女"<<"男";

    //循环填表
    for(int i=0;i<5;i++)
    {
        int cnt=0;
        ui->tableWidget->setItem(i,cnt++,new QTableWidgetItem(namelist[i]));
        ui->tableWidget->setItem(i,cnt++,new QTableWidgetItem(sexlist.at(i)));
        ui->tableWidget->setItem(i,cnt++,new QTableWidgetItem(QString::number(i+18)));
    }
```

##### StackedWidget

可以通过按钮控制显示的界面

```c++
    //StackedWidget
    //设置默认显示界面 scrollArea
        ui->stackedWidget->setCurrentIndex(0);
    //scrollArea
    connect(ui->btn_ScrollArea,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    //tabwidget
    connect(ui->btn_TabWidget,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    //toolbox
    connect(ui->btnToolBox,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });
```

##### 下拉框

```c++
    //下拉框
    ui->comboBox->addItem("男");
    ui->comboBox->addItem("女");

    connect(ui->btn_choose,&QPushButton::clicked,[=](){
        ui->comboBox->setCurrentIndex(1);
    });
```

##### Label

```c++
    //使用 QLabel显示图片
    ui->lbl_Image->setPixmap(QPixmap(":/Image/edit.png"));
```

#### 自定义控件

要设置Qt中的自定义控件，需要在当前项目中新建一个Qt设计师界面类，选择空窗口。然后在该窗口中绘制需要的控件。

```c++
//QSpinBox移动 QSlider跟着移动
    void(QSpinBox:: * spSingnal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox,spSingnal,ui->horizontalSlider,&QSlider::setValue);

    //QSlider移动 QSpinBox跟着移动
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
```

可以定义接口出来

```c++
//设置数值
void SmallWidget::setNum(int num)
{
    ui->spinBox->setValue(num);
}
//获取数值
int SmallWidget::getNum()
{
    return ui->spinBox->value();
}

```

## 第六天

#### Qt中的事件

设置鼠标事件，添加头文件

~~~c++
#include<QMouseEvent>
~~~

需求：设置一个Label控件，当鼠标进入和离开时分别输出

在自定义控件Label.h中添加以下公有函数

~~~c++
    //鼠标进入事件
    void enterEvent(QEvent *event);

    //鼠标离开事件
    void leaveEvent(QEvent *);
~~~

在label.cpp中实现

```c++
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
```

这样最简单的鼠标进入、离开事件就写好了

同时，我们还可以添加鼠标的点击、释放、移动事件

```c++
//鼠标按下
virtual void mousePressEvent(QMouseEvent *ev);
//鼠标释放
virtual void mouseReleaseEvent(QMouseEvent *ev);
//鼠标移动
virtual void mouseMoveEvent(QMouseEvent *ev);
```

```c++
//鼠标按下
void Mylabel::mousePressEvent(QMouseEvent *ev)
{
	qDebug()<<"鼠标按下了";
}

//鼠标释放
void Mylabel::mouseReleaseEvent(QMouseEvent *ev)
{
    qDebug()<<"鼠标释放了";
}
//鼠标移动
void Mylabel::mouseMoveEvent(QMouseEvent *ev)
{
    qDebug()<<"鼠标移动了";
}
```

好，再接下来，我们可以做一些额外的输出内容，比如输出鼠标按下/释放/移动的坐标。那么，鼠标的坐标信息储存在哪里呢？

通过QMouseEvent *ev中我们可以找到许多信息，其中就包含我们需要的坐标信息。

~~~c++
//鼠标按下
void Mylabel::mousePressEvent(QMouseEvent *ev)
{
    //Qt中的格式化输出
    QString str = QString("鼠标按下了 x=%1 y=%2").arg(ev->x()).arg(ev->y());
	qDebug()<<str;
}

//鼠标释放
void Mylabel::mouseReleaseEvent(QMouseEvent *ev)
{
    //Qt中的格式化输出
    QString str = QString("鼠标释放了 x=%1 y=%2").arg(ev->x()).arg(ev->y());
	qDebug()<<str;
}
//鼠标移动
void Mylabel::mouseMoveEvent(QMouseEvent *ev)
{
    //鼠标移动是一个特殊的事件，不能向上面这样写
    //联合按键 全真判断 &
    if(ev->buttons() & Qt::LeftButton)
    {
        QString str = QString("鼠标移动了 x=%1 y=%2").arg(ev->x()).arg(ev->y());
        qDebug()<<str;
    }
}
~~~

要注意，鼠标的移动是一个过程。因此我们需要使用联合按键，进行全真判断

#### 事件分发器

在自定义控件label.h中添加

```c++
    //通过event事件分发器 拦截 鼠标按下事件
    bool event(QEvent *e);
```

```c++
//通过event事件分发器 拦截 鼠标按下事件
bool Mylabel::event(QEvent *e)
{
    //如果是鼠标按下，在event事件分发中设置拦截
    if(e->type()==QEvent::MouseButtonPress)
    {
        //静态类型转换 static_cast<待转换的类型>(目标类型)
        QMouseEvent *ev = static_cast<QMouseEvent*>(e);
        QString str = QString("Event中 鼠标按下了 x=%1 y=%2").arg(ev->x()).arg(ev->y());
        qDebug()<<str;

        return true;//true代表用户自己处理
    }

    //其他事件 交给父类出来 默认处理
    return QLabel::event(e);
}

```

#### 定时器事件

Qt中使用定时器有两种方式

方式1，

```c++
 //定时器的第一种方式
    QTimer * timer = new QTimer(this);
    //启动定时器
    timer->start(500);

//将lbltimer3与定时器连接
    connect(timer,&QTimer::timeout,[=](){
        //lbltimer3每隔0.5秒+1
        static int num = 1;
        //要将int类型转换为QString类型
        ui->lbltimer3->setText(QString::number(num++));
    });
```

```c++
    //点击暂停按钮实现停止定时器
    connect(ui->btn,&QPushButton::clicked,[=](){
       timer->stop();
    });
```

方式2，

在widget.h中添加：

```c++
    //重写定时器的事件
    void timerEvent(QTimerEvent *ev);
```

在widget.cpp中实现

```c++
//重写定时器的事件
void Widget::timerEvent(QTimerEvent *ev)
{
    //lblTimer每隔1秒+1
    static int num = 1;
    ui->lblTimer->setText(QString::number(num++));
}
```

现在我们介绍了两种定时器的使用，那么，如果要同时使用两个定时器呢？

对于方法1，同时使用两个定时器只需要new一个就行了。

但是方法2操作就有点不同了，直接上代码

在widget.h中添加：

```c++
    int id1;//定时器1的唯一标识
    int id2;//定时器2的唯一表示
```

在widget.cpp中实现

```c++
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动定时器
    //参数1 间隔 单位是毫秒
    id1 = startTimer(1000);
    id2 = startTimer(2000);

}
//重写定时器的事件
void Widget::timerEvent(QTimerEvent *ev)
{

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
```

#### 事件过滤器

在widget.h中添加：

```c++
    //重写事件过滤器的事件
    bool eventFilter(QObject * ,QEvent * );
```

在widget.cpp中实现

```c++
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

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
```

## 第七天

#### 绘图事件

要在Qt中使用绘图事件，要在widget.h中添加

```c++
 //绘图事件
    void paintEvent(QPaintEvent *);
```

然后在widget.cpp中实现即可

首先来画一条直线

```c++
//实例化画家类 this指定的是绘图的设备
    QPainter painter(this);
//画直线
    painter.drawLine(QPoint(0,0),QPoint(100,100));
```

```c++
	//画 圆/椭圆
    painter.drawEllipse(QPoint(100,100),50,50);

    //画矩形
    painter.drawRect(100,100,20,30);
    painter.drawRect(QRect(20,20,50,50));

    //画文字
    painter.drawText(QRect(10,200,150,50),"好好学习，天天向上");
```

如果要让图画更加美观，可以设置画笔和画刷

```c++
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
```

注意，设置画笔和画刷应该在画图前。

#### 高级绘图

```c++
 	QPainter painter2(this);
	//不设置抗锯齿
    painter2.drawEllipse(QPoint(200,200),50,50);
    //设置 抗锯齿能力 效率低
    painter2.setRenderHint(QPainter::Antialiasing);
    painter2.drawEllipse(QPoint(300,200),50,50);
```

设置抗锯齿可以让图片看起来更清晰。

```c++
	//画矩形
    painter2.drawRect(QRect(200,200,50,50));

    //移动画家
    painter2.translate(100,0);

    //保存画家状态
    painter2.save();
	
	//画矩形
    painter2.drawRect(QRect(200,200,50,50));

    //还原画家保存状态
    painter.restore();
```

我们可以看到，本来应该重合的矩形，通过移动画家的相对位置，使它们没有重合

#### 画资源图片

```c++
 	QPainter painter3(this);
    painter3.drawPixmap(50,100,QPixmap(":/Image/edit.png"));
```

我们可以添加一个按钮，每当按一下按钮，图片向右移动20px。

在头文件定义一个`posX=0`,代表x坐标

```c++
    QPainter painter3(this);
    //painter3.drawPixmap(50,100,QPixmap(":/Image/edit.png"));

    //点击移动按钮，移动图片
    if(posX>this->width())
    {
        posX=0;
    }
    painter3.drawPixmap(posX,100,QPixmap(":/Image/edit.png"));
```

#### 课后作业

需求：使用绘图事件绘制一张资源图片，每隔1s向右移动20px，当图片超过窗体时，实现跑马灯效果。

```c++
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //需求：图片跑马灯

    QTimer *timer = new QTimer(this);

    timer->start(1000);

    connect(timer,&QTimer::timeout,[=](){
        posX+=20;
        update();
    });
}

void Widget::paintEvent(QPaintEvent *)
{
    //新建一个画家
    QPainter painter(this);
    //画图
    if(posX>this->width())
    {
        posX=0;
    }
    painter.drawPixmap(posX,100,QPixmap(":/Image/new.png"));
}

```

## 第八天

#### Pixmap绘图设备

```c++
    //创建300*300画布
	QPixmap pix(300,300);

    //填充颜色
    pix.fill(Qt::white);

    //声明画家
    QPainter painter(&pix);
    painter.setPen(QPen(Qt::green));
    painter.drawEllipse(QPoint(150,150),100,100);

    //保存
    pix.save("C:\\");
```

#### QImage绘图设备

```c++
    //设置300*300画布，填充色白色
    QImage img(300,300,QImage::Format_RGB32);
    img.fill(Qt::white);

    //声明画家
    QPainter painter(&img);
    painter.setPen(QPen(Qt::blue));
    painter.drawEllipse(QPoint(150,150),100,100);

    //保存
    img.save("C:\\img.png");
```

QImage绘图设备可以对像素进行访问

~~~c++
    //在widget.h中定义绘图事件
    void paintEvent(QPaintEvent *);
~~~

在widget.cpp中重写绘图事件

```c++
void Widget::paintEvent(QPaintEvent *)
{  
	//画家
    QPainter painter(this);

    //利用QImage 对像素进行修改
    QImage img;
    img.load(":/Image/edit.png");

    //修改像素点
    for(int i=50;i<100;i++)
    {
        for(int j=50;j<100;j++)
        {
            QRgb value = qRgb(255,0,0);
            img.setPixel(i,j,value);
        }
    }
    //画资源图片
    painter.drawImage(0,0,img);
}
```

#### QPicture绘图设备

可以记录和重现绘图的指令

```c++
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //QPicture 绘图设备 可以记录和重现绘图的指令
    QPicture pic;
    QPainter painter;

    painter.begin(&pic);    //开始往pic上画
    painter.setPen(QPen(Qt::cyan));
    painter.drawEllipse(QPoint(150,150),100,100);
    painter.end();    //结束画画

    //保存到磁盘
    pic.save("C:\\pic.zt");

}
void Widget::paintEvent(QPaintEvent *)
{
    //重现QPicture的绘图指令
    QPicture pic;
    pic.load("C:\\pic.zt");
    //画家
    QPainter painter(this);
    painter.drawPicture(0,0,pic);
}
```

#### Qt中的文件读写

##### 读文件

在空窗体中绘制一个Line Edit 、一个按钮、一个Text Edit，

实现：点击按钮时弹出文件对话框，选择文件后将路径显示在Line Edit中，并将文件内容输出到Text Edit中

```c++
 connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString path = QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\admin\\Desktop");
        //将路径放入到lineEdit中
        ui->lineEdit->setText(path);

        //读取内容 放入到textEdit中
        //QFile默认读的格式是UTF-8
        QFile file(path); //参数就是读取文件的路径
        //设置打开方式
        file.open(QIODevice::ReadOnly);

        QByteArray array = file.readAll();//全部读

        //将读取到的数据 放入textEdit中
        ui->textEdit->setText(array);

        //对文件对象进行关闭
        file.close();
 });
```

如果要在读取文件的时候要按行读也可以：

```c++
	//按行读        
	QByteArray array = file.readLine();
	//一行一行读完
    QByteArray array;
    while(!file.atEnd())
    {
		array+=file.readLine();
	}
```

如果目标文件编码格式不是UTF-8，需要使用`编码格式类`进行转码

```c++
 connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString path = QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\admin\\Desktop");
        //将路径放入到lineEdit中
        ui->lineEdit->setText(path);

        //编码格式的类
        QTextCodec * codec = QTextCodec::codecForName("gbk");

        //读取内容 放入到textEdit中
        QFile file(path); //参数就是读取文件的路径
        //设置打开方式
        file.open(QIODevice::ReadOnly);

        QByteArray array = file.readAll();//全部读

        //将读取到的数据 放入textEdit中
        ui->textEdit->setText(array);

        //转码
        ui->textEdit->setText(codec->toUnicode(array));

        //对文件对象进行关闭
        file.close();
});
```

##### 写文件

```c++
	//进行写文件
	file.open(QIODevice::Append);//用追加的方式进行写
	file.write("要写入的内容");
	//对文件对象进行关闭
	file.close();
```

##### FileInfo

```c++
	//要查看FileInfo的文件路径
	QFileInfo info(path);
	qDebug()<<"大小"<<info.size()<<"后缀名"<<info.suffix()<<"文件名称"<<info.fileName()<<"文件路径"<<info.path();
	qDebug()<<"创建日期"<<info.created().toString("yyyy/MM/dd hh:mm:ss");
	qDebug()<<"最后的修改日期"<<info.lastModified().toString("yyyy/MM/dd hh:mm:ss");
```

