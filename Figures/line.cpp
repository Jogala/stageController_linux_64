#include "line.h"

void    figures::line::loadValuesFromTextFile(){

    fstream f;

    f.open(storedValuesPath);

    if (f.is_open()) {

        for(auto item : itsValues){
            f>>item;
        }

    }
    f.close();

}
void    figures::line::writeValuesToTextFile(){

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

void    figures::line::setValue(int i, double value){

    itsValues[i]=value;

}
double  figures::line::getValue(int i){

    return itsValues[i];
}

void    figures::line::printMemberVariables(){

    int i = 0;
    for(auto item : itsValues){
        cout<<i++<<" "<<item<<endl;
    }

}

void figures::line::cutRel3D(){


    double l = itsValues[0];
    double phi = itsValues[1];
    double theta= itsValues[2];
    double repetitions= itsValues[3];
    double velocity = itsValues[4];

    pointerToE545->setVelocity(velocity, velocity, velocity);
    double vec[3];
    double pos[3];
    pointerToE545->getPositon(pos);
    repetitions = repetitions - 1;

    vec[0] = l*cos(phi)*sin(theta);
    vec[1] = l*sin(phi)*sin(theta);
    vec[2] = l*cos(theta);

    if (repetitions == 0){
        pointerToE545->openShutter();
        pointerToE545->move(vec);
        pointerToE545->closeShutter();
        pointerToE545->setVelocity(1000, 1000, 10);
        pointerToE545->moveTo(pos);
    }
    else{

        while (repetitions >= 0){
            pointerToE545->openShutter();
            pointerToE545->move(vec);
            pointerToE545->move(-vec[0], -vec[1], -vec[2]);
            repetitions = repetitions - 1;
        }
        pointerToE545->closeShutter();
        pointerToE545->moveTo(pos);
    }
}
void figures::line::cutAbs3D(){

    double l = itsValues[0];
    double phi = itsValues[1];
    double theta= itsValues[2];
    double repetitions= itsValues[3];
    double velocity = itsValues[4];

    if (repetitions < 1){

        cout << endl;
        cout << "ERROR:" << endl;
        cout << "repetitions has to be >= 1" << endl;

    }
    else{

        pointerToE545->setVelocity(velocity, velocity, velocity);

        double vec[3];
        double pos[3];
        auto storagePos = vector<vector<double>>(repetitions, vector<double>(3));

        pointerToE545->getPositon(pos);

        vec[0] = l*cos(phi)*sin(theta);
        vec[1] = l*sin(phi)*sin(theta);
        vec[2] = l*cos(theta);

        //////////////////////////////////////////////////////////////////////////
        //		Generating the sequence of coordinates that will be visited		//
        //////////////////////////////////////////////////////////////////////////


        for (int i = 0; i < repetitions; i++)
        {
            if (i % 2 == 0){
                storagePos[i][0] = pos[0] + vec[0];
                storagePos[i][1] = pos[1] + vec[1];
                storagePos[i][2] = pos[2] + vec[2];
            }

            if (i % 2 == 1){
                storagePos[i][0] = pos[0];
                storagePos[i][1] = pos[1];
                storagePos[i][2] = pos[2];
            }
        }
        //////////////////////////////////////////////////////
        //		Write sequence to file for controle			//
        //////////////////////////////////////////////////////

        use.writeCoordToFile("line3DAbs.txt", storagePos, repetitions);


        //////////////////////////////////////////
        //		Actual cutting procedure 		//
        //////////////////////////////////////////

        pointerToE545->openShutter();
        for (int i = 0; i < repetitions; i++){
            cout << " cut number " << i+1 << endl;
            pointerToE545->moveTo(storagePos[i][0], storagePos[i][1], storagePos[i][2]);

        }
        pointerToE545->closeShutter();
        pointerToE545->setVelocity(9000, 9000, 9000);
        pointerToE545->moveTo(pos[0] + pointerToE545->itsXFocus + vec[0] / 2, pos[1] + pointerToE545->itsYFocus + vec[1] / 2, pos[2] + pointerToE545->itsZFocus + vec[2] / 2);
    }//else

}
void figures::line::cutAbsLim3D(){

    double l = itsValues[0];
    double phi = itsValues[1];
    double theta= itsValues[2];
    double repetitions= itsValues[3];
    double velocity = itsValues[4];

    if (repetitions < 1){

        cout << endl;
        cout << "ERROR:" << endl;
        cout << "repetitions has to be >= 1" << endl;

    }
    else{

        pointerToE545->setVelocity(velocity, velocity, velocity);

        double vec[3];
        double pos[3];
        auto storagePos = vector<vector<double>>(repetitions, vector<double>(3));

        pointerToE545->getPositon(pos);

        vec[0] = l*cos(phi)*sin(theta);
        vec[1] = l*sin(phi)*sin(theta);
        vec[2] = l*cos(theta);

        int limAxis = use.axisOfBiggestProjection(vec);
        double c = 10;
        double normOfVec = use.norm(vec);

        //////////////////////////////////////////////////////////////////////////
        //		Generating the sequence of coordinates that will be visited		//
        //////////////////////////////////////////////////////////////////////////

        for (int i = 0; i < repetitions; i++)
        {
            if (i % 2 == 1){
                storagePos[i][0] = pos[0] + vec[0] + c*vec[0] / normOfVec;
                storagePos[i][1] = pos[1] + vec[1] + c*vec[1] / normOfVec;
                storagePos[i][2] = pos[2] + vec[2] + c*vec[2] / normOfVec;
            }

            if (i % 2 == 0){
                storagePos[i][0] = pos[0] - c*vec[0] / normOfVec;
                storagePos[i][1] = pos[1] - c*vec[1] / normOfVec;
                storagePos[i][2] = pos[2] - c*vec[2] / normOfVec;
            }
        }

        //////////////////////////////////////////////////////
        //		Write sequence to file for controle			//
        //////////////////////////////////////////////////////

        use.writeCoordToFile("line3DAbs.txt", storagePos, repetitions);

        //////////////////////////////////////////
        //		Actual cutting procedure 		//
        //////////////////////////////////////////

        //A
        pointerToE545->moveTo(storagePos[0][0], storagePos[0][1], storagePos[0][2]);
        pointerToE545->setLimits(limAxis, pos[limAxis], pos[limAxis] + vec[limAxis]);

        for (int i = 1; i <= repetitions; i++){

            pointerToE545->moveTo(storagePos[i][0], storagePos[i][1], storagePos[i][2]);

        }
        pointerToE545->closeShutter();
        pointerToE545->setVelocity(1000, 1000, 1000);
        pointerToE545->moveTo(pos[0], pos[1], pos[2]);

    }//else

}

