#pragma once

#include "ofMain.h"
#include "ParticleSystem.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void mouseReleased(int x, int y, int button);
    
    void keyPressed(int key);
   
    
    //        Ball balls[10];    // array of 10 Balls, see class declaration above
    bool clicked;
    
    vector<ParticleSystem> particleSystems;
    glm::vec2 gravity;
    
    float time;
    
    
};

