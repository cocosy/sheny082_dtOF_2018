#pragma once
#include "ofMain.h"

class Square {
public:
    void setup(float posX, float posY, float width, float height);
    void update();
    void draw();
    
    // some extra "utility" functions -
    // return the center coordinates
    //    float getCenterX();
    //    float getCenterY();
    
    glm::vec2 getCenter();
    glm::vec2 pos;
    glm::vec2 vel;
    float w, h;
  //  float dirX, dirY;
    ofColor color;
    
};


