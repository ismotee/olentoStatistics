#ifndef STATISTICS_H
#define STATISTICS_H

#include "kappale.h"
#include <vector>

struct sort_T{
    float key;
    float value;
};


std::vector<int> jarjestaEroavuudenMukaan(std::vector<std::vector<float> > aineisto, std::vector<float> vertailuarvo);

#endif // STATISTICS_H
