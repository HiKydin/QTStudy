#include "mainscene.h"
#include "ui_mainscene.h"
#include<QPushButton>
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
#include<QSound> //多媒体模块下的声音头文件
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //准备开始按钮的音响
    QSound *startSound = new QSound(":/res/start.wav",this);

    //配置主场景
    //设置固定大小
    setFixedSize(320,600);
    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置标题
    setWindowTitle("开心翻金币");

    //实例化选择关卡的场景
    chooseScene =new ChooseLevelScene ;

    //退出按钮的实现
    connect(ui->actionexit,&QAction::triggered,[=](){
        this->close();
    });


    //开始的按钮
    MyPushButton * startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);

    //监听选择关卡的返回按钮的信号
    connect(chooseScene,&ChooseLevelScene::IamBack,[=](){
        this->setGeometry(chooseScene->geometry());
        chooseScene->hide();//隐藏选择场景
        this->show();//重新显示主场景
    });

    //点击开始
    connect(startBtn,&MyPushButton::clicked,[=](){
        //播放开始音效资源
        startSound->play();

        //做弹跳动画
        startBtn->zoom1();
        startBtn->zoom2();

        //延时进入
        QTimer::singleShot(500,this,[=](){
            //进入到选择关卡的场景中

            //设置选择关卡场景的位置
            chooseScene->setGeometry(this->geometry());
            //自身隐藏
            this->hide();
            //显示选择关卡场景
            chooseScene->show();
        });
    });
}
void MainScene::paintEvent(QPaintEvent *)
{
    //新建画家
    QPainter painter(this);
    //新建Pixmap绘图事件
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    //画家画图
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画背景上的图标
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix);

}
MainScene::~MainScene()
{
    delete ui;
}

