#include "petal.h"

// --------------------------------------------------------
void Petal::setup(float posX, float posY, float posZ, float width, float height, float depth){
    
    // setup position and size
    
    x = posX;
    y = posY;
    z = posZ;
    w = width;
    h = height;
    d = depth;
    
    
    // default to no movement yet - we can set it later
    
    dirX = 0;
    dirY = 0;
    dirZ = 0;
    
}

// --------------------------------------------------------
void Petal::update(){
    
    // move: update position x and y
    
    x += dirX;
    y += dirY;
    //     z += dirZ;
    //      w += dirY;
    //      h += dirY;
    //    d += dirZ;
    
    // ------bounce:---------------------------------------------------------------------------------------
    // check if we moved out of window frame
    
    if(x > ofGetWidth()){         // if we're too far right...
        x = ofGetWidth();         // put back in window
        dirX = dirX * -1;         // flip x movement
        
    }
    else if (x < 0){             // bounce off left edge
        x = 0;
        dirX = dirX * -1;
    }
    
    
    if(y > ofGetHeight()){
        // bounce bottom edge
        
        y = ofGetHeight();
        dirY = dirY * -1;
    }
    else if (y < 0){
        // or bounce top edge
        
        y = 0;
        dirY = dirY * -1;
    }
    // ---------------------------------------------------------------------------------------------
    
    
    
}

// --------------------------------------------------------
void Petal::draw(){
    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    ofDrawLine(w,h,d,x,y,z);
    ofEnableAlphaBlending();
    ofSetColor(255,255,255,150);
    ofDrawTriangle(w,h,0,d,z,0,x,y,0);
    
    // draw a simple rectangle on screen
}

// --------------------------------------------------------
float Petal::getCenterX(){
    return x + (w * 0.5);   // origin plus half the width
}
float Petal::getCenterY(){
    return y + (h * 0.5);
}

