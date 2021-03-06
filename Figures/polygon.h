#ifndef POLYGON_H
#define POLYGON_H

#include "figures.h"

namespace figures
{

//////////////////////////////
//			polygon			//
//////////////////////////////
class polygon : public figures{

private:
    stageController * pointerToE545;
    string storedValuesPath="./Stored_Values/poly.txt";
    double itsValues[6];

    //        double itsR, phi0, velocity;
    //        int steps;
    //        double rotAngleX, rotAngleZ;

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

    void cutAbsViaMacro3D();

    polygon(stageController &E545){
        pointerToE545 = &E545;
    }

    polygon(){


    }

    ~polygon(){

    }

};

}






#endif // POLYGON_H
