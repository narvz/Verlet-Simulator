#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <vector>

#include "PointMass.h"
#include "Link.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

//-------------------------------VARIABLES GLOBALES-------------------------------------//
int npm = 0;
	
int widthW = 640;
float mouseInfluenceSize = 20; 
// minimum distance for tearing when user is right clicking
float mouseTearSize = 8;
float mouseInfluenceScalar = 5;
	
// amount to accelerate everything downward
float gravity = 980; 
	
// Dimensions for our curtain. These are number of PointMasss for each direction, not actual widths and heights
// the true width and height can be calculated by multiplying restingDistances by the curtain dimensions
const int curtainHeight = 2;
const int curtainWidth = 2;
const int yStart = 170; // where will the curtain start on the y axis?
const float restingDistances = 6;
const float stiffnesses = 1;
const float curtainTearSensitivity = 50; // distance the PointMasss have to go before ripping

vector<PointMass> pointmasses;
vector<Link> links;



/*-----------------------------------------------FUNCTIONS----------------------------------------------------*/

void createCourtain(){
	int midWidth = (int) (widthW/2 - (curtainWidth * restingDistances)/2);
	
	for (int y = 0; y <= curtainHeight; y++) { // due to the way PointMasss are attached, we need the y loop on the outside
    	for (int x = 0; x <= curtainWidth; x++) { 
      		PointMass pointmass = PointMass(midWidth + x * restingDistances, y * restingDistances + yStart);
      	
	      	// attach to 
	      	// x - 1  and
	      	// y - 1  
	      	//  *<---*<---*<-..
	      	//  ^    ^    ^
	      	//  |    |    |
	      	//  *<---*<---*<-..
	      	//
	      	// PointMass attachTo parameters: PointMass PointMass, float restingDistance, float stiffness
	      	// try disabling the next 2 lines (the if statement and attachTo part) to create a hairy effect
	        
	        if (x != 0){
	        	pointmass.attachTo((PointMass)pointmasses.at(pointmasses.size() - 1), restingDistances, stiffnesses);
			}
	        	
	      	// the index for the PointMasss are one dimensions, 
	      	// so we convert x,y coordinates to 1 dimension using the formula y*width+x 
			   
	      	/*if (y != 0)
	        	pointmass.attachTo((PointMass)(pointmasses.get((y - 1) * (curtainWidth+1) + x)), restingDistances, stiffnesses);*/
	        if (y != 0){
				pointmass.attachTo((PointMass)pointmasses.at((y - 1) * (curtainWidth+1) + x), restingDistances, stiffnesses);
			}
	      
	      	// we pin the very top PointMasss to where they are
	      	
	      	if (y == 0)
	        	pointmass.pinTo(pointmass.x, pointmass.y);

	        	
	        
	      	// add to PointMass array        	
	      	pointmasses.push_back(pointmass);
    	}
  	}
}







/*-----------------------------------------------UPDATE GRAPHICS----------------------------------------------------*/

/*-----------------------------------------------MAINS----------------------------------------------------*/


int main(int argc, char** argv){

    createCourtain();

    for(int i=0; i < pointmasses.size(); i++){
        PointMass p = pointmasses.at(i);
            p.draw();


    }
}


