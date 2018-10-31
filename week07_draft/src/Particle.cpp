//  Particle.cpp
//  wk06_particle_system
//
//  Created by Tyler Henry on 10/2/18.
//

#include "Particle.hpp"


Particle::Particle()
{   // default constructor:
    // Particle particle = Particle();
    
    pos = glm::vec2(0,0);
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
    origPos = pos;
}



Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass)
{
    // "overload" constructor, alternative:
    // Particle particle = Particle(pos,vel,acc);
    
    pos = _pos;
    origPos = pos;
    vel = _vel;
    mass = _mass;
    logo.load("tu.jpg");        //load picture
    //    ofLoadImage(p, "tu.jpg");
    //    tex.readToPixels(p); // now all the pixels from tex are in pix

}



void Particle::applyForce(glm::vec2 force)
{
    acc += force / mass;      // smaller mass greater acc
}

void Particle::applyElasticForce()
{
    glm::vec2 elastic = (origPos-pos) * 0.001;   // accelerate towards original position
    applyForce(elastic);
}


void Particle::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;
    
}

void Particle::draw()
{
    
    int widthStep = 10;
    int heightStep = 5;

    for (int i = 0; i < logo.getWidth(); i+=widthStep) {
        for (int j = 0; j < logo.getHeight(); j+=heightStep) {
            ofColor c = logo.getColor(i, j);
        }
    }
   
    // ofSetColor(c(pos));
    
    ofPushStyle();
    
    // interpolate between colors!
    ofColor cSlow    = ofColor::fromHex(0x005AA7);    // hex format: 0xRRGGBB
    ofColor cFast    = ofColor::fromHex(0xE0EAFC);
    
    float percent    = ofMap(glm::length(vel), 0., 7., 0., 1., true);    // mix based on speed
    ofColor particleColor   = cSlow.lerp(cFast, percent);    // "lerp" == interpolate
    
    ofSetColor(particleColor);
    
    ofDrawBitmapString("wwwaaattteeerrrfffaaallllll!",pos);
    

 
    //    ofColor purple = ofColor(255,0,255);    // another way to create colors
    //    ofSetColor(purple);
  
        ofPopStyle();
}








//---------------------------------------------------------------
    
//    ofPushStyle();
//    float hue = ofMap(mass, 0, 3, 100, 255); // mass changes hue

//    colors
//    if (pos.x < ofGetWidth() * 0.32){
//        ofSetColor(ofColor(255,hue,255));}
//    else if ( pos.x < ofGetWidth() * 0.7 && pos.x > ofGetWidth() * 0.32){
//        ofSetColor(ofColor::fromHsb(110 - hue * 0.4,hue,250));
//    }else{
//          ofSetColor(ofColor::fromHsb(hue,hue,250));
//    }

//    ofDrawCircle(pos, mass * 2.0);  // mass changes size
//    ofPopStyle();







    //    int ofImage_w = logo.width;
    //    int ofImage_h = logo.height;
    //    int type = logo.type;
    //    int bpp = logo.bpp / 8;
    //    for(){
    //
