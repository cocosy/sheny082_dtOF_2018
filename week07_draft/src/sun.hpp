#pragma once
#include "ofMain.h"

class sun {
    public:
    
    sun();                   // default
    sun(glm::vec2 _pos, float _mass, ofColor _cSlow, ofColor _cFast, string _text);
    
   
    
//    bool bSpin;     // animate / spin the spiral?
    
    // test if is colliding
    
    //void setup(glm::vec2 _pos, float _mass);
    
    void applyForce(glm::vec2 force);
    void applyDampingForce(float strength);
    void applyElasticForce();
    
    void bounceWindowEdges();
    
    void update(bool bSpin);
    void draw(bool bSpin);
    void keyPressed(int key);
    
    glm::vec2 origPos, pos, vel, acc;
    float mass;
    
    string text;
    
    ofColor sunColor,cSlow, cFast;
    
    
  
    
};
