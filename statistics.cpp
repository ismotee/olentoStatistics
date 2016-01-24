#include "statistics.h"
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool compare(const sort_T& lvalue, const sort_T& rvalue) {
    return (lvalue.key < rvalue.key);
}

float skalaarierotus(vector<float> A, vector<float> B) {
    //Kahden vektorin välinen eroavuus skalaarilukuna
    //Määritelmä: eroavuus on parametrien erotusten summa
    float palaute = 0;

    for(int i=0; i<A.size() && i < B.size(); i++)
        palaute += abs( A[i]-B[i] );

    return palaute;
}

vector<int> jarjestaEroavuudenMukaan(vector<vector<float> > aineisto, vector<float> vertailuarvo)
{
    //Järjestä pelkät indeksit eroavuuden mukaan
    vector<sort_T> S;

    for(int i=0; i<aineisto.size(); i++) {
        sort_T s;
        s.key = skalaarierotus(aineisto[i], vertailuarvo);
        s.value = i;
        S.push_back(s);
    }

    sort(S.begin(), S.end(), compare);

    //kopioi indeksit palautevektoriin ja palauta
    vector<int> palaute;
    for(int i=0; i<S.size(); i++)
        palaute.push_back(S[i].value);

    return palaute;
}
