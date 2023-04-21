
#ifndef VS2_CLION_POINTMASS_H
#define VS2_CLION_POINTMASS_H

#include <iostream>
#include <vector>


class PointMass{
	
	protected:
		
 		 		
  	public:

    PointMass();


        float lastX, lastY; // for calculating position change (velocity)
  		float x,y;
  		float accX, accY;
  		
  		float mass = 1;
  		float damping = 20;
	
  		// An ArrayList for links, so we can have as many links as we want to this PointMass
  		//ArrayList links = new ArrayList();
        //std::vector<Link> links;

        int idLinks[50];


        bool pinned = false;
  		float pinX, pinY;

  		PointMass(float xPos, float yPos);
  		void attachTo(PointMass P, float restingDist, float stiff);
  	  	void attachTo(PointMass P, float restingDist, float stiff, bool drawLink);
  	  	void attachTo(PointMass P, float restingDist, float stiff, float tearSensitivity);
 	  	void attachTo(PointMass P, float restingDist, float stiff, float tearSensitivity, bool drawLink);
 	  	void pinTo (float pX, float pY);
        void draw();

 	
};

#endif

