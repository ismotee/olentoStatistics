#include "olentotable.h"
//#include "statistics.h"
#include <iostream>
#include <string>
#include <algorithm>


//aineisto: kappaleet järjestettynä listaan
std::vector<kappale> kappaleet;


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


void olentoTable::jarjesta() {
    //Vertailee kappaleiden eroavuuslukuja, jotka on asetettu muualla
    sort(kappaleet.begin(), kappaleet.end(), vertaaEroavuutta );
}


/*olentoTable::olentoTable(QString path)
{
    loadToList(path);
}*/


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

std::vector<kappale> olentoTable::haeKappaleet() {
    return kappaleet;
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

void olentoTable::haeSamankehoisia(std::vector<float> input) {
    //Määritä kappaleiden kehollisuuden eroavuus annettuun syötteeseen
    for(int i=0; i<kappaleet.size(); i++)
        kappaleet[i].laskeKehonEroavuus(input);

    //Järjestä eroavuuden perusteella
    jarjesta();

}

void olentoTable::haeSamanmuotoisia(std::vector<float> input) {
    //Määritä kappaleiden kehollisuuden eroavuus annettuun syötteeseen
    for(int i=0; i<kappaleet.size(); i++)
        kappaleet[i].laskeMuodonEroavuus(input);

    //Järjestä eroavuuden perusteella
    jarjesta();
}


void olentoTable::writeTest(QString path) {

}

