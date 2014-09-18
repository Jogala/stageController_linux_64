#ifndef FIRSTPAGE_H
#define FIRSTPAGE_H

#include <QWidget>
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
#include "QDoubleSpinBox"
#include <QScrollArea>
#include <QShortcut>
#include <QKeySequence>
#include <QStackedWidget>
#include <QComboBox>

#include "GlobalVariables.h"

namespace Ui {
class firstPage;
}

class firstPage : public QWidget
{
    Q_OBJECT

public:

    explicit firstPage(QWidget *parent = 0);
    ~firstPage();

private slots:

    void on_rec_set_clicked();

    void on_poly_set_clicked();

    void on_spiral_set_clicked();

    void on_line_set_clicked();

    void on_line_cut_clicked();

    void on_rec_cut_clicked();

    void on_poly_cut_clicked();

    void on_spiral_cut_clicked();

    void setFocus_lineTable();
    void setFocus_recTable();
    void setFocus_polyTable();
    void setFocus_spiralTable();

private:
    Ui::firstPage *ui;

    QTableWidget * recTable;
    QTableWidget * polyTable;
    QTableWidget * spiralTable;
    QTableWidget * lineTable;

    //figures
    figures::rectangle  mRectangle{gE545};
    figures::polygon    mPoly{gE545};
    figures::spiral     mSpiral{gE545};
    figures::line       mLine{gE545};

    int cWidth = 10;
    double veloMax=9900;
    double maxA=195;
    void setUp_RecTable();
    void setUp_LineTable();
    void setUp_PolyTable();
    void setUp_SpiralTable();

    void setShortcuts();
};

#endif // FIRSTPAGE_H
