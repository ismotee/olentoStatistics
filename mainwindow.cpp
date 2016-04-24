#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "kappaletablewidget.h"
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    kappaleTable = new kappaleTableWidget(ui->centralWidget);
    olentoWidget = new GLWidget(ui->centralWidget);

    ui->horizontalLayout->addWidget(kappaleTable);
    ui->horizontalLayout->addWidget(olentoWidget);


    inputValues.resize(7);
}

MainWindow::~MainWindow()
{
    delete olentoWidget;
    delete kappaleTable;
    delete ui;
}


//----------------------------------SLIDERIT-----------------------------------------

void MainWindow::sliderValueChangedRoutine (int id, int value) {
    //Kokeillaan kappaleiden näyttämistä
    float fvalue = (float)value / 100;
        inputValues[id] = fvalue;

        olentoWidget->hide();
    olentoTable::haeSamankehoisia(inputValues);
    //tässä pitäisi antaa data widgetille
    kappaleTable->setData(olentoTable::haeKappaleet() );
    olentoWidget->show();
}

void MainWindow::on_paaSlider_valueChanged(int value)
{
    sliderValueChangedRoutine(0, value);
}

void MainWindow::on_hartiatSlider_valueChanged(int value)
{
    sliderValueChangedRoutine(1, value);
}

void MainWindow::on_rintakehaSlider_valueChanged(int value)
{
    sliderValueChangedRoutine(2, value);
}

void MainWindow::on_vatsaSlider_valueChanged(int value)
{
    sliderValueChangedRoutine(3, value);
}

void MainWindow::on_selkaSlider_valueChanged(int value)
{
    sliderValueChangedRoutine(4, value);
}

void MainWindow::on_kadetSlider_valueChanged(int value)
{
    sliderValueChangedRoutine(5, value);
}

void MainWindow::on_jalatSlider_valueChanged(int value)
{
    sliderValueChangedRoutine(6, value);
}
