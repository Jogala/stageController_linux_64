#ifndef THIRDPAGE_H
#define THIRDPAGE_H

#include "stageController.h"
#include <QWidget>

namespace Ui {
class thirdPage;
}

class thirdPage : public QWidget
{
    Q_OBJECT

public:
    explicit thirdPage( QWidget *parent = 0);
    ~thirdPage();

private:
    Ui::thirdPage *ui;

};

#endif // THIRDPAGE_H
