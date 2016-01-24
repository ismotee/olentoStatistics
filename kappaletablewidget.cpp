#include "kappaletablewidget.h"
#include "ui_kappaletablewidget.h"
#include "kappalewidget.h"

kappaleTableWidget::kappaleTableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kappaleTableWidget)
{
    ui->setupUi(this);
    QGridLayout* layout = new QGridLayout(ui->scrollAreaWidgetContents);

    for(int i = 0; i < 500; i++) {
        kappaleWidget* kplW = new kappaleWidget(ui->scrollAreaWidgetContents);
        layout->addWidget(kplW,i,0,1,1);
        kplW->setName(QString::number(i));
        kplWidget.push_back(kplW);
    }


}

kappaleTableWidget::~kappaleTableWidget()
{
    delete ui;
}

void kappaleTableWidget::setData(std::vector<kappale> kappaleet)
{


}
