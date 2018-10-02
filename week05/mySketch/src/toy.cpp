//
//  toy.cpp
//  mySketch
//
//  Created by Yang Shen on 2018/10/1.
//

#include "toy.hpp"

void Ball::setup(glm::vec2 position, float ballRadius, float ballLerp){
    //glm::vec2 position,
    //init ball variables
    
    pos = position;
    radius = ballRadius;
    lerp = ballLerp;
    
    vel = glm::vec2(0,0);

  
 
}

void Ball::update(glm::vec2 velocity) {
    vel = velocity;
    glm::vec2 mouse;
    mouse.x = ofGetMouseX();
    mouse.y = ofGetMouseY();
    
    pos += vel*lerp ;     // apply velocity
    pos += (mouse - pos) * lerp;
//    cout << "num: " << vel <<endl;
    

}
//
void Ball::draw() {
    ofColor color = ofColor(ofMap(radius,50,10, 0,255),ofMap(radius, 10,50, 0,255),0);
    ofSetColor(color);
    ofDrawCircle(pos, radius);
    ofSetColor(255);        // restore global white color
}
//
//void Ball::setVelocity(glm::vec2 velocity){
//
//}










//void Ball::setup(glm::vec2 position){
//}

//for (int i=0; i<nBalls; i++){
//
//    balls[i].radius = ofMap(i, 0, nBalls-1, 50, 10);
//    // radius based on ball array index
//    balls[i].lerp   = ofMap(balls[i].radius, 10, 50, 0.1, .03);
//    // the larger the ball, the slower the interpolation speed

