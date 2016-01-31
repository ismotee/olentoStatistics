#include "kappale.h"

kappale::kappale(std::vector<float> kaikkiArvot)
{
    all(kaikkiArvot);

}

float kappale::kehollisuus (KEHO arvo)
{
    return kehoList[arvo];
}

std::vector<float> kappale::kehollisuus ()
{
    // Tyhmä kommentti LÖYTYI!!!!
    return kehoList;
}

float kappale::muoto (MUOTO arvo)
{
    return muotoList[arvo];
}

std::vector<float> kappale::muoto ()
{
    return muotoList;
}

void kappale::muoto (MUOTO id, float set)
{
     muotoList[id] = set;
}

void kappale::kehollisuus (KEHO id, float set)
{
    kehoList[id] = set;
}

void kappale::all (std::vector<float> kaikkiArvot)
{
    muotoList.insert(muotoList.begin(), kaikkiArvot.begin(),kaikkiArvot.begin() + 6);
    kehoList.insert(kehoList.begin(), kaikkiArvot.begin() + 7,kaikkiArvot.end());

}
