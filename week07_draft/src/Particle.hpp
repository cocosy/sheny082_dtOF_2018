//
//  Particle.hpp
//  wk06_particle_system
//
//  Created by Tyler Henry on 10/2/18.
//

#pragma once
#include "ofMain.h"

class Particle {
    
public:
    
    Particle();
    Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass);
    
    void applyForce(glm::vec2 force);
    void applyElasticForce();
    void update();
    void draw();
    

    ofImage logo ;
    ofPixels p;
    ofTexture tex;
    
    ofColor particleColor;

    
    glm::vec2 origPos, pos, vel, acc;
    float mass;
    
    int w, h, type, bpp;


    
};
