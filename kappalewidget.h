#ifndef KAPPALEWIDGET_H
#define KAPPALEWIDGET_H

#include <QWidget>
#include <vector>
#include <QProgressBar>
#include "kappale.h"

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
    void setData (kappale kpl);

private:
    std::vector<QProgressBar*> muotoBars;
    std::vector<QProgressBar*> kehoBars;
    Ui::kappaleWidget *ui;
};

#endif // KAPPALEWIDGET_H
