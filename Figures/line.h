#ifndef LINE_H
#define LINE_H

#include "figures.h"

namespace figures
{

class line : public figures
{
private:
    stageController * pointerToE545;
    string storedValuesPath="./Stored_Values/line.txt";
    double itsValues[5];

//    double l, phi, velocity, theta;
//    int repetitions;

public:

    void setStoredValuesPath(string newstoredValuesPath ){
        storedValuesPath=newstoredValuesPath;
    }
    string getStoredValuesPath(){
        return storedValuesPath;
    }

    void loadValuesFromTextFile();
    void writeValuesToTextFile();

    void setValue(int i, double value);
    double getValue(int i);

    void printMemberVariables();

    void cutRel3D();
    void cutAbs3D();
    void cutAbsLim3D();

    line(stageController &E545){

        pointerToE545 = &E545;

    }
    //Default constructor is needed! Because I am using line as a member of a class see
    //http://stackoverflow.com/questions/9802341/constructor-and-initialization-of-custom-classes-objects
    line(){

    }
    ~line(){}

};
}
#endif // LINE_H
