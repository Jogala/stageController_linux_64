#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QTableWidget>
#include <QLabel>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>
#include <QAbstractTextDocumentLayout>
#include <QHeaderView>
#include <QLineEdit>
#include <QAbstractSpinBox>
#include <QTextEdit>
#include <QDoubleSpinBox>
#include <QScrollArea>
#include <QShortcut>
#include <QKeySequence>
#include <QStackedWidget>
#include <QComboBox>
#include <QVBoxLayout>
#include <QAction>
#include <QWidgetAction>

//#include "pages/firstpage.h"
//#include "pages/secondpage.h"
//#include "pages/thirdpage.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:



    void on_actionFigures_triggered();

    void on_actionSettings_triggered();

    void on_actionPuls_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
