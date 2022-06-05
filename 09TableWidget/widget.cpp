#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

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
}

Widget::~Widget()
{
    delete ui;
}

