//
//  Particle.cpp
//  wk06_particle_system
//
//  Created by Tyler Henry on 10/2/18.
//

#include "Particle.hpp"

Particle::Particle()
{
    
    // default constructor:
    // Particle particle = Particle();
    
    pos = glm::vec2(0,0);
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
    

}

Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass)
{
    
    // "overload" constructor, alternative:
    // Particle particle = Particle(pos,vel,acc);
    
    pos = _pos;
    vel = _vel;
    mass = _mass;

}

void Particle::applyForce(glm::vec2 force)
{
    acc += force / mass;             // smaller mass greater acc
}

void Particle::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;
}

void Particle::draw()
{
 
    ofPushStyle();
    float hue = ofMap(mass, 0, 3, 100, 255); // mass changes hue
    if (pos.x < ofGetWidth() * 0.32){
        ofSetColor(ofColor(255,hue,255));}
    else if ( pos.x < ofGetWidth() * 0.7 && pos.x > ofGetWidth() * 0.32){
        ofSetColor(ofColor::fromHsb(110 - hue * 0.4,hue,250));
    }else{
          ofSetColor(ofColor::fromHsb(hue,hue,250));
    }

    ofDrawCircle(pos, mass * 2.0);  // mass changes size
    ofPopStyle();
    

}

