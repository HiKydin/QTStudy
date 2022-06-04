#include "widget.h"
#include "ui_widget.h"
#include<QStackedWidget>
#include<QComboBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //stack
    //set morendingwei scrollArea
        ui->stackedWidget->setCurrentIndex(0);
    //scrollArea
    connect(ui->btn_ScrollArea,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    //tab widget
    connect(ui->btn_TabWidget,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    //toolbox
    connect(ui->btnToolBox,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    //xialakuang
    ui->comboBox->addItem("che");
    ui->comboBox->addItem("ggg");

    connect(ui->btn_choose,&QPushButton::clicked,[=](){
        ui->comboBox->setCurrentIndex(1);
    });

    //use QLabel show image
    ui->lbl_Image->setPixmap(QPixmap(":/Image/edit.png"));
}

Widget::~Widget()
{
    delete ui;
}

