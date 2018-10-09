//
//  ParticleSystem.cpp
//  wk06_particle_system
//
//  Created by Tyler Henry on 10/2/18.
//

#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem()
{
    pos = glm::vec2(0,0);       // default value
    time;
    
}

ParticleSystem::ParticleSystem(glm::vec2 _pos, float _life)
{
    pos = _pos;                 // assigned value
    time = _life;
    
}

void ParticleSystem::applyForce(glm::vec2 force)
{
    // add the force to all particles
    
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].applyForce(force);
    }
}

void ParticleSystem::update(int numNewParticles, int maxParticles)
{
    
    // create new particles:
   

    for (int i=0; i<numNewParticles; i++)
    {
        float sinOfTime = sin(ofGetElapsedTimef());
        float cosOfTime = cos(ofGetElapsedTimef());
        
        
        glm::vec2 vel = glm::vec2(ofRandom(-7,7),ofRandom(-7,7));  //move up
        float mass    = ofRandom(.01, 3);
        Particle particle = Particle(pos,vel,mass);     // start at system's position
        particles.push_back(particle);

    }

    
    
    // update particles:
    
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].update();
    }
    
    // erase old particles:
    
    while (particles.size() > maxParticles)     // keep the number of particles under a limit
    {
        particles.erase(particles.begin());     // erase the oldest particle
        
    }
    
}

void ParticleSystem::draw()
{
    if( ofGetElapsedTimef() - time < 5){
    //cout << "t:" << ofGetElapsedTimef() - time << endl; // if exist more than 10s
    
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].draw();
    }
    }
    
}

