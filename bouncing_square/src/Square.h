#pragma once
#include "ofMain.h"

class Square {
public: // accessible for other classes
    void setup(float posX,float posY, float width, float height);
    void update();
    void draw();
    
    float x;
    float y;
    float w;
    float h;
    
    float dirX, dirY;
};

