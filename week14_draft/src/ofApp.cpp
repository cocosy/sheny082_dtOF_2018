#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    //setup plane
    plane.set(320,240);   ///dimensions for width and height in pixels
    plane.setPosition(-20,20, 50); /// position in x y z
    plane.setResolution(10, 10); /// this resolution (as columns and rows) is enough
    
    body.loadModel("woman.obj",true);
    body.setPosition(ofGetWidth()/20, (float)ofGetHeight() * -0.3 , 0); //position
    
    meshBody = body.getMesh(0);                                         //create meshBody
    
    //change position of meshBody by moving all points
    int numVerts = meshBody.getNumVertices();
    for (int i=0; i<numVerts; ++i) {
        glm::vec3 vert = meshBody.getVertex(i);
//        vert.y -= 30;
//        vert.z += 480;
        meshBody.setVertex(i, vert);
    }
    
    
    //load image
    img.load("fish.png");
    img.resize(200, 133);
    
    
    //add color
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
    
    //GUI setup
    gui.setup();
    //set up three drawing methods
    gui.add( drawFaces.set("draw faces", true) );
    gui.add( drawWireframes.set("draw wires", false) );
    gui.add( drawVertices.set("draw vertices", false) );

    meshNode.setPosition(glm::vec3(ofGetWidth()*.5, ofGetHeight()*.5,0));
    meshNode.rotateDeg(180, 0,0,1);
}


//--------------------------------------------------------------
void ofApp::update(){
    
     float time = ofGetElapsedTimef();
    
    auto& planeVerts = plane.getMesh().getVertices();
    for (int i=0; i<planeVerts.size(); i++)
    {
    // add some mesh noise for an organic mountain
//        glm::vec3 nPos = planeVerts[i] * 0.1;
//        planeVerts[i].x += ofSignedNoise( nPos.x ) * 30.;
//        planeVerts[i].y += ofSignedNoise( nPos.y ) * 30.;
//        planeVerts[i].z += ofSignedNoise( nPos.z ) * 30.;
        
        
        float noise =
        ofSignedNoise ( planeVerts[i].x * 0.01,    // x pos
                       planeVerts[i].y * 0.01,    // y pos ; noiseScale.get().y
                       time * 0.5    // time (z) to animate ; noiseFreq
                       );
        
        //  change vertex z depth based on noise and amplitude setting
         planeVerts[i].z = noise * 40.0; //noiseAmp
    }
    
    
   
    glm::vec2 target = glm::vec2(ofGetMouseX(), ofGetMouseY()); //mouse position

    // make points vibrate with noise
    int numVerts = meshBody.getNumVertices();
    for (int i=0; i<numVerts; ++i) {
        glm::vec3 vert = meshBody.getVertex(i);
        
        glm::vec2 position;         // get the vert postion in vec2
        position.x = vert.x;
        position.y = vert.y;
        
//        glm::vec2 directionVec = target - position;      // the direction
//
//        //moving in the direction
//        vert.x += directionVec.x * 0.0001;
//        vert.y += directionVec.y * 0.0001;
        
        //moise
        float timeScale = 3.0;
        float displacementScale = 0.25;
        glm::vec3 timeOffsets = offsets[i];
        
        
        vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
        vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
        vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale;
        meshBody.setVertex(i, vert);
    }
    glm::vec2 direction = target - meshNode.getPosition();
    meshNode.setPosition( meshNode.getPosition() + direction*0.001);
    
}

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




//-----------------------------------------------------------------------------------------




void ofApp::draw(){
    
    
    mesh.draw();
//    cam.begin();
    ofEnableDepthTest();
    ofDrawAxis(100);
    
    ofPushMatrix();
    ofMultMatrix( meshNode.getGlobalTransformMatrix());
    plane.drawWireframe();
    
    if (drawFaces){

        meshBody.drawFaces();
    }
    if (drawWireframes){

        meshBody.drawWireframe();
    }
    if (drawVertices){
        //body.enableColors();
        // body.drawVertices();
        meshBody.drawVertices();
        //meshBody.disableColors();
    }
    
    ofPopMatrix();
    
    ofDisableDepthTest();
    
//    cam.end();
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
