#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "kappaletablewidget.h"
#include "window.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    kappaleTable = new kappaleTableWidget(ui->centralWidget);

    ui->horizontalLayout->addWidget(kappaleTable);

   // QMenuBar *menuBar = new QMenuBar;
   // QMenu *menuWindow = menuBar->addMenu(tr("&Window"));
   // QAction *addNew = new QAction(menuWindow);
   // addNew->setText(tr("Add new"));
   // menuWindow->addAction(addNew);
   // connect(addNew, &QAction::triggered, this, &MainWindow::onAddNew);
   // setMenuBar(menuBar);

   // onAddNew();

    inputValues.resize(7);
}

void MainWindow::onAddNew()
{
  //  if (!centralWidget())
      kappaleTable->layout()->addWidget(new GLWidget(kappaleTable));
  //  else
  //      qDebug() << "Cannot add new window" << "Already occupied. Undock first.";
}


MainWindow::~MainWindow()
{
    delete kappaleTable;
    delete ui;
}


//----------------------------------SLIDERIT-----------------------------------------

void MainWindow::sliderValueChangedRoutine (int id, int value) {
    //Kokeillaan kappaleiden näyttämistä
    float fvalue = (float)value / 100;
        inputValues[id] = fvalue;

    olentoTable::haeSamankehoisia(inputValues);
    //tässä pitäisi antaa data widgetille
    kappaleTable->setData(olentoTable::haeKappaleet() );
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
