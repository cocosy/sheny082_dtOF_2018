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
        
        
        glm::vec2 vel = glm::vec2(0,ofRandom(0,-7));  //move up
        float mass    = ofRandom(.01, 3);
        Particle particle = Particle(pos- glm::vec2 (65,0),vel,mass);  // start at system's position
        particles.push_back(particle);
    }

    
    // update particles; add repulsion:
    
    glm::vec2 mousePos = glm::vec2(ofGetMouseX(), ofGetMouseY());
    
    for (int i=0; i<particles.size(); i++)
    {
        glm::vec2 diff  = mousePos - particles[i].pos - glm::vec2 (65,0);
   
        float dist      = glm::length(diff);
        
        if (dist < 120. && dist != 0.)    // apply repulsion if distance is small (and not 0!)
        {
            glm::vec2 diffNorm  = diff / dist;
            glm::vec2 repulsion = diffNorm * -.5;
            particles[i].applyForce(repulsion);
        }
        particles[i].update();            // update
        //particles[i].applyElasticForce(); // bounce back to starting position
    }
    
    
    // erase old particles:
    
    while (particles.size() > maxParticles)     // keep the number of particles under a limit
    {
        particles.erase(particles.begin());     // erase the oldest particle
        
    }
    
}

void ParticleSystem::draw()
{
    for (int i=0; i<particles.size(); i++){
        
        particles[i].draw();
        
        
    }
    //cout << "t:" << ofGetElapsedTimef() - time << endl; // if exist more than 10s
    
}


bool ParticleSystem::testCollision(glm::vec2 sunPos,float sunRadius)
{   particleRadi = 3;
    bool collided = false;
    // check each circle of the paddle for collision:
   
    for (int i=0; i<particles.size(); i++)
    { //for (int j=0; j<315; j++){
        glm::vec2 diff = particles[i].pos - sunPos;

        float distance = glm::length(diff);

         
        if (distance <= particleRadi + sunRadius)
        {
            // collision!
            collided = true;
            break;  // exit for loop here! we don't want to continue checking
        }
    }
    return collided;    // return the result
}


