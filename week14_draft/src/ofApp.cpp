#include "ofApp.h"
//credit to https://openframeworks.cc/ofBook/chapters/generativemesh.html for exmaple on generating mesh from image



ofMesh meshLine(const ofMesh &mesh){
    ofMesh lines;
    ofVec3f centroid = mesh.getCentroid();
    int numVerts = mesh.getNumVertices();
    
    
    for(int i=0; i<numVerts; ++i){       //ofVec3f vertex : mesh.getVertices()
        double length = sin(ofGetElapsedTimef()) * 20.0;
        ofVec3f vertex = mesh.getVertex(i);
        ofVec3f direction = (vertex - centroid).getNormalized();
        ofVec3f farther_vertex = vertex + direction * length;
        //             cout << "t:" << vertex << endl;
        size_t idx = lines.getNumVertices();
        lines.addVertex(vertex);
        lines.addVertex(farther_vertex);
        
        lines.enableColors();
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255), ofRandom(100));
        lines.addIndex(idx);
        lines.addIndex(idx + 1);
        lines.disableColors();

        
    }
//    lines.setPosition(glm::vec3(ofGetWidth()*.5, ofGetHeight()*.5 + 30,500));//position
//    lines.rotateDeg(180, 0,0,1);
    lines.setMode(OF_PRIMITIVE_LINES); //OF_PRIMITIVE_LINE
    return lines;
};



//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    body.loadModel("woman.obj",true);

    //body.setPosition(ofGetWidth()/20, (float)ofGetHeight() * -0.3 , 0); //position
    
    meshBody = body.getMesh(0);
    meshCopyLine = body.getMesh(0);
   
    meshNode.setPosition(glm::vec3(ofGetWidth()*.5, ofGetHeight()*.5 + 30,500));//position
    meshNode.rotateDeg(180, 0,0,1);
    

    //setup plane
    plane.set(320,240);             //dimensions for width and height in pixels
    plane.setPosition(0,30, -50);   // position in x y z
    plane.setPosition(0,0,0);
    plane.setResolution(15, 15);    // this resolution (as columns and rows) is enough
    
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
    
//    //GUI setup
//    gui.setup();
//    //set up three drawing methods
//    gui.add( drawFaces.set("draw faces", true) );
//    gui.add( drawWireframes.set("draw wires", false) );
//    gui.add( drawVertices.set("draw vertices", false) );
    
    light.setup();
    light.setDirectional();
    light.setDiffuseColor( ofColor::wheat );
    light.setPosition(0, 200, 200);
    light.rotateDeg(225, 0, 1, 0);  // turn around to face plane + extra
    light.enable();
    bLighting  = false;
    
     drawFaces.set(true) ;
     drawWireframes.set(false) ;
     drawVertices.set(false) ;
    
   
    
    meshCentroid = meshBody.getCentroid();
    // Now that we know our centroid, we need to know the polar coordinates
    // (distance and angle) of each vertex relative to that center point.
    // We've found the distance between points before, but what about the angle?
    // This is where atan2 comes in.  atan2(y, x) takes an x and y value and returns
    // the angle relative to the origin (0,0).  If we want the angle between two
    // points (x1, y1) and (x2, y2) then we just need to use atan2(y2-y1, x2-x1).
    int numVerts = meshBody.getNumVertices();
    for (int i=0; i<numVerts; ++i) {
        ofVec3f vert = meshBody.getVertex(i);
        float distance = vert.distance(meshCentroid);
        float angle = atan2(vert.y - meshCentroid.y, vert.x - meshCentroid.x);
        distances.push_back(distance);
        angles.push_back(angle);
    }
    
    // These variables will allow us to toggle orbiting on and off
    orbiting = false;
    startOrbitTime = 0.0;
    meshCopy = meshBody;            //for orbiting

}


