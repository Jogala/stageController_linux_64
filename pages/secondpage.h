#ifndef SECONDPAGE_H
#define SECONDPAGE_H

#include "GlobalVariables.h"
#include "stageController.h"
#include <QWidget>

namespace Ui {
class secondPage;
}

class secondPage : public QWidget
{
    Q_OBJECT

public:
    explicit secondPage(QWidget *parent = 0);
    ~secondPage();

private slots:
    void on_open_shutter_clicked();

    void on_close_shutter_clicked();

    void on_pulse_button_clicked();

private:
    Ui::secondPage *ui;

};

#endif // SECONDPAGE_H
