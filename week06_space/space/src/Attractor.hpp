//
//  Attractor.hpp
//


#pragma once
#include "ofMain.h"

#include "Mover.hpp"
// Attractor class will apply attraction force on Movers

class Attractor {
public:
	
	Attractor();	                    	// default constructor - name of the class - run anytime you create a new obj - similar setup
	Attractor(glm::vec2 _pos, float _mass);	// alternative constructor
	
	glm::vec2 getForce(Mover m);
	// calculate attraction (or repulsion!)
    
    void update();
	void draw();
	
	glm::vec2 pos;
	float mass;
	
	const float G = .4;		// gravitational constant
	// affects strength of gravity
	
};
