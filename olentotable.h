#ifndef OLENTOTABLE_H
#define OLENTOTABLE_H

#include <QFile>
#include <QList>
#include <QString>
#include <QTextStream>

class olentoTable
{
private:
    QFile file;
    QList<float> muoto;
    QList<float> keho;

public:
    olentoTable(QString path);
};

#endif // OLENTOTABLE_H
