#ifndef FIGURES_H
#define FIGURES_H

#include "Header.h"
#include "stageController.h"
#include "usefulFunctions.h"
#include <Eigen/Core>

//This maybe seems confusing... I declared a namespace "figuresWriteCoordToFile"
//here because I ant to use for example "figuresWriteCoordToFile::rectangle rec" and 
//"figures::rectangle myRec"
//Something like "figuresWriteCoordToFile::figuresWriteCoordToFile myFigure" can not 
//occure becaue the contructors of "figuresWriteCoordToFile" are set to protected. 
//the same is true for the class and namespace figures. 
//This has the advantage that I can give all child classes shared functions or objects
//(like usefulFunctions) by writing them into the parent class, and I can still use namespace.
namespace figures{

	class figures
	{
	private:

	public:

		//For macros 
		double delayFactor = 1;


	protected:

		usefulFunctions use;
		figures(){}
		~figures(){}
	};




	//////////////////////////////////////
	//		surface rectangle			//
	//////////////////////////////////////
	class surfaceRectangle : public figures
	{
	private:
		stageController * pointerToE545;
		double a, b, phi0, velocity;
		int resolution;
		char orientation;

	public:
		void set(double aIn, double bIn, double phi0In, double velocityIn, int resoluationIn, char longOrShortSide);
		void cutRel();
		void cutAbs();

		surfaceRectangle(stageController &E545){

			pointerToE545 = &E545;
		}

		surfaceRectangle(){	
		}

		~surfaceRectangle(){}

	};





}
#endif
