#pragma once
#include "ofMain.h"

class fly {
    public:

    
    fly();
    
    fly(glm::vec2 _pos);
    
    
    void update();
    void draw();
    
    ofPolyline polyline;
    ofPolyline polyline2;
    ofPolyline pv;
    float elementPositionPercent = 0.f;
    ofPoint elementPosition;
    
    float elementPositionPercent_02 = 0.f;
    ofPoint elementPosition_02;
    
};
