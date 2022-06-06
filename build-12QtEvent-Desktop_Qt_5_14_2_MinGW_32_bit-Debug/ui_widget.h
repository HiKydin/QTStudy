/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <mylabel.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    Mylabel *label;
    QLabel *lblTimer;
    QLabel *lbltimer2;
    QLabel *lbltimer3;
    QPushButton *btn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        label = new Mylabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 80, 321, 61));
        label->setFrameShape(QFrame::Box);
        lblTimer = new QLabel(Widget);
        lblTimer->setObjectName(QString::fromUtf8("lblTimer"));
        lblTimer->setGeometry(QRect(100, 180, 211, 51));
        lblTimer->setFrameShape(QFrame::Panel);
        lbltimer2 = new QLabel(Widget);
        lbltimer2->setObjectName(QString::fromUtf8("lbltimer2"));
        lbltimer2->setGeometry(QRect(100, 260, 201, 61));
        lbltimer2->setFrameShape(QFrame::WinPanel);
        lbltimer3 = new QLabel(Widget);
        lbltimer3->setObjectName(QString::fromUtf8("lbltimer3"));
        lbltimer3->setGeometry(QRect(100, 350, 201, 41));
        lbltimer3->setFrameShape(QFrame::Panel);
        lbltimer3->setFrameShadow(QFrame::Sunken);
        btn = new QPushButton(Widget);
        btn->setObjectName(QString::fromUtf8("btn"));
        btn->setGeometry(QRect(390, 360, 93, 28));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QString());
        lblTimer->setText(QString());
        lbltimer2->setText(QString());
        lbltimer3->setText(QString());
        btn->setText(QCoreApplication::translate("Widget", "\346\232\202\345\201\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
