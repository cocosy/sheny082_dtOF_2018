#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    
public:
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


