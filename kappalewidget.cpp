#include "kappalewidget.h"
#include "ui_kappalewidget.h"

kappaleWidget::kappaleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kappaleWidget)
{
    ui->setupUi(this);
}

kappaleWidget::~kappaleWidget()
{
    delete ui;
}

void kappaleWidget::setName(QString name)
{
    ui->label->setText(name);

}
