/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QToolButton *toolButton;
    QGroupBox *groupBox;
    QRadioButton *rBtnWoman;
    QRadioButton *rBtnMan;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *cBox;
    QListWidget *listWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 93, 28));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(-10, 70, 121, 81));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);
        toolButton->setIconSize(QSize(32, 32));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton->setAutoRaise(true);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 360, 120, 80));
        rBtnWoman = new QRadioButton(groupBox);
        rBtnWoman->setObjectName(QString::fromUtf8("rBtnWoman"));
        rBtnWoman->setGeometry(QRect(10, 50, 115, 19));
        rBtnMan = new QRadioButton(groupBox);
        rBtnMan->setObjectName(QString::fromUtf8("rBtnMan"));
        rBtnMan->setGeometry(QRect(10, 20, 115, 19));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 250, 120, 80));
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 20, 115, 19));
        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(10, 50, 115, 19));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(350, 40, 111, 129));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        verticalLayout->addWidget(checkBox_3);

        cBox = new QCheckBox(groupBox_3);
        cBox->setObjectName(QString::fromUtf8("cBox"));

        verticalLayout->addWidget(cBox);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(170, 210, 256, 192));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "\345\223\210\345\223\210\345\223\210", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\200\247\345\210\253", nullptr));
        rBtnWoman->setText(QCoreApplication::translate("MainWindow", "\345\245\263", nullptr));
        rBtnMan->setText(QCoreApplication::translate("MainWindow", "\347\224\267", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\345\251\232\345\220\246", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "\345\267\262\345\251\232", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "\346\234\252\345\251\232", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\351\227\256\345\215\267\350\260\203\346\237\245", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\344\273\267\346\240\274\344\274\230\346\203\240", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "\345\217\243\346\204\237\345\245\275", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\210\260\344\275\215", nullptr));
        cBox->setText(QCoreApplication::translate("MainWindow", "\350\200\201\346\235\277\345\250\230\345\245\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
