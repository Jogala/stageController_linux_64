#-------------------------------------------------
#
# Project created by QtCreator 2014-09-18T19:38:17
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = stageController
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    stageController.cpp \
    usefulFunctions.cpp \
    GlobalVariables.cpp \
    Figures/line.cpp \
    Figures/polygon.cpp \
    Figures/rectangle.cpp \
    Figures/spiral.cpp \
    Figures/surfaceRec.cpp \
    pages/firstpage.cpp

HEADERS  += mainwindow.h \
    stageController.h \
    usefulFunctions.h \
    Header.h \
    GlobalVariables.h \
    Figures/figures.h \
    Figures/line.h \
    Figures/polygon.h \
    Figures/rectangle.h \
    Figures/spiral.h \
    pages/firstpage.h

FORMS    += mainwindow.ui \
    pages/firstpage.ui

INCLUDEPATH += $$PWD/Eigen_Linear_Algebra_Library\

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/PI_stuff/release/ -lpi_pi_gcs2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/PI_stuff/debug/ -lpi_pi_gcs2
else:unix: LIBS += -L$$PWD/PI_stuff/ -lpi_pi_gcs2

INCLUDEPATH += $$PWD/PI_stuff
DEPENDPATH += $$PWD/PI_stuff

RESOURCES += \
    Resources.qrc
