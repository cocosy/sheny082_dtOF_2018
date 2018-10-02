//
//  toy.hpp
//  mySketch
//
//  Created by Yang Shen on 2018/10/1.
//

#pragma once
#include "ofMain.h"

class Ball {
    
public:

    void setup(glm::vec2 position, float ballRadius, float ballLerp);   // init size and ball's "bounciness" glm::vec2 position
    void update(glm::vec2 velocity);
    void draw();
    
//    void setVelocity();
    
    glm::vec2 pos;
    glm::vec2 vel;      // velocity
    ofColor color;
    float radius;

    float lerp;
    
    
};
    
    // amount to interpolate when moving
    // (percentage of distance to target)
    


//    balls[i].radius = ofMap(i, 0, nBalls-1, 50, 10);
//    // radius based on ball array index
//
//    balls[i].lerp   = ofMap(balls[i].radius, 10, 50, 0.1, .03);
//    // the larger the ball, the slower the interpolation speed
//
//    // set color
//    balls[i].color.r = ofMap(balls[i].radius, 50,10, 0,255);    // smaller --> redder
//    balls[i].color.b = ofMap(balls[i].radius, 10,50, 0,255);    // larger --> bluer
//    balls[i].color.g = 0;       // no green

