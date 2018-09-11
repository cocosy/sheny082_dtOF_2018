#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
//    square.setup(0,0,100,100);
//    square2.setup(100,-100,100,100);
    
    
    for (int i =0; i<10;i++){
        squares[i].setup(i*100,i*100,100,100);
    }
//    x = ofGetWidth()*0.5 -50;
//    y = ofGetHeight()*0.5 -50;
//    w = 100;
//    h = 100;
//
//    float i =0;
//    int idx =0;
//    bool myBool = false;
}

//--------------------------------------------------------------
void ofApp::update(){
//    square.update();
//    square2.update();
    
    for (int i =0; i<10;i++){
        squares[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
////    x = 0;
////    y = 0;
//    for(int i=0; i<10;i++){
////  ofDrawRectangle(x,y,w,h);
//    ofDrawRectangle(x+100*i,y+100*i,w,h);
////        x+= 100;
////        y+= 100;
//    }
//
//        int i = 0;
//        while(i<10){
//            cout<<"i is" << i << endl;
//            i++;
//        }
    
//    square.draw();
//    square2.draw();
    
      for (int i =0; i<10;i++){
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
