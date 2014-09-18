#include "rectangle.h"


void    figures::rectangle::loadValuesFromTextFile()
{

    fstream f;

    f.open(storedValuesPath);

    if (f.is_open()) {

        for(auto item : itsValues){
            f>>item;
        }

    }
    f.close();

}
void    figures::rectangle::writeValuesToTextFile(){

   fstream f;
   f.open(storedValuesPath);

   cout<<"writing values to "<<storedValuesPath<<endl;
   for(auto item : itsValues)
   {
       cout<<item<<endl;
       f<<item<<endl;
   }

   f.close();
}

void    figures::rectangle::setValue(int i, double value){

    itsValues[i]=value;

}
double  figures::rectangle::getValue(int i){

    return itsValues[i];
}

void    figures::rectangle::printMemberVariables(){

    int i = 0;
    for(auto item : itsValues){
        cout<<i++<<" "<<item<<endl;
    }

}

void figures::rectangle::cutAbs3D(){

    double a=itsValues[0];
    double b=itsValues[1];
    double phi0=itsValues[2];
    double rotAngleX=itsValues[3];
    double rotAngleZ=itsValues[4];
    double velocity = itsValues[5];

	if ((a <= 0) || (b <= 0)){

		cout << endl;
		cout << "ERROR:" << endl;
		cout << "a <= 0 or b <= 0 are no exaptable values for a rectangle " << endl;

	}
	else{

		pointerToE545->setVelocity(velocity, velocity, velocity);

		double xRotMat[3][3];
		double zRotMat[3][3];
		double pos[3];
		double deltaPhi[2];
		double R;
		double storagePos[5][3];
		double vec[3];

		int moves = 5;

		use.setRotMatrices(xRotMat, zRotMat, rotAngleX, rotAngleZ);
		pointerToE545->getPositon(pos);

		//////////////////////////////////////////////////////////////////////////
		//		Generating the sequence of coordinates that will be visited		//
		//////////////////////////////////////////////////////////////////////////

		R = 0.5*sqrt(a*a + b*b);
		deltaPhi[0] = 2 * atan(b / a);
		deltaPhi[1] = 2 * atan(a / b);

		double deltaPhiSum = phi0 - deltaPhi[0] / 2.0;

		//A
		//##################################
		vec[0] = R*cos(deltaPhiSum);
		vec[1] = R*sin(deltaPhiSum);
		vec[2] = 0;

		use.matrixTimesVec(xRotMat, vec);
		use.matrixTimesVec(zRotMat, vec);

		storagePos[0][0] = vec[0] + pos[0];
		storagePos[0][1] = vec[1] + pos[1];
		storagePos[0][2] = vec[2] + pos[2];
		//##################################

		//B, C, D, A 
		for (int i = 1; i <moves; i++){

			deltaPhiSum = deltaPhiSum + deltaPhi[((i + 1) % 2)];

			vec[0] = R*cos(deltaPhiSum);
			vec[1] = R*sin(deltaPhiSum);
			vec[2] = 0;

			use.matrixTimesVec(xRotMat, vec);
			use.matrixTimesVec(zRotMat, vec);

			storagePos[i][0] = vec[0] + pos[0];	
			storagePos[i][1] = vec[1] + pos[1];
			storagePos[i][2] = vec[2] + pos[2];
		}

		//////////////////////////////////////////////////////
		//		Write sequence to file for controle			//
		//////////////////////////////////////////////////////

		use.writeCoordToFile("rec3DAbs.txt", storagePos, moves);


		//////////////////////////////////////////
		//		Actual cutting procedure 		//
		//////////////////////////////////////////

		//A
		pointerToE545->moveTo(storagePos[0][0], storagePos[0][1], storagePos[0][2]);
		cout << "was target: "<<storagePos[0][0] << " " << storagePos[0][1] << " " << storagePos[0][2] << endl;
		pointerToE545->printPosition();
		pointerToE545->openShutter();
		//B, C, D, A
		for (int i = 1; i < moves; i++){

			cout << "i " << i << endl;
			pointerToE545->moveTo(storagePos[i][0], storagePos[i][1], storagePos[i][2]);
			cout<<"was target: " << storagePos[i][0] << " " << storagePos[i][1] << " " << storagePos[i][2] << endl;
			pointerToE545->printPosition();

		}
		pointerToE545->closeShutter();
		pointerToE545->moveTo(pos[0] + pointerToE545->itsXFocus, pos[1] + pointerToE545->itsYFocus, pos[2] + pointerToE545->itsZFocus);

	}
}

