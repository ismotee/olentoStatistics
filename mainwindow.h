#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "olentotable.h"
#include "kappaletablewidget.h"


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

    void on_inputSlider_valueChanged(int value);

    void on_inputSlider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;

    //Widget johon voi työntää dataa näytettäväksi
    kappaleTableWidget* kappaleTable;
};

#endif // MAINWINDOW_H
