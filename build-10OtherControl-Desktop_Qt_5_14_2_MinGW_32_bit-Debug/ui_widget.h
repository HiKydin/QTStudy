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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_9;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QWidget *page_6;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_3;
    QWidget *tab_2;
    QWidget *page_5;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *page_3;
    QWidget *page_2;
    QComboBox *comboBox;
    QPushButton *btn_choose;
    QLabel *lbl_Image;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btn_ScrollArea;
    QPushButton *btn_TabWidget;
    QPushButton *btnToolBox;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(673, 600);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(9, 9, 224, 338));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        verticalLayout_2 = new QVBoxLayout(page_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea = new QScrollArea(page_4);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 204, 318));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_9 = new QPushButton(scrollAreaWidgetContents);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        verticalLayout->addWidget(pushButton_9);

        pushButton_7 = new QPushButton(scrollAreaWidgetContents);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(scrollAreaWidgetContents);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        verticalLayout->addWidget(pushButton_8);

        pushButton_6 = new QPushButton(scrollAreaWidgetContents);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_5 = new QPushButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        stackedWidget->addWidget(page_4);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        horizontalLayout = new QHBoxLayout(page_6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(page_6);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        stackedWidget->addWidget(page_6);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        toolBox = new QToolBox(page_5);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(50, 60, 85, 143));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 85, 56));
        toolBox->addItem(page, QString::fromUtf8("famil"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        toolBox->addItem(page_3, QString::fromUtf8("hhhh"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 85, 56));
        toolBox->addItem(page_2, QString::fromUtf8("friend"));
        stackedWidget->addWidget(page_5);
        comboBox = new QComboBox(Widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(160, 360, 87, 22));
        btn_choose = new QPushButton(Widget);
        btn_choose->setObjectName(QString::fromUtf8("btn_choose"));
        btn_choose->setGeometry(QRect(160, 410, 93, 28));
        lbl_Image = new QLabel(Widget);
        lbl_Image->setObjectName(QString::fromUtf8("lbl_Image"));
        lbl_Image->setGeometry(QRect(370, 40, 201, 181));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 360, 123, 98));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        btn_ScrollArea = new QPushButton(widget);
        btn_ScrollArea->setObjectName(QString::fromUtf8("btn_ScrollArea"));

        verticalLayout_3->addWidget(btn_ScrollArea);

        btn_TabWidget = new QPushButton(widget);
        btn_TabWidget->setObjectName(QString::fromUtf8("btn_TabWidget"));

        verticalLayout_3->addWidget(btn_TabWidget);

        btnToolBox = new QPushButton(widget);
        btnToolBox->setObjectName(QString::fromUtf8("btnToolBox"));

        verticalLayout_3->addWidget(btnToolBox);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(1);
        tabWidget->setCurrentIndex(1);
        toolBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Widget", "baidu", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Widget", "shougou", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Widget", "google", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("Widget", "famil", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("Widget", "hhhh", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("Widget", "friend", nullptr));
        btn_choose->setText(QCoreApplication::translate("Widget", "choose ggg", nullptr));
        lbl_Image->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        btn_ScrollArea->setText(QCoreApplication::translate("Widget", "btn_ScrollArea", nullptr));
        btn_TabWidget->setText(QCoreApplication::translate("Widget", "btn_TabWidget", nullptr));
        btnToolBox->setText(QCoreApplication::translate("Widget", "btnToolBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
