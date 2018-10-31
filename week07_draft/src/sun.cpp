//
//  sun.cpp
//  week07_draft
//
//  Created by Yang Shen on 2018/10/28.
//

#include "sun.hpp"

//sun::sun(glm::vec2 _pos, float _mass)
//{
//    pos = glm::vec2 ( ofRandom(ofGetWidth(),ofRandom(ofGetHeight())) );
//    origPos = pos;
//    mass    = ofRandom(1,5);
//    vel     = glm::vec2(0,0);
//    acc     = glm::vec2(0,0);
//}


sun::sun(glm::vec2 _pos, float _mass, ofColor _cSlow, ofColor _cFast, string _text){

    pos     = _pos;
    origPos = pos;
    mass    = _mass;
    vel     = glm::vec2(0,0);
    acc     = glm::vec2(0,0);
    cSlow   = _cSlow;
    cFast  = _cFast;
    text   = _text;
}


void sun::applyForce(glm::vec2 force)
{
    // force = mass * acceleration
    // acc = force / mass
    
    acc += force/mass;
}

void sun::applyDampingForce(float strength)
{

    
    // slows the ElasticMover
    
    float length = glm::length(vel);            // speed / "magnitude" of current velocity
    
    if (length != 0.0){                         // avoid illegal division by 0
        
        glm::vec2 direction = vel / length;     // normalize velocity to make speed 1
        applyForce( -direction * strength );    // scale speed and apply force away from velocity
    }
    
}

void sun::applyElasticForce()
{
    glm::vec2 elastic = (origPos-pos) * 0.02;   // accelerate towards original position
    applyForce(elastic);
}

void sun::bounceWindowEdges() {
    
    // keep ElasticMover on screen (bounce off edges)
    
    if (pos.x < 0) {
        pos.x = 0;
        vel.x *= -1;
    }
    
    if (pos.x > ofGetWidth()) {
        pos.x = ofGetWidth();
        vel.x *= -1;
    }
    
    if (pos.y < 0) {
        pos.y = 0;
        vel.y *= -1;
    }
    
    if (pos.y > ofGetHeight()) {
        pos.y = ofGetHeight();
        vel.y *= -1;
    }
}


void sun::update(bool bSpin)
{
    
    glm::vec2 mousePos = glm::vec2(ofGetMouseX(), ofGetMouseY());
    
//    for (int i=0; i<Sun.size(); i++)
//    {
    
        glm::vec2 diff  = mousePos - pos;
        float dist      = glm::length(diff);
        
        if (dist < 50. && dist != 0.)    // apply repulsion if distance is small (and not 0!)
        {
            glm::vec2 diffNorm  = diff / dist;
            glm::vec2 repulsion = diffNorm * -.5;
            applyForce(repulsion);
           // cout << "t:" << repulsion << endl;
        }
    
    applyElasticForce();
    applyDampingForce(0.05);
        
    //update
    vel += acc;
    pos += vel;
    acc *= 0;
    
    // add a circular spin (rotate the mover's orig pos and pos)
    
    float rotRad = .03;
    
    if (bSpin)
    {
        glm::vec2 center    = glm::vec2(ofGetWidth() * 0.5, ofGetHeight() * 0.8);
        
        // rotate pos of Mover
        
        glm::vec2 vec    = pos - center;
        float theta        = atan2(vec.y, vec.x) - rotRad;         // new angle for spiral
        float radius    = glm::length(vec);
        
        pos.x = center.x + (cos(theta) * radius);     // calc new position
        pos.y = center.y + (sin(theta) * radius);
        
        // rotate origPos of Mover
        
        glm::vec2 oVec  = origPos - center;
        float oTheta    = atan2(oVec.y, oVec.x) - rotRad;
        float oRadius   = glm::length(oVec);
        
        origPos.x = center.x + (cos(oTheta) * oRadius);
        origPos.y = center.y + (sin(oTheta) * oRadius);
        
    }
    
    
}
    


void sun::draw(bool bSpin)
{
  
    ofPushStyle();
    
    // interpolate between colors!
//    ofColor cSlow; //   = ofColor::fromHex(0xFFF200);    // hex format: 0xRRGGBB
//    ofColor cFast;   // = ofColor::fromHex(0xFF0000);
    
    float percent    = ofMap(glm::length(vel), 0., 7., 0., 1., true);    // mix based on speed
    ofColor sunColor   = cSlow.lerp(cFast, percent);    // "lerp" == interpolate
    
    ofSetColor(sunColor);
   
    ofDrawBitmapString(text,pos);
    //    ofDrawCircle(pos, mass * 2.0);  // base radius on mass
    
    ofPopStyle();
    
    
    
// ofColor lblCol(0); // black
//    if (bSpin) lblCol = ofColor::darkRed;
    ofDrawBitmapStringHighlight("space: Add Waterfall!", glm::vec2(20,20));
    ofDrawBitmapStringHighlight("mousePress: Draw Rainbow!", glm::vec2(20,40));
    
    
}



