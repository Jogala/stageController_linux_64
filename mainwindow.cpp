#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    firstPage *firstPageWidget= new firstPage(this);
//    secondPage *secondPageWidget= new secondPage(this);
//    thirdPage *thirdPageWidget = new thirdPage(this);
    stackedWidget = new QStackedWidget(this);

    stackedWidget->addWidget(firstPageWidget);
//    stackedWidget->addWidget(secondPageWidget);
//    stackedWidget->addWidget(thirdPageWidget);
    this->setCentralWidget(stackedWidget);


    QSize myIconSize(128,128);
    ui->mainToolBar->setIconSize(myIconSize);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionFigures_triggered()
{

}

void MainWindow::on_actionSettings_triggered()
{

}

void MainWindow::on_actionPuls_triggered()
{

}
