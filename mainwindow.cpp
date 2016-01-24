#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // toivottavasti toimii..
}

MainWindow::~MainWindow()
{
    delete ui;
}

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
