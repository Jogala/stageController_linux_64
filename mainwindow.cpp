#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
