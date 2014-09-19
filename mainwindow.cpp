#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSize myIconSize(100,100);
    ui->mainToolBar->setIconSize(myIconSize);

    stackedWidget = new QStackedWidget(this);
    firstPage *firstPageWidget= new firstPage(this);
    secondPage *secondPageWidget= new secondPage(this);
    thirdPage *thirdPageWidget = new thirdPage(this);

    //////////////////////////////////////////////////////////
    //      Put firstPageWidget into a Scroll Area          //
    //////////////////////////////////////////////////////////
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(firstPageWidget);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    //////////////////////////////////////////////////////////////
    //  assigns pages to switch between to a QstackedWidget     //
    //////////////////////////////////////////////////////////////
    stackedWidget->addWidget(scrollArea);
    stackedWidget->addWidget(secondPageWidget);
    stackedWidget->addWidget(thirdPageWidget);

    ////////////////////////////////////////////////////////////
    //      Show First Page and Adjust size of MainWindow     //
    ////////////////////////////////////////////////////////////
    this->setCentralWidget(stackedWidget);
    adjusMainWindowFor_firstPage();

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

    adjusMainWindowFor_firstPage();

}

void MainWindow::on_actionPuls_triggered()
{
    stackedWidget->setCurrentIndex(1);
    this->setCentralWidget(stackedWidget);

    adjusMainWindowFor_secondPage();
}


void MainWindow::on_actionSettings_triggered()
{
    stackedWidget->setCurrentIndex(2);
    this->setCentralWidget(stackedWidget);

    adjusMainWindowFor_thirdPage();
}

void MainWindow::adjusMainWindowFor_firstPage(){

    QRect sizeMenuBar = this->menuBar()->geometry();
    int widthOfScrollBar = qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent);

    this->setFixedHeight(firstPageHeight+1.5*widthOfScrollBar+ sizeMenuBar.height());
    this->setMaximumWidth(firstPageWidth+1.5*widthOfScrollBar);
    this->resize(firstPageWidth+ 1.5*widthOfScrollBar,firstPageHeight+1.5*widthOfScrollBar+ sizeMenuBar.height());

}

void MainWindow::adjusMainWindowFor_secondPage(){

    QRect sizeMenuBar = this->menuBar()->geometry();
    QRect sizeMenuWidegt= this->menuWidget()->geometry();

    QRect sizeToolbar = ui->mainToolBar->geometry();
    QLayout * mLayout = stackedWidget->currentWidget()->layout();

    this->setFixedSize(mLayout->geometry().width(),
                       mLayout->geometry().height()+sizeMenuBar.height()+sizeMenuWidegt.height()+sizeToolbar.height());

}

void MainWindow::adjusMainWindowFor_thirdPage(){

    QRect sizeMenuBar = this->menuBar()->geometry();
    QRect sizeMenuWidegt= this->menuWidget()->geometry();

    QRect sizeToolbar = ui->mainToolBar->geometry();




    this->setFixedSize(thirdPageWidth,thirdPageHeight+sizeMenuBar.height()+sizeMenuWidegt.height()+sizeToolbar.height());
    this->resize(thirdPageWidth,thirdPageHeight+sizeMenuBar.height()+sizeMenuWidegt.height()+sizeToolbar.height());


}
