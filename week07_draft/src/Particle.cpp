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
}



Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass)
{
    // "overload" constructor, alternative:
    // Particle particle = Particle(pos,vel,acc);
    
    pos = _pos;
    vel = _vel;
    mass = _mass;
    logo.load("tu.jpg");
    ofLoadImage(p, "tu.jpg");
    // do some stuff with tex
    tex.readToPixels(p); // now all the pixels from tex are in pix

}
    



void Particle::applyForce(glm::vec2 force)
{
    acc += force / mass;      // smaller mass greater acc
}



void Particle::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;

}


void Particle::draw()
{
    
//       logo.draw(pos);
    
    
//       unsigned char * pixels = logo.getPixels();
//       int counter = 0;
//       for(int i = 0; i < logo.width * logo.height; i++){
//       if (pixels[i] > 250){
//            counter ++;
//    }
    
    // put some stuff in the pixels
    
//    int i = 0;
//    while( i < p.size()) {
//       char c = p[i];
//    cout << "t:" << c << endl;
//        i++;
//    }
    
    ofSetColor(255);
//    ofColor purple = ofColor(255,0,255);       // another way to create colors
//    ofSetColor(purple);
    ofDrawBitmapString("Hiiiiiiiiiiiiiiiii!",pos);

 
    
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
