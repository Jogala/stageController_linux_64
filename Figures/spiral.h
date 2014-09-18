#pragma once
#include "figures.h"

namespace figures{
	//////////////////////////////
	//			spiral			//
	//////////////////////////////
	class spiral : public figures{
	private:
		stageController * pointerToE545;
        string storedValuesPath="./Stored_Values/spiral.txt";
        double itsValues[8];

//		double itsR, phi0, velocity;
//		int steps;
//		double rotAngleX, rotAngleZ;
//		int sectors;
//		double radiusRatio;

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

        void setValue(double RIn, double phi0In, double rotAngleXIn, double rotAngleZIn, int stepsIn, double velocityIn);

        void cutAbsMacroSpiral3D();

		spiral(stageController &E545){
			pointerToE545 = &E545;
		}
		spiral(){


		}

		~spiral(){

		}

	};
}
