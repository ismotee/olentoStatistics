#include "kappalewidget.h"
#include "ui_kappalewidget.h"

kappaleWidget::kappaleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kappaleWidget)
{
    ui->setupUi(this);

    //muotobarit
    muotoBars.push_back(ui->arkkityyppiBar);
    muotoBars.push_back(ui->variBar);
    muotoBars.push_back(ui->materiaaliBar);
    muotoBars.push_back(ui->ylosBar);
    muotoBars.push_back(ui->taipuvaBar);
    muotoBars.push_back(ui->twistBar);
    muotoBars.push_back(ui->pulleaBar);

    //kehollisuusbarit
    kehoBars.push_back(ui->paaBar);
    kehoBars.push_back(ui->hartiatBar);
    kehoBars.push_back(ui->rintakehaBar);
    kehoBars.push_back(ui->vatsaBar);
    kehoBars.push_back(ui->selkaBar);
    kehoBars.push_back(ui->kadetBar);
    kehoBars.push_back(ui->jalatBar);

}

kappaleWidget::~kappaleWidget()
{
    delete ui;    
}

void kappaleWidget::setName(QString name)
{
    ui->label->setText(name);

}

void kappaleWidget::setData(kappale kpl) {

    for (int i = 0; i < kpl.kehollisuus.size();i++) {
        float scaled = kpl.kehollisuus[i] * 100;
        kehoBars.at(i)->setValue((int)scaled);
    }

    for (int i = 0; i < kpl.muoto.size();i++) {
        float scaled = kpl.muoto[i] * 100;
        muotoBars.at(i)->setValue((int)scaled);
    }

    ui->eroavaisuus->setText(QString::number(kpl.eroavuus));

}
