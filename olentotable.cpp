#include "olentotable.h"
#include "statistics.h"
#include <iostream>
#include <string>

void olentoTable::loadToList(QString path)
{
    //lukee kappaleet tiedostosta tableen
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cout << "Read error! \n";
        return;
    }
    while(!file.atEnd()) {

        QString str = file.readLine();
        QStringList strList = str.split(";", QString::SkipEmptyParts);
        std::vector<float> values;
        //std::cout << "values: " << strList.length() << "\n";
        for(int i = 0; i < strList.length();i++) {
            QString strr = (QString)strList.at(i);
            //td::cout << "[" << strr.toFloat() << "] ";
            values.push_back(strr.toFloat());
        }
        //std::cout << "\n";
        kappaleet.push_back(kappale(values));
    }
}

olentoTable::olentoTable(QString path)
{
    loadToList(path);
}


std::vector<kappale> olentoTable::getById (std::vector<int> idt)
{
    //Ottaa vektorin jossa jotkut indeksit tableen ja palauttaa vektorina vastaavat kappaleet
    std::vector<kappale> palautus;
    for(int i = 0; i < (int)idt.size();i++) {
       palautus.push_back(kappaleet.at(idt[i]));
    }
    return palautus;
}

kappale olentoTable::getById(int i) {
    return kappaleet.at(i);
}

std::vector<kappale*> olentoTable::getList() {
    std::vector<kappale*> palaute;
    for(int i=0; i<kappaleet.size(); i++)
        palaute.push_back(&kappaleet[i] );

    return palaute;

}

std::vector< std::vector<float> > olentoTable::haeKehoarvot() {
    //palauttaa kaikki kehoarvot vektorina
    std::vector< std::vector<float> > palaute;

    for(int i=0; i < kappaleet.size(); i++)
        palaute.push_back(kappaleet[i].kehollisuus );

    return palaute;
}

std::vector< std::vector<float> > olentoTable::haeMuotoarvot() {
    //palauttaa kaikki muotoarvot vektorina
    std::vector< std::vector<float> > palaute;

    for (int i=0; i<kappaleet.size(); i++)
        palaute.push_back(kappaleet[i].kehollisuus );

    return palaute;
}

std::vector<kappale> olentoTable::haeSamankehoisia(std::vector<float> kehoInput) {

    std::vector<kappale> palaute;
    std::vector<int> indexList = jarjestaEroavuudenMukaan(haeKehoarvot(), kehoInput); //palauttaa jÃ¤rjestetyn indeksilistan

    palaute = getById(indexList);

    return palaute;

}

std::vector<kappale> olentoTable::haeSamanmuotoisia(std::vector<float> muotoInput) {
    std::vector<kappale> palaute;
    std::vector<int> indexList = jarjestaEroavuudenMukaan(haeMuotoarvot(), muotoInput); //palauttaa jÃ¤rjestetyn indeksilistan

    palaute = getById(indexList);

    return palaute;
}


void olentoTable::writeTest(QString path) {

    std::vector<float> I;
    I.resize(7);

    std::vector<kappale> T = haeSamankehoisia(I);
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        std::cout << "Write error!\n";
    else {
        QTextStream out(&file);

        for(int i=0; i<T.size(); i++) {
        std::vector<float> values = T[i].kehollisuus;
        for(int j=0; j<values.size(); j++){
           out << values[j] << ";";
        }
         out << "\n";
       }
    }
}

