//
//  ParticleSystem.hpp
//  wk06_particle_system
//
//  Created by Tyler Henry on 10/2/18.
//

#pragma once
#include "ofMain.h"
#include "Particle.hpp"

class ParticleSystem {
public:
    
    // we are now using C++ constructors --
    
    // constructors are functions like setup(), but they run automatically
    // when the object is created in our app
    
    // -- note: constructors do not have a return type
    
    ParticleSystem();                   // default
    ParticleSystem(glm::vec2 _pos, float _life);     // "overload" / alternative
    
    void applyForce(glm::vec2 force);   // applies force to particles
    
    void update(int numNewParticles = 1, int maxParticles = 40);
    /*
        numNewParticles:
            how many new particles to create each frame
                (defaults to 10)
        maxParticles:
            maximum number of particles the system will hold
                (defaults to 1000)
     */
    
    bool testCollision(glm::vec2 sunPos, float sunRadius);
    
    
    void draw();
    
    glm::vec2 pos, sunPos;                      // origin of the particle system
    
    vector<Particle> particles;
    float time, particleRadi;                         // stopwatch for particle sys
};
