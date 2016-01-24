#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "kappaletablewidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    kappaleTableWidget* kplTable = new kappaleTableWidget(ui->centralWidget);
    ui->horizontalLayout->addWidget(kplTable);

    // toivottavasti toimii..
}

MainWindow::~MainWindow()
{
    delete ui;
}

<<<<<<< HEAD
=======
void MainWindow::on_inputSlider_valueChanged(int value)
{
    ui->progressBar->setValue(value);
    ui->progressBar->update();
}

void MainWindow::on_inputSlider_sliderMoved(int position)
{
    ui->progressBar->setValue(position);
    ui->progressBar->update();
}
>>>>>>> cf923c9699eeb43d0578769b6cf7185aca1273d0
