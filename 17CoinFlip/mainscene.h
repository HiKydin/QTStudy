#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include"chooselevelscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //重写绘图事件
    void paintEvent(QPaintEvent *);

    //初始化选择关卡场景
    ChooseLevelScene * chooseScene = NULL ;


private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
