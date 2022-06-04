#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QRadioButton>
#include<QDebug>
#include<QListWidgetItem>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置按钮男默认被选中
    ui->rBtnMan->setChecked(true);

    //选中女后打印信息
    connect(ui->rBtnWoman,&QRadioButton::clicked,[=](){
        qDebug()<<"选择了女";
    });

    //多选按钮  2是选择 0是未选中
    connect(ui->cBox,&QCheckBox::stateChanged,[=](){
        qDebug()<<"老板娘好";
    });

    //利用listWidget写一首诗
//    QListWidgetItem *item = new QListWidgetItem("锄禾日当午");
//    //将一行诗放入到QListWidgetItem
//    ui->listWidget->addItem(item);
//    item->setTextAlignment(Qt::AlignHCenter);

    //QStringList  QList<QString>
    QStringList list ;
    list << "锄禾日当午" << "海底河下游";
    ui->listWidget->addItems(list);
}

MainWindow::~MainWindow()
{
    delete ui;
}

