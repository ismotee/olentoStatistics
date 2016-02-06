#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "kappaletablewidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    kappaleTable = new kappaleTableWidget(ui->centralWidget);
    ui->horizontalLayout->addWidget(kappaleTable);
    olentoTable::loadToList("c:\\Users\\Omistaja\\Documents\\olentoStatistics\\shapeTable.txt");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inputSlider_valueChanged(int value)
{
    //Kokeillaan kappaleiden näyttämistä
    std::vector<float> input;
    float fvalue = (float)value / 100;
    for(int i=0; i<7; i++)
        input.push_back(fvalue);

    olentoTable::haeSamankehoisia(input);

    //tässä pitäisi antaa data widgetille
    kappaleTable->setData(olentoTable::haeKappaleet() );

}

void MainWindow::on_inputSlider_sliderMoved(int position)
{

}
