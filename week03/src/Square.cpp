#include "Square.h"

// --------------------------------------------------------
void Square::setup(float posX, float posY, float width, float height){
    
    // setup position and size
    
    //    x = posX;
    //    y = posY;
    
    pos = glm::vec2(posX,posY);
    
    w = width;
    h = height;
    
    // default to no movement yet - we can set it later
    
    //    dirX = 0;
    //    dirY = 0;
       vel = glm::vec2(0,0);
//    vel.x = 0;
//    vel.y = 0;
    color = ofColor(225);
}

// --------------------------------------------------------
void Square::update(){
    
    // move: update position x and y
    
    //    x += dirX;
    //    y += dirY;
    pos += vel;
    
    // bounce:
    
    // check if we moved out of window frame
    
    if(pos.x > ofGetWidth()){
        // if we're too far right...
        
        // bounce
        pos.x = ofGetWidth();        // put back in window
        vel.x = vel.x * -1;        // flip x movement
        
    }
    else if (pos.x < 0){
        // bounce off left edge
        
        pos.x = 0;
        vel.x = vel.x * -1;
        //dirX = dirX * -1;
    }
    
    
    if(pos.y > ofGetHeight()){
        // bounce bottom edge
        
        pos.y = ofGetHeight();
        vel.y = vel.y * -1;
    }
    else if (pos.y < 0){
        // or bounce top edge
        
        pos.y = 0;
        vel.y = vel.y * -1;
    }
    
}

// --------------------------------------------------------
void Square::draw(){
    ofSetColor(color);
    ofDrawRectangle(pos.x,pos.y,w,h);
    // draw a simple rectangle on screen
}

// --------------------------------------------------------
//float Square::getCenterX(){
//    return pos.x + (w * 0.5);   // origin plus half the width
//}
//float Square::getCenterY(){
//    return pos.y + (h * 0.5);
//}

glm::vec2 Square::getCenter(){
    float cx = pos.x + w * 0.5;
    float cy = pos.y + h * 0.5;
    return glm::vec2(cx,cy);
}
