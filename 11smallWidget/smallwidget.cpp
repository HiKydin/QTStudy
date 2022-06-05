#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);

    //QSpinBox移动 QSlider跟着移动
    void(QSpinBox:: * spSingnal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox,spSingnal,ui->horizontalSlider,&QSlider::setValue);

    //QSlider移动 QSpinBox跟着移动
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}

SmallWidget::~SmallWidget()
{
    delete ui;
}

//设置数值
void SmallWidget::setNum(int num)
{
    ui->spinBox->setValue(num);
}
//获取数值
int SmallWidget::getNum()
{
    return ui->spinBox->value();
}
