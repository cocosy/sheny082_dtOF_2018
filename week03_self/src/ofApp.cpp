#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);    // set background black
  
    ofSetCircleResolution(100); // prettier circles
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //destination point
    
    glm::vec2 destination;
    destination.x   = ofGetMouseX();
    destination.y   = ofGetMouseY();
    float percent   = .05;
    
    // "interpolation" equation:
    
    glm::vec2 diff = destination - pos;
    
    pos += percent * diff;
    
    float dist = glm::distance(destination,pos);
    
    eye1 =  glm::vec2 (50,20);
    eye2 =  glm::vec2 (-50,20);
    
    eye1 -= percent *diff;
    eye2 -= percent *diff;
    
    
   // cout << " positions @ " << eyeDist << " here" << endl;
    
 radius = ofMap(dist, 0, 500, 30, 10);
 eyeModifier = ofMap(dist, 0, 500, 0.9,1.3);
 move = ofMap(dist, 0, 400, 20,140);

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //circle
    
    
    if(pos.x > 200+move && pos.x< 300+move && pos.y >300 && pos.y <700)
    {
       ofSetColor (255,0,0);
        ofDrawCircle(pos,150);
    }else{
        ofSetColor(51,204,255);
        ofDrawRectangle(pos- glm::vec2 (100,100),200,200);
    }    // set drawing color red
         //  circle position
    
    //whites
     ofSetColor(255);
    ofDrawCircle(pos - eye1, 30);
    ofDrawCircle(pos - eye2, 30);
    
    //eyes
    ofSetColor(0);
    
    ofDrawCircle(pos - eyeModifier*eye1, 15);
    ofDrawCircle(pos - eyeModifier*eye2, 15);
    
    //mouth
    ofSetColor(0);
    ofDrawCircle(pos + glm::vec2 (0,60), radius);

    //body
    ofSetColor(255);
    ofSetLineWidth(10);
    ofDrawLine(pos+ glm::vec2 (0,100), pos+ glm::vec2 (0,340));
    //arms
    ofDrawLine(pos+ glm::vec2 (0,150),pos+glm::vec2 (110,180));
    ofDrawLine(pos+ glm::vec2 (0,150),pos+glm::vec2 (-110,180));
    //legs
    ofDrawLine(pos+ glm::vec2 (0,330),pos+glm::vec2 (130,430));
    ofDrawLine(pos+ glm::vec2 (0,330),pos+glm::vec2 (-130,430));
    
    
    // tree
    
    ofSetColor(0,255,0);        // green
    ofDrawRectangle(200+move,300, 100,400);      // x,y: 100,300    width,height: 200,400
    
    // triangle
    ofSetColor(0,0,255);        // blue
    ofDrawTriangle(150+move,350,250+move,220-move,350+move,350);   // point1 x,y   point2 x,y     point3 x,y

    
    
    // simple text
    
    ofColor purple = ofColor(255,0,255);       // another way to create colors
    ofSetColor(purple);
    ofDrawBitmapString("hey yo!", ofGetWidth() * 0.5, ofGetHeight() - 100);
    // center and bottom
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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

