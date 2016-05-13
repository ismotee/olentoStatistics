#include "mainwindow.h"
#include "olentotable.h"
#include <QApplication>
#include <vector>
#include <QDir>
#include <QSurfaceFormat>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString appDir = QCoreApplication::applicationDirPath();
    olentoTable::loadToList(appDir + "/shapeTable.txt");

    QSurfaceFormat fmt;
    fmt.setDepthBufferSize(24);
    if (QCoreApplication::arguments().contains(QStringLiteral("--multisample")))
        fmt.setSamples(4);
    //if (QCoreApplication::arguments().contains(QStringLiteral("--coreprofile"))) {
        fmt.setVersion(3, 3);
        fmt.setProfile(QSurfaceFormat::CoreProfile);
   // }
    QSurfaceFormat::setDefaultFormat(fmt);




    MainWindow w;
    w.show();

    return a.exec();
}
