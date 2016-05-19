#include "oPalette.h"
#include <iostream>

oPalette::oPalette()
{

}


QVector3D oPalette::GetColor(float id)
{
    id += 1;
    id /= 2;

    int index = id * palette.size();
    return palette[index];

}

void oPalette::Load(QString file)
{
    std::cerr << "loading palette form " << file.toStdString() << "\n";

    QImage paletteImage;
    paletteImage.load(file);

    for(int i = 0; i < paletteImage.width();i++)
    {
       QColor color(paletteImage.pixel(i,0));
       QVector3D color3D(color.redF(),color.greenF(),color.blueF());

       palette.push_back(color3D);
      // std::cerr << "color" << i << ":" << color.red() << color.green() << color.blue() << "\n";
    }

    std::cerr << "palette size:" << palette.size() << "\n";

}
