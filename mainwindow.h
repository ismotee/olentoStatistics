#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "olentotable.h"
#include "kappaletablewidget.h"
#include "glwidget.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_paaSlider_valueChanged(int value);

    void on_hartiatSlider_valueChanged(int value);

    void on_rintakehaSlider_valueChanged(int value);

    void on_vatsaSlider_valueChanged(int value);

    void on_selkaSlider_valueChanged(int value);

    void on_kadetSlider_valueChanged(int value);

    void on_jalatSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    void onAddNew();

    //Widget johon voi työntää dataa näytettäväksi
    kappaleTableWidget* kappaleTable;
    dObject obj;

    //Input sliderien arvot
    std::vector<float> inputValues;
    void sliderValueChangedRoutine (int id, int value);
};

#endif // MAINWINDOW_H
