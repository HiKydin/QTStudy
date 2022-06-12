#include "playscene.h"
#include<QDebug>
#include<QMenuBar>
#include<QPainter>
#include<mypushbutton.h>
#include<QTimer>
#include<QLabel>
#include"mycoin.h"
#include"dataconfig.h"
#include<QPropertyAnimation>
#include<QSound>
PlayScene::PlayScene(int levelNum)
{
//    QString str = QString("进入了第 %1 关").arg(levelNum);
//    qDebug()<<str;
    this->levelIndex = levelNum;
    //准备音效
    QSound *clickSound = new QSound(":/res/click.wav",this);//点击按钮音效
    QSound *clickCoinSound = new QSound(":/res/clickCoin.wav",this);//点击金币音效
    QSound *winGame = new QSound(":/res/winGame.wav",this);//胜利音效
    //初始化游戏场景
    //设置固定大小
    this->setFixedSize(320,600);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    QString WindowTitle = QString("翻金币第%1关").arg(levelNum);
    this->setWindowTitle(WindowTitle);

    //创建菜单栏
    QMenuBar * bar = menuBar();
    setMenuBar(bar);
    //创建开始菜单
    QMenu *startMenu = bar->addMenu("开始");
    //创建菜单项
    QAction *quitAciton = startMenu->addAction("关闭");
    connect(quitAciton,&QAction::triggered,[=](){
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

//        qDebug()<<"不玩游戏了";
    });

    //显示当前关卡数
    QLabel *lbl = new QLabel;
    lbl->setParent(this);
    QFont font;
    font.setFamily("微软雅黑");
    font.setPixelSize(30);
    lbl->setFont(font);
    QString strlevel = QString("Level:%1").arg(levelNum);
    lbl->setText(strlevel);
    lbl->setGeometry(30,this->height()-50,120,50);

    dataConfig config;
    //初始化每个关卡的二维数组
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }

    //胜利图片显示
    QLabel *winlbl = new QLabel;
    QPixmap pix;
    pix.load(":/res/LevelCompletedDialogBg.png");
    winlbl->setParent(this);
    winlbl->setGeometry(0,0,pix.width(),pix.height());
    winlbl->setPixmap(pix);
    winlbl->move((this->width()-pix.width())*0.5,-pix.height());



    //显示金币背景图案
    for(int i=0;i<4;i++)
    {
        for(int j=0; j<4;j++)
        {
            //创建背景图片
            QPixmap pix= QPixmap(":/res/BoardNode.png");
            QLabel * lbl = new QLabel;
            lbl->setGeometry(0,0,pix.width(),pix.height());
            lbl->setPixmap(pix);
            lbl->setParent(this);
            lbl->move(60+i*50,200+j*50);

            //创建金币
            QString str;
            if(this->gameArray[i][j] ==1)
            {
                //显示金币
                str=":/res/Coin0001.png";
            }
            else
            {
                //显示银币
                str=":/res/Coin0008.png";
            }
            MyCoin * coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(62+i*50,204+j*50);

            //给 金币属性赋值
            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j];

            //将金币放入 金币的二维数组里 以便于后期维护
            coinBtn[i][j] = coin;

            //点击金币 进行翻转
            connect(coin,&QPushButton::clicked,[=](){
                coin->changFlag();
                this->gameArray[i][j] = this->gameArray[i][j]==0 ? 1 : 0;
                //点击按钮音效
                clickCoinSound->play();

                //没有翻转完成前禁止点击其他硬币
                for(int i=0;i<4;i++)
                {
                    for(int j = 0;j<4;j++)
                    {
                        coinBtn[i][j]->isWin = true;
                    }
                }
                //翻转周围硬币 延时翻转
                QTimer::singleShot(300,this,[=](){
                    //右侧金币
                    if(coin->posX +1<=3)
                    {
                        coinBtn[coin->posX+1][coin->posY]->changFlag();
                        this->gameArray[coin->posX+1][coin->posY] = this->gameArray[coin->posX+1][coin->posY] ==0 ? 1 : 0;
                    }
                    //左侧硬币
                    if(coin->posX-1>=0)
                    {
                        coinBtn[coin->posX-1][coin->posY]->changFlag();
                        this->gameArray[coin->posX-1][coin->posY] = this->gameArray[coin->posX-1][coin->posY] ==0 ? 1 : 0;
                    }
                    //上侧硬币
                    if(coin->posY-1>=0)
                    {
                        coinBtn[coin->posX][coin->posY-1]->changFlag();
                        this->gameArray[coin->posX][coin->posY-1] = this->gameArray[coin->posX][coin->posY-1] ==0 ? 1 : 0;
                    }
                    //下侧硬币
                    if(coin->posY+1<=3)
                    {
                        coinBtn[coin->posX][coin->posY+1]->changFlag();
                        this->gameArray[coin->posX][coin->posY+1] = this->gameArray[coin->posX][coin->posY+1] ==0 ? 1 : 0;
                    }
                    //周围硬币翻转后解开禁用
                    for(int i=0;i<4;i++)
                    {
                        for(int j = 0;j<4;j++)
                        {
                            coinBtn[i][j]->isWin = false;
                        }
                    }

                    //判断是否胜利
                    this->isWin = true;
                    for(int i=0;i<4;i++)
                    {
                        for(int j = 0;j<4;j++)
                        {
                            if(coinBtn[i][j]->flag == false)//只要有一个是反面，就还没赢
                            {
                                this->isWin = false;
                                break;
                            }
                        }
                    }
                    //胜利了
                    if(this->isWin == true)
                    {
                        for(int i=0;i<4;i++)
                        {
                            for(int j = 0;j<4;j++)
                            {
                                //将所有按钮的胜利标志改为true
                                coinBtn[i][j]->isWin = true;
                            }
                        }
//                        qDebug()<<"胜利";
                        //将胜利的图片移动下来
                        QPropertyAnimation * animation = new QPropertyAnimation(winlbl,"geometry");
                        //设置时间间隔
                        animation->setDuration(1000);
                        //设置开始位置
                        animation->setStartValue(QRect(winlbl->x(),winlbl->y(),winlbl->width(),winlbl->height()));
                        //设置结束位置
                        animation->setEndValue(QRect(winlbl->x(),winlbl->y()+170,winlbl->width(),winlbl->height()));
                        //设置缓和曲线
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        //执行动画
                        animation->start();
                        //播放音效
                        winGame->play();
                    }

                });

            });
        }
    }
}
void PlayScene::paintEvent(QPaintEvent *)
{
    //新建画家
    QPainter paint(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    paint.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    //缩放图片
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    paint.drawPixmap(10,30,pix.width(),pix.height(),pix);
}
