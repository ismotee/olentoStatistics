#ifndef KAPPALEWIDGET_H
#define KAPPALEWIDGET_H

#include <QWidget>
#include <vector>
#include <QProgressBar>
#include "kappale.h"
#include "glwidget.h"
#include "oModificators.h"
#include "oPalette.h"

namespace Ui {
class kappaleWidget;
}



class kappaleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit kappaleWidget(QWidget *parent = 0);
    ~kappaleWidget();
    void setName (QString name);
    void setData (kappale& kpl);
    void showGL (bool on_off);
    void setMods(oModificators& mods);
    void setPalette (oPalette& palette);

private:
    std::vector<QProgressBar*> muotoBars;
    std::vector<QProgressBar*> kehoBars;
    Ui::kappaleWidget *ui;
    oModificators* mod_ptr;
    oPalette* palette_ptr;

};

#endif // KAPPALEWIDGET_H
