#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofxGui.h"
//#include "Body.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofParameter<float> scale;
    ofParameter<bool> drawFaces, drawWireframes, drawVertices;
    ofImage img;
    
//   Plane mesh;     // plane stores an ofMesh
    
    ofPlanePrimitive plane;
    
    ofxAssimpModelLoader body;
    ofEasyCam cam;
    ofxPanel gui;
    ofMesh meshBody;
    ofNode meshNode;
    ofMesh mesh;
    
    
    vector<ofVec3f> offsets;
   //vector<Vert> Vert;
   
};
    
    
