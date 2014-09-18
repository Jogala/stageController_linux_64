#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figures.h"

namespace figures
{

class rectangle : public figures
{
private:
    stageController * pointerToE545;
    double itsValues[6];

    string storedValuesPath = "./Stored_Values/rec.txt" ;
    
    //leaveOrSwap leaves a and b unchanged if -45<=phi<=45 or 135<=phi<=225
    //and adjusts phi
    void leaveOrSwapAndAdjustPhi(double &phi, double &a, double &b);
    
public:
    string getStoredValuesPath(){
        return storedValuesPath;
    }
    void setStoredValuesPath(string newstoredValuesPath ){
        storedValuesPath=newstoredValuesPath;
    }

    void cutAbs3D();

    void   setValue(int i, double value);
    double getValue(int i);

    void writeValuesToTextFile();
    void loadValuesFromTextFile();

    void printMemberVariables();


    rectangle(stageController &E545){
        
        pointerToE545 = &E545;
    }
    
    rectangle(){
    }
    ~rectangle(){}
    
};
}
#endif
