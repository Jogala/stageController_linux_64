#include "thirdpage.h"
#include "ui_thirdpage.h"

thirdPage::thirdPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::thirdPage)
{
    ui->setupUi(this);
}

thirdPage::~thirdPage()
{
    delete ui;
}
