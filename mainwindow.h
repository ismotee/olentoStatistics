#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "olentotable.h"


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
<<<<<<< HEAD

=======
    void on_inputSlider_valueChanged(int value);

    void on_inputSlider_sliderMoved(int position);
>>>>>>> cf923c9699eeb43d0578769b6cf7185aca1273d0

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
