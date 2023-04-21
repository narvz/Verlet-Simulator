//
// Created by Usuario on 05/04/2023.
//

#ifndef VS2_CLION_LINK_H
#define VS2_CLION_LINK_H

#include <iostream>
#include "Pointmass.h"
// The Link class is used for handling distance constraints between PointMasss.

class Link {
protected:


public:

    //Link(PointMass mass, PointMass mass1, float d, float d1, float d2, bool b);

    float restingDistance;
    float stiffness;
    float tearSensitivity;

    PointMass p1;
    PointMass p2;

    // if you want this link to be invisible, set this to false
    bool drawThis = true;
    Link();
    Link(PointMass which1, PointMass which2, float restingDist, float stiff, float tearSensitivity, bool drawMe);
    //void draw();
    ~Link();



};


#endif //VS2_CLION_LINK_H
