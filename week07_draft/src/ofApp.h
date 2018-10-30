#pragma once

#include "ofMain.h"
#include "ParticleSystem.hpp"
#include "sun.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    void keyPressed(int key);
   
    
    //        Ball balls[10];    // array of 10 Balls, see class declaration above
    bool clicked;
    bool bSpin;     // animate / spin the spiral?
    
    vector<ParticleSystem> particleSystems;
    vector<sun> Sun;

    glm::vec2 gravity;
    glm::vec2 center;
    glm::vec2 sunPos;
    
    bool paddleCollided;
    
    float time, sunRadius;
    
    ofColor sunColor, particleColor;
    
    ofPolyline currentPolyline;
    ofVec2f lastPoint;
    vector <ofPolyline> polylines;
    bool leftMouseButtonPressed;
    float minDistance;
    
};

