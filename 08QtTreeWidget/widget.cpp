#include "widget.h"
#include "ui_widget.h"
#include<QTreeWidget>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //treeWidget树控件的使用

    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");

    QTreeWidgetItem * liitem = new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem * mingitem = new QTreeWidgetItem(QStringList()<<"mingjie");
    QTreeWidgetItem * zhiitem = new QTreeWidgetItem(QStringList()<<"zhili");
    //load top nodes
    ui->treeWidget->addTopLevelItem(liitem);
    ui->treeWidget->addTopLevelItem(mingitem);
    ui->treeWidget->addTopLevelItem(zhiitem);

    //add child nodes
    QStringList lihero1;
    lihero1<<"gangbeizhu"<<"henrou";
    QTreeWidgetItem *l1 = new QTreeWidgetItem(lihero1);
    liitem->addChild(l1);


}

Widget::~Widget()
{
    delete ui;
}

