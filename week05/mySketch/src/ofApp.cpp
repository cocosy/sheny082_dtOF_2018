#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    clicked = false;
    ofBackground(0);
    
    ofSetCircleResolution(100);
    
    // create 10 balls in array
    int nBalls = 5;    // needs to match array size delcared in ofApp.h!

        
    for (int i=0; i<nBalls; i++){
        Ball ball;
        
        float radius      = ofMap(i, 0, nBalls-1, 50, 10);
        float lerpness    = ofMap(radius, 10, 50, 0.1,.001);

            
        glm::vec2 pos;
        pos.x               = ofGetWidth() * 0.5;      //  random x pos in box
        pos.y               = ofGetHeight() * 0.5;
        
            ball.setup(pos, radius, lerpness);
            balls.push_back(ball);
        }

}

//--------------------------------------------------------------
void ofApp::update(){
     for (int i=0; i<balls.size(); i++){
     balls[i].update();
     }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //text
    ofColor purple = ofColor(255,0,255);       // another way to create colors
    ofSetColor(purple);
    ofDrawBitmapString("Press 't' to open the box!", ofGetWidth() * 0.5, ofGetHeight() - 200);
    
    if(clicked){
        for (int i=0; i<balls.size(); i++){
            balls[i].draw();}
   
}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 't'){
        clicked = true;
        }
    }
    


//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

//            balls[i].radius = ofMap(i, 0, nBalls-1, 50, 10);
//            // radius based on ball array index
//
//            balls[i].lerp   = ofMap(balls[i].radius, 10, 50, 0.1,.001);
// the larger the ball, the slower the interpolation speed

//  random x pos in box

// set color
//            balls[i].color.r = ofMap(balls[i].radius, 50,10, 0,255);    // smaller --> redder
//            balls[i].color.b = ofMap(balls[i].radius, 10,50, 0,255);    // larger --> bluer
//            balls[i].color.g = 0;       // no green



//    for (int i=0; i<10; i++){
//        ofSetColor(balls[i].color);
//        ofDrawCircle(balls[i].pos, balls[i].radius);
//}
