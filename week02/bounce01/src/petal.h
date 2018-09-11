#pragma once
#include "ofMain.h"

class Petal {
public:
    void setup(float posX, float posY, float posZ, float width, float height, float depth);
    void update();
    void draw();
    
    // some extra "utility" functions -
    // return the center coordinates
    float getCenterX();
    float getCenterY();
    
    float x, y, z, w, h, d;
    float dirX, dirY, dirZ;

    
};

