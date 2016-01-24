#include "olentotable.h"


olentoTable::olentoTable(QString path) : file(path)
{
    //TODO: file doesn't exist check

  //if(!file.open(QIODevice::ReadOnly));

    file.open(QIODevice::ReadOnly);
    loadToList();
}

void olentoTable::loadToList()
{
    while(!file.atEnd()) {

        QString str = file.readLine();
        QStringList strList = str.split(";");
        std::vector<float> values;
        for(int i = 0; i < strList.length();i++) {
            QString strr = (QString)strList.at(i);
            values.push_back(strr.toFloat());
        }
        kappaleet.push_back(values);
    }
}

std::vector<kappale> olentoTable::haeKappaleet (std::vector<int> idt)
{
    std::vector<kappale> palautus;
    for(int i = 0; i < idt.size();i++) {
       palautus.push_back(kappaleet.at(idt[i]));
    }
    return palautus;
}
