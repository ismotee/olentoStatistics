#ifndef OLENTOTABLE_H
#define OLENTOTABLE_H

#include <QFile>
#include <QStringList>
#include <QString>
#include <QTextStream>
#include "kappale.h"
#include <vector>

class olentoTable
{
private:
    void loadToList(QString path);
public:
    olentoTable(QString path);
    std::vector<kappale> kappaleet;
    std::vector<kappale> getById (std::vector<int> idt);
    kappale getById (int);
    std::vector<kappale*> getList();
    std::vector< std::vector<float> > haeKehoarvot();
    std::vector< std::vector<float> > haeMuotoarvot();
    std::vector<kappale> haeSamankehoisia(std::vector<float> kehoInput);
    std::vector<kappale> haeSamanmuotoisia(std::vector<float> muotoInput);

    void writeTest(QString path);
};

#endif // OLENTOTABLE_H
