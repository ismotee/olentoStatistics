#include "mainwindow.h"
#include "olentotable.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    olentoTable T("/Users/ismotorvinen/olentoStatistics/shapeTable.txt");
    T.writeTest("/Users/ismotorvinen/olentoStatistics/sorted.txt");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
