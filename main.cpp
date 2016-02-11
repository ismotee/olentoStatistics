#include "mainwindow.h"
#include "olentotable.h"
#include <QApplication>
#include <vector>
#include <QDir>

int main(int argc, char *argv[])
{
    QString appDir = QDir::homePath();
    olentoTable::loadToList(appDir + "/olentoStatistics/shapeTable.txt");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
