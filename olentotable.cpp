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
        std::cout << "Read error: " << path.toStdString() << "\n";
        return;
    }

    int jarjestys[14] = {0,3,2,4,5,6,1,7,8,9,10,11,12,13};

    while(!file.atEnd()) {

        QString str = file.readLine();
        QStringList strList = str.split(";", QString::SkipEmptyParts);
        std::vector<float> values;
       // std::cout << "values: " << strList.length() << "\n";



        for(int i = 0; i < strList.length();i++) {
            QString strr = (QString)strList.at(jarjestys[i]);
            //std::cout << "[" << strr.toFloat() << "] ";
            values.push_back(strr.toFloat());
        }
        //std::cout << "\n";
        kappaleet.push_back(kappale(values));
    }

    poistaHuonot();
}


void olentoTable::poistaHuonot() {
    //Poistetaan identtiset kappaleet, koska kappaleet ovat saattaneet kopioitua,
    //ja koska on epätodennäköistä että käyttäjät olisivat todella tehneet identtisiä kappaleita.

    //Poistetaan myös sellaiset kappaleet, joiden muoto on täsmälleen sama kuin kehonkuva,
    //koska luultavimmin silloin käyttäjä ei ole antanut mitään kehonkuvaa.
    //Pelkällä muototiedolla ei tehdä mitään.

    //Tyhjennetään "kappaleet" ja lisätään takaisin vain hyvät
    std::vector<kappale> kaikki = kappaleet;
    kappaleet.clear();

    for(int i=0; i<kaikki.size(); i++) {
        //Lisää kappaleisiin, jos muoto ja kehollisuus eivät ole samat, ja jos samanlaista ei ole vielä kappaleissa
        if(kaikki[i].muoto != kaikki[i].kehollisuus) {
            bool alreadyAdded = false;
            for(int j=0; j < kappaleet.size() && alreadyAdded == false; j++) {
                if(kaikki[i] == kappaleet[j] ) {
                    alreadyAdded = true;
                }
            }
            if(alreadyAdded == false) {
                //lisää kappaleisiin
                kappaleet.push_back(kaikki[i]);
                //kaikki[i].kerro();
            }
        }
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

