#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    firstPage *firstPageWidget= new firstPage(this);
    secondPage *secondPageWidget= new secondPage(this);
    thirdPage *thirdPageWidget = new thirdPage(this);
    stackedWidget = new QStackedWidget(this);

    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(firstPageWidget);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCentralWidget(scrollArea);

    stackedWidget->addWidget(scrollArea);
    stackedWidget->addWidget(secondPageWidget);
    stackedWidget->addWidget(thirdPageWidget);
    this->setCentralWidget(stackedWidget);


    QSize myIconSize(128,128);
    ui->mainToolBar->setIconSize(myIconSize);

    recMenuBar=this->menuBar()->geometry();
    int widthOfScrollBar = qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent);
    this->resize(firstPageWidth+1.5*widthOfScrollBar,firstPageHeight+1.5*widthOfScrollBar+ recMenuBar.height());
    this->setMinimumHeight(firstPageHeight+1.5*widthOfScrollBar+ recMenuBar.height());
    this->setMaximumWidth(firstPageWidth+1.5*widthOfScrollBar);





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionFigures_triggered()
{
    stackedWidget->setCurrentIndex(0);
    this->setCentralWidget(stackedWidget);
    gE545.moveTo(100,100,100);

    int widthOfScrollBar = qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent);
    this->resize(firstPageWidth+1.5*widthOfScrollBar,firstPageHeight+1.5*widthOfScrollBar+ recMenuBar.height());
    this->setMinimumHeight(firstPageHeight+1.5*widthOfScrollBar+ recMenuBar.height());
    this->setMaximumWidth(firstPageWidth+1.5*widthOfScrollBar);

}

void MainWindow::on_actionPuls_triggered()
{
    stackedWidget->setCurrentIndex(1);
    this->setCentralWidget(stackedWidget);

}


void MainWindow::on_actionSettings_triggered()
{
    stackedWidget->setCurrentIndex(2);
    this->setCentralWidget(stackedWidget);
}
