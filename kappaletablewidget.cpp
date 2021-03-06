#include "kappaletablewidget.h"
#include "ui_kappaletablewidget.h"
#include "kappalewidget.h"

const int MAX_WIDGETS = 10;



kappaleTableWidget::kappaleTableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kappaleTableWidget)

{
    std::string modDirs[4] = {"ylos","sivulle","ulos","kierteinen",};

    mods.initialize(QCoreApplication::applicationDirPath().toStdString() + "/meshes/","arkkityypit", std::vector<std::string> (&modDirs[0],&modDirs[4]) );

    palette.Load(QCoreApplication::applicationDirPath() + "/colors_8.png");

    ui->setupUi(this);
    QGridLayout* layout = new QGridLayout(ui->scrollAreaWidgetContents);

    for(int i = 0; i < MAX_WIDGETS; i++) {
        kappaleWidget* kplW = new kappaleWidget(ui->scrollAreaWidgetContents);
        layout->addWidget(kplW,i,0,1,1);
        kplW->setName(QString::number(i));
        kplW->setMods(mods);
        kplW->setPalette(palette);
        kplWidget.push_back(kplW);
    }
}

kappaleTableWidget::~kappaleTableWidget()
{
    delete ui;
}

void kappaleTableWidget::setData(std::vector<kappale> kappaleet)
{

    int size = kappaleet.size();
    if(size > MAX_WIDGETS) size = MAX_WIDGETS;

    for(int i = 0; i < size;i++) {
        kplWidget[i]->setData(kappaleet[i]);
    }
}

