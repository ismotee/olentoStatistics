#ifndef KAPPALEWIDGET_H
#define KAPPALEWIDGET_H

#include <QWidget>

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

private:
    Ui::kappaleWidget *ui;
};

#endif // KAPPALEWIDGET_H
