// Square.cpp
//  bouncing_square
//
//  Created by Yang Shen on 2018/9/4.

#include "Square.h"

void Square::setup(float posX,float posY,float width, float height){//link the the public
    x = posX ;
    y = posY;
    w = width;
    h = height;
    dirX =5;
    dirY =5;
    
}

void Square::update(){
    x += dirX;
    y += dirY;
    if(x>ofGetWidth() || x<0){
        x = ofGetWidth();
        dirX = dirX * -1;
    }
    if(y>ofGetHeight() || y<0){
        y = ofGetHeight();
        dirY = dirY * -1;
    }
}

void Square::draw(){
    ofDrawRectangle(x,y,w,h);
    
}
