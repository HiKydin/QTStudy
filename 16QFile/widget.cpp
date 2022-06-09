#include "widget.h"
#include "ui_widget.h"
#include<QFile>
#include<QPushButton>
#include<QFileDialog>
#include<QTextCodec>
#include<QFileInfo>
#include<QDebug>
#include<QDateTime>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    //点击选取文件按钮，弹出文件对话框

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString path = QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\admin\\Desktop");
        //将路径放入到lineEdit中
        ui->lineEdit->setText(path);

        //编码格式的类
        QTextCodec * codec = QTextCodec::codecForName("gbk");

        //读取内容 放入到textEdit中
        //QFile默认读的格式是UTF-8
        QFile file(path); //参数就是读取文件的路径
        //设置打开方式
        file.open(QIODevice::ReadOnly);

        //QByteArray array = file.readAll();//全部读

        //QByteArray array = file.readLine();//按行读
        QByteArray array;
        while(!file.atEnd())
        {
            array+=file.readLine();
        }

        //将读取到的数据 放入textEdit中
        ui->textEdit->setText(array);

        //转码
        //ui->textEdit->setText(codec->toUnicode(array));

        //对文件对象进行关闭
        file.close();

        //进行写文件
        file.open(QIODevice::Append);//用追加的方式进行写
        file.write("hhhhhhhhassault啊实打实大苏打实打实");
        file.close();

        //QFileInfo

        QFileInfo info(path);

        qDebug()<<"大小"<<info.size()<<"后缀名"<<info.suffix()<<"文件名称"<<info.fileName()<<"文件路径"<<info.path();
        qDebug()<<"创建日期"<<info.created().toString("yyyy/MM/dd hh:mm:ss");
        qDebug()<<"最后的修改日期"<<info.lastModified().toString("yyyy/MM/dd hh:mm:ss");
    });
}

Widget::~Widget()
{
    delete ui;
}

