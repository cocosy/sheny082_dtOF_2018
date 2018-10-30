#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    // create one particle system at center screen -- see ParticleSystem.cpp + ParticleSystem.hpp
    
    glm::vec2 pos = glm::vec2(ofGetWidth() * 0.5, ofGetHeight() * 0.2);     // center screen
    time = ofGetElapsedTimef();
    ParticleSystem particleSystem = ParticleSystem(pos, time);
    particleSystems.push_back(particleSystem);
    
    // setup general gravity force
    
    gravity = glm::vec2(0, .8);
    
    
    // make a spiral
    
    center  = glm::vec2 (ofGetWidth() * 0.5, ofGetHeight() * 0.8);
    cout << "t:" << center << endl;
    int nRotations    = 5;
    float maxAngle    = TWO_PI * nRotations;                  // angle in radians
    
    for (float theta = 0.; theta < maxAngle; theta += .1)    // increase angle (in radians)
    {
        
        float radius = (theta / maxAngle) * ofGetWidth() * .07;  // increase radius around spiral
        
        sunPos.x = center.x + (cos(theta) * radius * 5) * 2;
        sunPos.y = center.y + (sin(theta) * radius);
        
        sun theSun = sun(sunPos,1.);
        Sun.push_back(theSun);
        
            
        }
        
    
    bSpin = false;      // turn off spiral spinning
    
   
}

//--------------------------------------------------------------
void ofApp::update(){
    



    for (int i =0; i<Sun.size();i++){
        Sun[i].update(bSpin);
    }
    
    for (int i=0; i<particleSystems.size(); i++){
        particleSystems[i].applyForce(gravity);
        particleSystems[i].update();
    }
    
    // test collision
    sunRadius =    ofGetHeight() * 0.3;
    for (int j=0; j<Sun.size(); j++){
    for (int i=0; i<particleSystems.size(); i++){
        
        bool  paddleCollided = particleSystems[i].testCollision(Sun[j].pos, sunRadius);
        if (paddleCollided) {
            Sun[j].applyForce(glm::vec2 (-0.7,0.4));
            sunColor = ofColor(0,255,0);
        } else {particleColor = ofColor(0,0,255);}// particleColor = ofColor(0,0,255); }
            
        }
       
    }
    


        
    
  
}

//--------------------------------------------------------------
void ofApp::draw(){
    //if(clicked){
    for (int i=0; i<particleSystems.size(); i++){
        particleSystems[i].draw();
        if(( ofGetElapsedTimef() -  particleSystems[i].time) > 10){
            particleSystems.erase(particleSystems.begin());
        }
    }
    for (int i =0; i<Sun.size();i++){
        Sun[i].draw(bSpin);
    }
    //}
  
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    // create a new particle system at mouse position on click
    time = ofGetElapsedTimef();
    particleSystems.push_back( ParticleSystem(glm::vec2(x,y),time));
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 't'){
        clicked = true;
    }
    
    if (key == ' ')
    {
        bSpin = !bSpin;    // toggle wind
    }
    
}
