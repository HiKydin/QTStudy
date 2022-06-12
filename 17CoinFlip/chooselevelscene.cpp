#include "chooselevelscene.h"
#include<QMenuBar>
#include<QPainter>
#include"mypushbutton.h"
#include"mainscene.h"
#include<QDebug>
#include<QTimer>
#include<QLabel>
#include<QSound>
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //配置选择关卡场景
    this->setFixedSize(320,600);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("选择关卡");
    //准备音效
    QSound *clickSound = new QSound(":/res/click.wav",this);

    //创建菜单栏
    QMenuBar * bar =menuBar();
    setMenuBar(bar);
    //创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");

    //创建退出 菜单项
    QAction * quitAction = startMenu->addAction("退出");

    //点击退出
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });


    //返回按钮
    MyPushButton * backBtn = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());


    //点击返回
    connect(backBtn,&MyPushButton::clicked,[=](){
        //告示主场景 我返回了 主场景要监听ChooseLevelScene的返回按钮

        //点击按钮音效
        clickSound->play();

        //延时返回
        QTimer::singleShot(500,this,[=](){
            //发送自定义信号 emit
            emit this->IamBack();
        });
    });

    //创建选择关卡的按钮
    for(int i = 0 ; i < 20;i++)
    {
        MyPushButton * menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25+ i%4 * 70 ,130+ i/4 * 70);

        //监听每个按钮的点击事件
        connect(menuBtn,&MyPushButton::clicked,[=](){
            //点击按钮音效
            clickSound->play();

//            QString str=QString("选择的是第%1关").arg(i+1);
//            qDebug()<<str;

            //进入到游戏场景
            this->hide();
            play = new PlayScene(i+1);

            //设置游戏场景初始位置
            play->setGeometry(this->geometry());
            //显示窗口
            play->show();
            connect(play,&PlayScene::IamBack,[=](){
                this->setGeometry(play->geometry());
                this->show();
                delete play;
                play=NULL;
            });
        });

        QLabel *lbl = new QLabel;
        lbl->setParent(this);
        lbl->setFixedSize(menuBtn->width(),menuBtn->height());
        lbl->setText(QString::number(i+1));
        lbl->move(25+ i%4 * 70 ,130+ i/4 * 70);

        //设置label上的文字对齐方式 水平居中和垂直居中
        lbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //设置鼠标穿透
        lbl->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

//绘图
void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    //定义画家
    QPainter painter(this);

    //载入背景图
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");

    //画背景图
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画标题
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width() - pix.width())*0.5,30,pix.width(),pix.height(),pix);
}
