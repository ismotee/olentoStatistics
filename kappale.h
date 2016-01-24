#ifndef KAPPALE_H
#define KAPPALE_H

#include <vector>

enum KEHO {PAA,HARTIAT,RINTAKEHA,VATSA,SELKA,KADET,JALAT};
enum MUOTO{ARKKITYYPPI,VARI,MATERIAALI,YLOS,TAIPUVA,TWIST,PULLEA};


class kappale
{

public:

//costructor
    kappale(std::vector<float> kaikki_arvot);

//methods
    float kehollisuus (KEHO arvo);
    std::vector<float> kehollisuus ();
    float muoto (MUOTO arvo);
    std::vector<float> muoto ();
    void muoto (MUOTO id,float set);
    void kehollisuus (KEHO id, float set);
    void all (std::vector<float> kaikkiArvot);

protected:

private:
    std::vector<float> muotoList;
    std::vector<float> kehoList;
};

#endif // KAPPALE_H
