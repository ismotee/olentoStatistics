#include "kappale.h"
#include <cmath>
#include <algorithm>
#include <iostream>

float fabs(float x) {
    if(x<0) return -x;
    else return x;
}


kappale::kappale (std::vector<float> kaikkiArvot) {
    muoto.insert(muoto.begin(), kaikkiArvot.begin(),kaikkiArvot.begin() + 6);
    kehollisuus.insert(kehollisuus.begin(), kaikkiArvot.begin() + 7,kaikkiArvot.end());
    eroavuus = -1;
}


float laskeEroavuus(std::vector<float> aineisto, std::vector<float> vertailu) {
    //eroavuus on parametrien erotusten summa.

    if(vertailu.size() != 7 || aineisto.size() != 7) {
        //Ei voida vertailla: vektorit ovat väärän kokoiset!
        std::cout << vertailu.size() << " ; " << aineisto.size() << "\n";
        return -1;
    }

    float summa = 0;

    for(int i=0; i<7; i++)
        summa += fabs(aineisto[i] - vertailu[i]);

    return summa;
}


float kappale::laskeKehonEroavuus(std::vector<float> vertailu) {
    //asettaa kappaleen eroavuusluvun kehoparametrien vertailun mukaan
    eroavuus = laskeEroavuus(kehollisuus, vertailu);
    return eroavuus;
}


float kappale::laskeMuodonEroavuus(std::vector<float> vertailu) {
    //asettaa kappaleen eroavuusluvun muotoparametrien vertailun mukaan
    eroavuus = laskeEroavuus(muoto, vertailu);
    return eroavuus;
}


bool vertaaEroavuutta(const kappale& A, const kappale& B) {
    //palauttaa TRUE, jos A:n eroavuus on B:n eroavuutta suurempi
    return (A.eroavuus < B.eroavuus);
}
