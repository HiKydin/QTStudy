#include "mywidget.h"
#include <QApplication>//包含一个应用程序类的头文件

int main(int argc, char *argv[])
{
    //a应用程序对象，在qt中，应用程序对象，有且仅有一个
    QApplication a(argc, argv);
    myWidget w;
    w.show();

    //让应用程序对象进入消息循环
    return a.exec();
}
