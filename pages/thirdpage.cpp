#include "thirdpage.h"
#include "ui_thirdpage.h"
#include <QTime>

thirdPage::thirdPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::thirdPage)
{
    ui->setupUi(this);

    for(auto item : tare){
        item = 0;
    }


    ui->delayFactor_SpinBox->setValue(::macroDelayFactor);

    ui->x_pos->setReadOnly(true);
    ui->y_pos->setReadOnly(true);

    ui->x_pos->setMinimum(-200);
    ui->x_pos->setMaximum(200);

    ui->y_pos->setMinimum(-200);
    ui->y_pos->setMaximum(200);

    ui->vel_spinBox->setMinimum(0);
    ui->vel_spinBox->setMaximum(9900);

    ui->stepSize_spinBox->setMinimum(0);
    ui->stepSize_spinBox->setMaximum(50);

    gE545.getPositon(pos);
    ui->x_pos->setValue(pos[0]);
    ui->y_pos->setValue(pos[1]);


    gE545.setVelocity(vel,vel,vel);
    ui->up_button->setAutoRepeat(true);
    ui->down_button->setAutoRepeat(true);
    ui->right_button->setAutoRepeat(true);
    ui->left_button->setAutoRepeat(true);

    gE545.getFocusValues(focus);

    ui->deltaX_spinBox->setValue(focus[0]);
    ui->deltaY_spinBox->setValue(focus[1]);
    ui->stepSize_spinBox->setValue(stepSize);
    ui->vel_spinBox->setValue(vel);

    //this->setLayout(ui->gridLayout_2);
}

thirdPage::~thirdPage()
{
    delete ui;
}


void thirdPage::on_up_button_pressed()
{

    gE545.move(0,stepSize,0);

    gE545.getPositon(pos);
    ui->x_pos->setValue(pos[0]-tare[0]);
    ui->y_pos->setValue(pos[1]-tare[1]);

}

void thirdPage::on_down_button_pressed()
{

    gE545.move(0,-stepSize,0);

   gE545.getPositon(pos);

   ui->x_pos->setValue(pos[0]-tare[0]);
   ui->y_pos->setValue(pos[1]-tare[1]);

}

void thirdPage::on_left_button_pressed()
{

    gE545.move(-stepSize,0,0);

   gE545.getPositon(pos);
   ui->x_pos->setValue(pos[0]-tare[0]);
   ui->y_pos->setValue(pos[1]-tare[1]);


}

void thirdPage::on_right_button_pressed()
{

    gE545.move(stepSize,0,0);

   gE545.getPositon(pos);
   ui->x_pos->setValue(pos[0]-tare[0]);
   ui->y_pos->setValue(pos[1]-tare[1]);

}

void thirdPage::on_set_focus_values_clicked()
{

    gE545.setFocus_and_writeValuesToFile( ui->deltaX_spinBox->value(),ui->deltaY_spinBox->value(),0);

}

void thirdPage::on_stepSize_spinBox_valueChanged(double arg1)
{
    stepSize= ui->stepSize_spinBox->value();
}


void thirdPage::on_vel_spinBox_valueChanged(double arg1)
{
    vel = ui->vel_spinBox->value();
}

void thirdPage::on_pushButton_clicked()
{
    gE545.getPositon(pos);

    for(int i = 0; i<3;i++){
        tare[i]=pos[i];
    }

}



void thirdPage::on_delayFactor_SpinBox_valueChanged(double arg1)
{
    ::macroDelayFactor=ui->delayFactor_SpinBox->value();
}
