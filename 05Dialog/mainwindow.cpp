#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include<QMessageBox>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击新建按钮，弹出一个对话框
    connect(ui->actionnew,&QAction::triggered,[=](){
        //对话框 分类
        //模态对话框（不可以对其他窗口进行操作） 非模态对话框 （可以对其他的窗口进行操作）
        //模态创建 阻塞

//        QDialog dlg(this);
//        dlg.resize(200,100);
//        dlg.exec();

        //非模态对话框
//        QDialog dlg2(this);
//        dlg2.show();
        //一闪而过，因为在匿名函数中，dlg2在栈上，执行完show就被释放了

        //在堆上创建
//        QDialog *dlg3 = new QDialog(this);
//        dlg3->resize(200,100);
//        dlg3->setAttribute(Qt::WA_DeleteOnClose);//设置属性：在被关闭时释放对象
//        dlg3->show();

        //消息对话框
        //错误对话框
        //QMessageBox::critical(this,"critical","错误");

        //信息对话框
        //QMessageBox::information(this,"information","信息");

        //问题对话框
        //参数1 父亲 参数2 标题 参数3 提示内容 参数4 按键类型 参数5 默认关联回车的按键
//        if(QMessageBox::Save == QMessageBox::question(this,"question","问题",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel))
//        {
//            qDebug()<<"选择的是保存";
//        }
//        else
//        {
//            qDebug()<<"选择的是取消";
//        }

        //警告对话框
        QMessageBox::warning(this,"warning","警告");

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

