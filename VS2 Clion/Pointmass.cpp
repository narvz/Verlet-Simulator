#include "PointMass.h"
#include "Link.h"

using namespace std;

PointMass::PointMass(){
    x=0;
    y=0;

}

PointMass::PointMass(float xPos, float yPos){
  	x = xPos;
    		
    y = yPos;
    	
    lastX = x;
    lastY = y;
    accX = 0;
    accY = 0;
}

void PointMass::attachTo(PointMass P, float restingDist, float stiff){
	//cout << "attachTo 3ar\n";
	attachTo(P, restingDist, stiff, 30, true);
}

void PointMass::attachTo(PointMass P, float restingDist, float stiff, bool drawLink){
	//cout << "attachTo 4ar Bool\n";
	attachTo(P, restingDist, stiff, 30, drawLink);

}

void PointMass::attachTo(PointMass P, float restingDist, float stiff, float tearSensitivity){
	//cout << "attachTo 4ar Float\n";
	attachTo(P, restingDist, stiff, tearSensitivity, true);

}

Link link(Link lnk){
    return lnk;
}

void PointMass::attachTo(PointMass P, float restingDist, float stiff, float tearSensitivity, bool drawLink){
    Link lnk = Link(*this, P, restingDist, stiff, tearSensitivity, drawLink);
    link(lnk);
    //
	//cout << "attachTo 5ar : Link \n";
}

void PointMass::pinTo (float pX, float pY){
	pinned = true;
    pinX = pX;
    pinY = pY;
}

void PointMass::draw() {
    cout << "x: " << x << " y: " << y << "\n";
}
	
	


