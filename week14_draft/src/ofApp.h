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
    
//  B mesh;     // plane stores an ofMesh
    
    ofPlanePrimitive plane;
    ofBoxPrimitive box;
    
    ofxAssimpModelLoader body;

    ofEasyCam cam;
    ofxPanel gui;
    ofMesh meshBody;
    ofNode meshNode;
    ofMesh meshCopy;
    
    ofMesh meshCopyLine;
    ofMesh mesh;
    
    
    bool orbiting;
    float startOrbitTime;
    
    // These variables will let us store the polar coordinates of each vertex
    vector<float> distances;
    vector<float> angles;
    ofVec3f meshCentroid;
    
    ofPolyline line;
    vector<ofVec3f> offsets;
   //vector<Vert> Vert;
    
       ofLight light;
     bool bLighting, bNormals, bWireframe;

};
    
    
