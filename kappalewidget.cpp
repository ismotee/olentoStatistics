#include "kappalewidget.h"
#include "ui_kappalewidget.h"
#include "glm/vec3.hpp"
#include <vector>


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

void kappaleWidget::setData(kappale& kpl) {

    showGL(false);

    for (int i = 0; i < (int)kpl.kehollisuus.size();i++) {
        float scaled = kpl.kehollisuus[i] * 100;
        kehoBars.at(i)->setValue((int)scaled);
    }

    for (int i = 0; i < (int)kpl.muoto.size();i++) {
        float scaled = kpl.muoto[i] * 100;
        muotoBars.at(i)->setValue((int)scaled);
    }
    std::vector<float> values = kpl.muoto;
    values.erase(values.begin() + 1);
    values.erase(values.begin() + 1);

    std::cerr << "values.size: " << values.size() << "\n";
    ui->widget->m_obj.vertices = mod_ptr->getShape(values);

    ui->eroavaisuus->setText(QString::number(kpl.eroavuus));

    showGL(true);
}

void kappaleWidget::showGL (bool on_off)
{
    if(on_off)
        ui->widget->show();
    else
        ui->widget->hide();
}

void kappaleWidget::setMods(oModificators &mods)
{
    mod_ptr = &mods;

}