//--------------------------------------------------------------
void ofApp::update(){
    
    float time = ofGetElapsedTimef();
    
    //plane noise
    auto& planeVerts = plane.getMesh().getVertices();
    for (int i=0; i<planeVerts.size(); i++)
    {
        float noise =
        ofSignedNoise (planeVerts[i].x * 0.01,    // x pos
                       planeVerts[i].y * 0.01,    // y pos ; noiseScale.get().y
                       time * 0.5    // time (z) to animate ; noiseFreq
                       );
        
        //change vertex z depth based on noise and amplitude setting
         planeVerts[i].z = noise * 40.0; //noiseAmp
    }
    
    
   //move with mouse using position
    glm::vec2 target = glm::vec2(ofGetMouseX(), ofGetMouseY()); //mouse position
    glm::vec2 direction = target - meshNode.getPosition();
    //meshNode.setPosition( meshNode.getPosition() + direction*0.001);

    // make points vibrate with noise
    int numVerts = meshBody.getNumVertices();
    for (int i=0; i<numVerts; ++i) {
        glm::vec3 vert = meshBody.getVertex(i);

        //noise
        float timeScale = 3.0;
        float displacementScale = 0.25;
        glm::vec3 timeOffsets = offsets[i];
        
        
        vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
        vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
        vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale;
        
        //vert = vert - direction*0.001;
        meshBody.setVertex(i, vert - direction*0.001);
    };
    
    
    //orbiting
    if (orbiting) {
        int numVerts = meshBody.getNumVertices();
        for (int i=0; i<numVerts; ++i) {
            
            ofVec3f vert = meshBody.getVertex(i);
            float distance = distances[i];
            float angle = angles[i];
            float elapsedTime = ofGetElapsedTimef() - startOrbitTime;

            // Lets adjust the speed of the orbits such that things that are closer to
            // the center rotate faster than things that are more distant
            float speed = ofMap(distance, 0, 200, 1, 0.25, true);

            // To find the angular rotation of our vertex, we use the current time and
            // the starting angular rotation
            float rotatedAngle = elapsedTime * speed + angle;

            // Remember that our distances are calculated relative to the centroid
            // of the mesh, so we need to shift everything back to screen
            // coordinates by adding the x and y of the centroid
//            vert.x = distance * cos(rotatedAngle) + meshCentroid.x;
//            vert.y = distance * sin(rotatedAngle) + meshCentroid.y;
//            vert.z = vert.z ;

            vert.x = vert.x;
            vert.y = distance * sin(rotatedAngle) + meshCentroid.y;
            vert.z = distance * 0.8 + meshCentroid.z - 50;

            // cout << "t:" << sin(rotatedAngle) << endl;
            meshBody.setVertex(i, vert);
       
        }
    }

    

}

//----------------------------------------------------------------------------------------


void ofApp::draw(){
//    ofEnableAlphaBlending();
//    ofSetColor(30,30,30,30);
    
    

//    cam.begin();
    ofEnableDepthTest();
    ofDrawAxis(100);

    //meshBody.draw();
   
    ofPushMatrix();
    ofMultMatrix(meshNode.getGlobalTransformMatrix());
    
    meshLine(meshBody).draw();
   
 
    
    if (bLighting) ofEnableLighting();
    
//    plane.drawWireframe();
  
    
    if (bLighting) {
        ofPushStyle();
        ofSetColor(light.getDiffuseColor());
        light.draw();
        ofPopStyle();
    }
  
    if (drawFaces){

        meshBody.drawFaces();
        ofSetColor(255, 255, 255);
        plane.drawWireframe();
    }
    if (drawWireframes){

        meshBody.drawWireframe();
        ofSetColor(255, 255, 255);
        plane.drawWireframe();
    }
    if (drawVertices){
        //body.enableColors();
        // body.drawVertices();
        meshBody.drawVertices();
        ofSetColor(255, 255, 255);
        plane.drawVertices();
        //meshBody.disableColors();
    }
    if (bLighting) ofDisableLighting();
    ofPopMatrix();
    
    
    // draw info
    stringstream ss;
    ss
    << "use [L]ighting: \t" << bLighting << endl
    << "use [O]rbit: \t" << bNormals << endl
    << "draw [F]aces: \t" << drawFaces << endl
    << "draw [V]ertices: \t" << drawVertices << endl
    << "draw [W]ireframe: \t" << drawWireframes;
    
    ofDrawBitmapStringHighlight( ss.str(), 20,20 );
    
    ofDisableDepthTest();
    
//    cam.end();
//    gui.draw();
    
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'f'){
//        cout << "t:" << body.getPosition()<< endl;
        drawFaces.set(true);
        drawWireframes.set(false);
        drawVertices.set(false);
    }
    else if(key == 'w'){
        //        cout << "t:" << body.getPosition()<< endl;
        drawFaces.set(false);
        drawWireframes.set(true);
        drawFaces.set(false);
    }
    else if(key == 'v'){
        //        cout << "t:" << body.getPosition()<< endl;
        drawVertices.set(true);
        drawWireframes.set(false);
        drawFaces.set(false);
    }
    else if(key == 'l'){
               cout << "t:" << bLighting<< endl;
        bLighting = !bLighting;
    }
    if (key == 'o') {
            orbiting = !orbiting; // This inverts the boolean
            startOrbitTime = ofGetElapsedTimef();
            meshBody = meshCopy; // This restores the mesh to its original values
    };

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
