#include "mainwindow.h"
#include "olentotable.h"
#include <QApplication>
#include <vector>

int main(int argc, char *argv[])
{
    olentoTable::loadToList("shapeTable.txt");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
