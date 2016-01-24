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

void MainWindow::on_inputSlider_valueChanged(int value)
{

}

void MainWindow::on_inputSlider_sliderMoved(int position)
{

}
