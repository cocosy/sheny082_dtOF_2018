
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // Create some polylines!
    straightSegmentPolyline.addVertex(100, 100);  // Add a new point: (100, 100)
    straightSegmentPolyline.addVertex(150, 150);  // Add a new point: (150, 150)
    straightSegmentPolyline.addVertex(200, 100);  // etc...
    straightSegmentPolyline.addVertex(250, 150);
    straightSegmentPolyline.addVertex(300, 100);
    
    curvedSegmentPolyline.curveTo(350, 100);  // These curves are Catmull-Rom splines
//  curvedSegmentPolyline.curveTo(350, 100);  // Necessary Duplicate for Control Point
    curvedSegmentPolyline.curveTo(400, 150);
    curvedSegmentPolyline.curveTo(450, 100);
    curvedSegmentPolyline.curveTo(500, 150);
//    curvedSegmentPolyline.curveTo(550, 100);
    curvedSegmentPolyline.curveTo(550, 100);  // Necessary Duplicate for Control Point
    
    closedShapePolyline.addVertex(600, 125);
    closedShapePolyline.addVertex(700, 100);
    closedShapePolyline.addVertex(800, 125);
    closedShapePolyline.addVertex(700, 150);
    closedShapePolyline.close();  // Connect first and last vertices
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetLineWidth(2.0);  // Line widths apply to polylines
    ofSetColor(255,100,0);
    
    float cx = ofGetWidth()/2;
    float cy = 200;
    float step = TWO_PI / 60;
    for (float i = 0.0; i < TWO_PI; i+=step) {
        
        
        if(i == 0.0) {
            line.addVertex(cx + (400*cos(i)), cy+400, 400 * sin(i));
        } else {
            line.bezierTo( cx - (200*cos(i)), cy-100, 400 * sin(i),
                          cx + (200*cos(i)), cy+600, 400 * sin(i),
                          cx + (400*cos(i)), cy+400, 400 * sin(i));
        }
    }
    
    
    
    straightSegmentPolyline.draw();  // This is how we draw polylines
    curvedSegmentPolyline.draw();  // Nice and easy, right?
    closedShapePolyline.draw();
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
