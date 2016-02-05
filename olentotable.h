#ifndef OLENTOTABLE_H
#define OLENTOTABLE_H

#include <QFile>
#include <QStringList>
#include <QString>
#include <QTextStream>
#include "kappale.h"
#include <vector>

namespace olentoTable{

    //lataa kappaleet tiedostosta
    void loadToList(QString path);

    //Järjestä kappaleet eroavuuden mukaan. Kappaleiden eroavuusarvot asetetaan muualla; tämä vain suorittaa järjestämisen.
    void jarjesta();

    //konstruktori: lataa kappaleet tiedostosta listaan
    //olentoTable(QString path);

    //hakufunktiot: kappaleiden ja niiden arvojen hakeminen listasta
    std::vector<kappale> getById (std::vector<int> idt);
    kappale getById (int);

    std::vector<kappale> haeKappaleet(); //hakee koko listan
    std::vector< std::vector<float> > haeKehoarvot();
    std::vector< std::vector<float> > haeMuotoarvot();

    //Järjestä lista kehon/muodon perusteella
    void haeSamankehoisia(std::vector<float> input);
    void haeSamanmuotoisia(std::vector<float> input);

    //Kirjoita kokeeksi kappaleiden tietoja tiedostoon
    void writeTest(QString path);
};

#endif // OLENTOTABLE_H
