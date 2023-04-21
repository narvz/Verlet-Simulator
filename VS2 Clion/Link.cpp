//
// Created by Usuario on 05/04/2023.
//

#include "Link.h"
#include "Pointmass.h"

using namespace std;
Link::Link() {


}

Link::Link(PointMass which1, PointMass which2, float restingDist, float stiff, float tearSensitivity, bool drawMe)  {

    p1 = which1; // when you set one object to another, it's pretty much a reference.
    p2 = which2; // Anything that'll happen to p1 or p2 in here will happen to the paticles in our ArrayList

    restingDistance = restingDist;
    stiffness = stiff;
    drawThis = drawMe;

    this->tearSensitivity = tearSensitivity;
}

Link::~Link(){
}


