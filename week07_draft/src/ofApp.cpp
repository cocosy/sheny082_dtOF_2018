#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    //rainbo setuo
    leftMouseButtonPressed = false;
    minDistance = 55.0;
    
    // create one particle system at center screen -- see ParticleSystem.cpp + ParticleSystem.hpp
    
    glm::vec2 pos = glm::vec2 (ofGetWidth() * 0.5, ofGetHeight() * 0.2);     // center screen
    time = ofGetElapsedTimef();
    ParticleSystem particleSystem = ParticleSystem(pos, time);
    particleSystems.push_back(particleSystem);
    
    // setup general gravity force
    
    gravity = glm::vec2(0, .8);
    
    
    // make a spiral
    
    center  = glm::vec2 (ofGetWidth() * 0.5, ofGetHeight() * 0.9);
    int nRotations    = 5;
    float maxAngle    = TWO_PI * nRotations;                  // angle in radians
    
    for (float theta = 0.; theta < maxAngle; theta += .1)    // increase angle (in radians)
    {
        float radius = (theta / maxAngle) * ofGetWidth() * .07;  // increase radius around spiral
        
        sunPos.x = center.x + (cos(theta) * radius * 4) * 2;
        sunPos.y = center.y + (sin(theta) * radius);
        
        sun theSun = sun(sunPos,1.);
        Sun.push_back(theSun);
        
            
        }
        
    
    bSpin = false;      // turn off spiral spinning
    
   
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (leftMouseButtonPressed) {
        ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());
        if (lastPoint.distance(mousePos) >= minDistance) {
            // a.distance(b) calculates the Euclidean distance between point a and b.  It's
            // the straight line distance between the points.
            currentPolyline.curveTo(ofGetMouseX(), ofGetMouseY());  // Here we are using an ofVec2f with curveTo(...)
            lastPoint = mousePos;
        }
    }


    for (int i =0; i<Sun.size();i++){
        Sun[i].update(bSpin);
    }
    
    for (int i=0; i<particleSystems.size(); i++){
        particleSystems[i].applyForce(gravity);
        particleSystems[i].update();
    }
    
    // test collision
    sunRadius =    ofGetHeight() * 0.3;
    for (int j=0; j<Sun.size(); j++){
    for (int i=0; i<particleSystems.size(); i++){
        
        bool  paddleCollided = particleSystems[i].testCollision(Sun[j].pos, sunRadius);
        if (paddleCollided) {
            Sun[j].applyForce(glm::vec2 (-0.7,0.4));
            sunColor = ofColor(0,255,0);
        } else {particleColor = ofColor(0,0,255);}// particleColor = ofColor(0,0,255); }
            
        }
       
    }
    


        
    
  
}

//--------------------------------------------------------------
void ofApp::draw(){
    //if(clicked){
    for (int i=0; i<particleSystems.size(); i++){
        particleSystems[i].draw();
        if(( ofGetElapsedTimef() -  particleSystems[i].time) > 10){
            particleSystems.erase(particleSystems.begin());
        }
    }
    for (int i =0; i<Sun.size();i++){
        Sun[i].draw(bSpin);
    }
    //}
  
    
    //rainbow
    for (int i=0; i<polylines.size(); i++) {
        
        // Drawing the polyline
        ofPolyline polyline = polylines[i];
        //polyline.draw();
        
        // Drawing evenly spaced tangents along the polyline
        //  Note: These are pretty exaggerated tangents, like Figure 16 (right)
        ofSetColor(255, 50);
        float numPoints = polyline.size();
        float tangentLength = 300;
        for (int p=0; p<500; p+=1) {
            ofVec3f point = polyline.getPointAtPercent(p/100.0);
            float floatIndex = p/100.0 * (numPoints-1);
            ofVec3f tangent = polyline.getTangentAtIndexInterpolated(floatIndex) * tangentLength;
            
            ofSetColor(ofColor::fromHex(0xFF0000));
            ofDrawBitmapString("R",point);
            
            ofSetColor(ofColor::fromHex(0xFF7F00));
            ofDrawBitmapString("A",point + ofVec3f(10, 0, 0));
            
            ofSetColor(ofColor::fromHex(0xFFF200));
            ofDrawBitmapString("I",point + ofVec3f(20, 0, 0));
            
            ofSetColor(ofColor::fromHex(0x1E9600));
            ofDrawBitmapString("N",point + ofVec3f(30, 0, 0));
            
            ofSetColor(ofColor::fromHex(0x0000FF));
            ofDrawBitmapString("B",point + ofVec3f(40, 0, 0));
            
            ofSetColor(ofColor::fromHex(0x4B0082));
            ofDrawBitmapString("O",point + ofVec3f(50, 0, 0));
            
            ofSetColor(ofColor::fromHex(0x9400D3));
            ofDrawBitmapString("W",point + ofVec3f(60, 0, 0));
        }
    }
     ofSetColor(255,255,255);
    
}


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    // create a new particle system at mouse position on click
    time = ofGetElapsedTimef();
    particleSystems.push_back( ParticleSystem(glm::vec2(x,y),time));
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 't'){
        clicked = true;
    }
    
    if (key == ' ')
    {
        bSpin = !bSpin;    // toggle wind
    }
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (button == OF_MOUSE_BUTTON_LEFT) {
        leftMouseButtonPressed = true;
        
        currentPolyline.curveTo(x, y);  // Remember that x and y are the location of the mouse
        currentPolyline.curveTo(x, y);  // Necessary duplicate for first control point
        lastPoint.set(x, y);  // Set the x and y of a ofVec2f in a single line
    }
    
    // Erase the polylines if the right mouse button is pressed
    if (button == OF_MOUSE_BUTTON_RIGHT) {
        currentPolyline.clear();
        polylines.clear();
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    if (button == OF_MOUSE_BUTTON_LEFT) {
        leftMouseButtonPressed = false;
        currentPolyline.curveTo(x, y);   // Necessary duplicate for last control point
        currentPolyline.simplify(0.75);
        polylines.push_back(currentPolyline);
        currentPolyline.clear();  // Erase the vertices, allows us to start a new brush stroke
    }
}
