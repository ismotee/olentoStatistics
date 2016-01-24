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
    QFile file;
    void loadToList();

public:
    olentoTable(QString path);
    std::vector<kappale> kappaleet;
    std::vector<kappale> haeKappaleet (std::vector<int> idt);
};

#endif // OLENTOTABLE_H
