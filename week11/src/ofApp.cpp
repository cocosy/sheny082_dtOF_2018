#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    body.loadModel("woman.obj",true);
    body.getMesh(bodyMesh);
    cout << bodyMesh << endl;
    meshBody = body.getMesh(0);
    
    meshBody.getVertices().
    
    
    //load image
    image.load("fish.png");
    image.resize(200, 133);
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.enableColors();
    
    float intensityThreshold = 150.0;
    int w = image.getWidth();
    int h = image.getHeight();
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();
            if (intensity >= intensityThreshold) {
                glm::vec3 pos(x*5, y*5, 0.0);
                mesh.addVertex(pos);
                // When addColor(...), the mesh will automatically convert
                // the ofColor to an ofFloatColor
                mesh.addColor(c);
            }
        }
    }
    
    
    mesh.setMode(OF_PRIMITIVE_LINES);
    
    // We are going to be using indices this time
    mesh.enableIndices();
    
    // ...
    // Omitting the code for creating vertices for clarity
    // but don't erase it from your file!
    
    // Let's add some lines!
    float connectionDistance = 30;
    int numVerts = mesh.getNumVertices();
    for (int a=0; a<numVerts; ++a) {
        ofVec3f verta = mesh.getVertex(a);
        for (int b=a+1; b<numVerts; ++b) {
            ofVec3f vertb = mesh.getVertex(b);
            float distance = verta.distance(vertb);
            if (distance <= connectionDistance) {
                // In OF_PRIMITIVE_LINES, every pair of vertices or indices will be
                // connected to form a line
                mesh.addIndex(a);
                mesh.addIndex(b);
            }
        }
    }
    
    body.setPosition(ofGetWidth()/20, (float)ofGetHeight() * -0.3 , 0);     //position
//    body.setRotation(0, 180, 1, 0, 0);                                    //rotate to face the front
//    body.setRotation(0, 180, 0, 1, 0);
    body.setRotation(0, 180, 0, 0, 1);
    
    
    gui.setup();

    //set up three drawing methods
    gui.add( drawFaces.set("draw faces", true) );
    gui.add( drawWireframes.set("draw wires", false) );
    gui.add( drawVertices.set("draw vertices", false) );
    
    gui.add(scale.set("scale",1.0, 0.0, 3.0));

    // add parameters from Plane class
}


//--------------------------------------------------------------
void ofApp::update(){
    body.setScale(scale,scale, scale);
    ofMesh mesh = body.getMesh(0);
    
}

void ofApp::draw(){
    

    mesh.draw();
    //cout << mesh.getNumVertices() << endl;
    cam.begin();
    ofEnableDepthTest();
    
    
    if (drawFaces){
     
        body.drawFaces();
    }
    if (drawWireframes){
      
        body.drawWireframe();
    }
    if (drawVertices){
        //body.enableColors();
        body.drawVertices();
        body.disableColors();
    }
    
    ofDisableDepthTest();
    
    cam.end();
    
      gui.draw();
    

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
    cout << "t:" << body.getPosition()<< endl;
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
