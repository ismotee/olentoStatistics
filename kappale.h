#ifndef KAPPALE_H
#define KAPPALE_H

#include <vector>

enum KEHO {PAA,HARTIAT,RINTAKEHA,VATSA,SELKA,KADET,JALAT};
enum MUOTO{ARKKITYYPPI,VARI,MATERIAALI,YLOS,TAIPUVA,TWIST,PULLEA};

struct kappale {
    kappale (std::vector<float> kaikkiArvot) {
        muoto.insert(muoto.begin(), kaikkiArvot.begin(),kaikkiArvot.begin() + 6);
        kehollisuus.insert(kehollisuus.begin(), kaikkiArvot.begin() + 7,kaikkiArvot.end());
    }
    std::vector<float> kehollisuus;
    std::vector<float> muoto;
    float eroavuus;
};

#endif // KAPPALE_H
