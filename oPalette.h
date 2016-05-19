#ifndef OPALETTE_H
#define OPALETTE_H

#include <QImage>
#include <QVector3D>
#include <vector>
#include <QDebug>
#include <QColor>
#include <QRgb>

class oPalette
{

std::vector<QVector3D> palette;

public:
    oPalette();
    void Load(QString file);
    QVector3D GetColor(float id);
};

#endif // OPALETTE_H
