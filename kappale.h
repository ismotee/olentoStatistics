#ifndef KAPPALE_H
#define KAPPALE_H

#include <vector>

enum KEHO {PAA,HARTIAT,RINTAKEHA,VATSA,SELKA,KADET,JALAT};
enum MUOTO{ARKKITYYPPI,VARI,MATERIAALI,YLOS,TAIPUVA,TWIST,PULLEA};

struct kappale {
    std::vector<float> kehollisuus;
    std::vector<float> muoto;

    //Eroavuus asetetaan muodon tai kehollisuuden mukaan tarvittaessa kappaleiden järjestämiseksi
    float eroavuus;

    kappale (std::vector<float> kaikkiArvot);

    float laskeMuodonEroavuus(std::vector<float> vertailu); //asettaa ja palauttaa eroavuuden
    float laskeKehonEroavuus(std::vector<float> vertailu);

    bool operator==(const kappale& rvalue);
    void kerro();
};


bool vertaaEroavuutta(const kappale& A, const kappale& B);  //palauttaa TRUEn, jos A:n eroavuus on B:n eroavuutta suurempi; FALSE muuten.

#endif // KAPPALE_H
