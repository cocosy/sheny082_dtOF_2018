#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);    // set background black
    
    // setup our array of 10 petals, which we declared in ofApp.h
    for (int i=0; i<10; i++){   // loop 10 times, increment i each time
        
        // run the square setup function, offsetting x and y positions by (i * 50) pixels
        float w = ofGetWidth()/2 ;      // width
        float h = ofGetHeight()/2;      // height
        float d = 300;
        float x = ofGetWidth()/2 *sin(i/PI);
        float y = ofGetHeight()/2 *cos(i/PI);
        float z = 200;
        
        // we access array elements by index number, like array[index]
        
        petals[i].setup(x, y, z, w, h,d);
        
        // set starting movement direction
        
        petals[i].dirX = sin(i/PI);        // move 5 pixels right per frame to start
        petals[i].dirY = cos(i/PI);        // move 5 pixels down per frame
        
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<10; i++){
        petals[i].update();        // move and bounce off walls
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0; i<10; i++){
        petals[i].draw();          // draw to screen
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    
    // some extra keyboard commands:
    
    if (key == 'f') {
        
        // press f to toggle fullscreen / window mode
        ofToggleFullscreen();
    }
    
    else if (key == 'p')
        
        // print some info to console:
        
        // number of seconds app has been running
        cout << "petal positions @ " << ofGetElapsedTimef() << " seconds..." << endl;
    
    for (int i=0; i<10; i++){
        // print center positions
        cout << "    petal [" << i << "]: " << petals[i].getCenterX() << ", " << petals[i].getCenterY() << endl;
    }
    
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
