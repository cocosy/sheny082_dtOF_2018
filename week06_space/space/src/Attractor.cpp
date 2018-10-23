//
//  Attractor.cpp
//

// Source code for section 1.ii.d. Star Line Brush from the Introduction
// to Graphics chapter of ofBook (https://github.com/openframeworks/ofBook).
//https://github.com/openframeworks/ofBook/blob/master/chapters/intro_to_graphics/code/1_ii_d_Star_Line_Brush.sketch

#include "Attractor.hpp"

Attractor::Attractor()
{
	pos.x = ofRandom(ofGetWidth());
	pos.y = ofRandom(ofGetHeight());
	mass = ofRandom(5.,30.);
	
}

Attractor::Attractor(glm::vec2 _pos, float _mass)
{
	pos = _pos;
	mass = ofClamp(_mass, 5., 30.); // keep mass between 5 and 30
	
}

glm::vec2 Attractor::getForce(Mover mover)
{
	// calculate a force of attraction on mover
	glm::vec2 dir	= pos - mover.pos;	// the target is the attractor
    float distance	= glm::length(dir);
    
    glm::vec2 force = glm::vec2(0,0);   // default to 0 force
    
    if (distance > 0) {     // avoid division by 0
 
        // we'll model gravity:
        // from http://natureofcode.com/book/chapter-2-forces/#chapter02_section9
        //
        // gravity magnitude = (G * mass1 * mass2) / (distance * distance)
        //
        // where G = gravitational constant
        
        // we'll "clamp" the distance between 5 and 25
        // to prevent super-massive or super-micro gravity forces
        // ... this is a hack to keep things in equilibrium!
        float distanceMod	= ofClamp(distance, 5., 100.);
        
        float strength	    = (G * mass * mover.mass) / (distanceMod * distanceMod);
	
        glm::vec2 dirNorm   = dir / distance;   // normalized direction
        force	= dirNorm * strength;
	
    }
	return force;
}




void Attractor::draw()
{
	ofPushStyle();
    ofPopStyle();

// hue based on mass
   
//    ofSetLineWidth(2);
    // radius based on mass;
    
    int numLines = 30;
    int minRadius = ofMap(mass,4,30,5,60);
    int maxRadius = ofMap(mass,4,30,100,185);
    
        for (int i=0; i<numLines; i++) {
        
           
            // Formula for converting from polar to Cartesian coordinates:
            //    x = cos(polar angle) * (polar distance)
            //    y = sin(polar angle) * (polar distance)
            // We need our angle to be in radians if we want to use sin() or cos()
            // so we can make use of an openFrameworks function to convert from degrees
            // to radians
            
            
            
            float angle = ofRandom(ofDegToRad(360.0));
            float distance = ofRandom(minRadius, maxRadius);
            float xOffset = cos(angle) * distance;
            float yOffset = sin(angle) * distance;
            float alpha = ofMap(distance, minRadius, maxRadius, 50, 0); // Make shorter lines more opaque
            ofSetColor(255, alpha);
            
            ofSetLineWidth(ofRandom(1.0, 5.0)); // Remember, this doesn't work on all graphics cards
            //ofDrawLine(pos, pos.x +xOffset, pos.y +yOffset);
    
            ofDrawLine(pos.x,pos.y,pos.x + xOffset,pos.y + yOffset);
//            ofSetColor(0,0,0,0);
            float hue  = ofMap(mass, 5, 100, 180, 255);
            ofSetColor(ofMap(hue, 180, 255, 100, 255));
            ofDrawCircle(pos, mass * 0.1);
           
            cout << "t:" << mass << endl;
        }
    
    
    
}
	
	
	
	
