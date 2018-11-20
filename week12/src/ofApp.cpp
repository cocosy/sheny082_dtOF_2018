#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    body.loadModel("woman.obj",true);
    body.setPosition(ofGetWidth()/20, (float)ofGetHeight() * -0.3 , 0);     //position
    //    body.setRotation(0, 180, 1, 0, 0);                                    //rotate to face the front
    //    body.setRotation(0, 180, 0, 1, 0);
    body.setRotation(0, 180, 0, 0, 1);
    
    
    //load image
    img.load("fish.png");
    img.resize(200, 133);
    
    //    mesh.setMode(OF_PRIMITIVE_POINTS);
    //    mesh.enableColors();
    
    meshBody = body.getMesh(0);
    float intensityThreshold = 150.0;
    int w = img.getWidth();
    int h = img.getHeight();
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = img.getColor(x, y);
            float intensity = c.getLightness();
            if (intensity >= intensityThreshold) {
                //glm::vec3 pos(x*5, y*5, 0.0);
                //meshBody.addVertex(pos);
                // When addColor(...), the mesh will automatically convert
                // the ofColor to an ofFloatColor
                meshBody.addColor(c);
                
                offsets.push_back(glm::vec3(ofRandom(0,100000), ofRandom(0,100000), ofRandom(0,100000)));
            }
        }
    }
    
    
    gui.setup();
    //set up three drawing methods
    gui.add( drawFaces.set("draw faces", true) );
    gui.add( drawWireframes.set("draw wires", false) );
    gui.add( drawVertices.set("draw vertices", false) );
    
    //    gui.add(scale.set("scale",1.0, 0.0, 3.0));
    
}


//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    // body.setScale(scale,scale, scale);
    //ofMesh mesh = body.getMesh(0);
    
    
    int numVerts = meshBody.getNumVertices();
    for (int i=0; i<numVerts; ++i) {
        glm::vec3 vert = meshBody.getVertex(i);
        
        float time = ofGetElapsedTimef();
        float timeScale = 5.0;
        float displacementScale = 0.75;
        glm::vec3 timeOffsets = offsets[i];
        
        // A typical design pattern for using Perlin noise uses a couple parameters:
        // ofSignedNoise(time*timeScale+timeOffset)*displacementScale
        //     ofSignedNoise(time) gives us noise values that change smoothly over
        //         time
        //     ofSignedNoise(time*timeScale) allows us to control the smoothness of
        //         our noise (smaller timeScale, smoother values)
        //     ofSignedNoise(time+timeOffset) allows us to use the same Perlin noise
        //         function to control multiple things and have them look as if they
        //         are moving independently
        //     ofSignedNoise(time)*displacementScale allows us to change the bounds
        //         of the noise from [-1, 1] to whatever we want
        // Combine all of those parameters together, and you've got some nice
        // control over your noise
        
        vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
        vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
        vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale;
        meshBody.setVertex(i, vert);
    }
    
}

void ofApp::draw(){
    
    
    mesh.draw();
    //cout << mesh.getNumVertices() << endl;
    cam.begin();
    ofEnableDepthTest();
    
    
    if (drawFaces){
        //  body.drawFaces();
        meshBody.drawFaces();
    }
    if (drawWireframes){
        // body.drawWireframe();
        meshBody.drawWireframe();
    }
    if (drawVertices){
        //body.enableColors();
        // body.drawVertices();
        meshBody.drawVertices();
        //meshBody.disableColors();
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

