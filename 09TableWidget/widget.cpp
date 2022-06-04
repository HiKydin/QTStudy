#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //TableWidget
    //set lieshu
    ui->tableWidget->setColumnCount(3);
    //set shuipingbiaotou
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"name"<<"gender"<<"age");
    //set hangshu
    ui->tableWidget->setRowCount(5);
    //set zhengwen
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("zs"));


    QStringList namelist;
    namelist<<"11"<<"22"<<"33"<<"44"<<"55";
    QList<QString> sexlist;
    sexlist<<"nan"<<"nv"<<"nan"<<"nv"<<"nan";

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

