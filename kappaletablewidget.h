#ifndef KAPPALETABLEWIDGET_H
#define KAPPALETABLEWIDGET_H

#include <QWidget>
#include "kappalewidget.h"
#include "kappale.h"
#include <vector>
#include "oModificators.h"
#include <QCoreApplication>
#include "oPalette.h"


namespace Ui {
class kappaleTableWidget;
}

class kappaleTableWidget : public QWidget
{
    Q_OBJECT

public:
     explicit kappaleTableWidget(QWidget *parent = 0);
   //  kappaleTableWidget(QWidget *parent = 0, int num_obj);
    ~kappaleTableWidget();
    void setData(std::vector<kappale> kappaleet);
private:
    Ui::kappaleTableWidget *ui;
    std::vector<kappaleWidget*> kplWidget;
    oModificators mods;
    oPalette palette;
};

#endif // KAPPALETABLEWIDGET_H
