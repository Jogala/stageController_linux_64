#include "secondpage.h"
#include "ui_secondpage.h"

secondPage::secondPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::secondPage)
{
    ui->setupUi(this);
}

secondPage::~secondPage()
{
    delete ui;
}

void secondPage::on_open_shutter_clicked()
{
    gE545.openShutter();
}


void secondPage::on_close_shutter_clicked()
{
    gE545.closeShutter();
}


void secondPage::on_pulse_button_clicked()
{
   double T = ui->T_spinBox->value();

}
