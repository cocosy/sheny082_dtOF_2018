#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for (int i = 0; i < 10; i ++){
        float w = ofRandom(20, 50);
        squares[i].setup(ofGetWidth()*0.5, ofGetHeight()*0.5, w, w);
        //float speed = squares[i].w * 0.25;
        float area = squares[i].w * squares[i].h;
        
        //        int dir = 1;
        //        if (ofRandom(1)<0.5){
        //            dir *= -1;
        //        }
        
        float speed = ofMap(area, 400, 2500, 20, 5);
        squares[i].vel.x = speed * ofRandom(-1,1);
        squares[i].vel.y = speed * ofRandom(-1,1);
        
        cout << "square["<< i << "] area =" << area
        << " speed = " << speed << endl;
        
        //squares[i].color = ofColor(speed);
        float hue = ofMap(speed, 5, 20, 100, 200);
        squares[i].color = ofColor::fromHsb(hue, 255, 200);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < 10; i ++){
        squares[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < 10; i ++){
        squares[i].draw();
    }
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
