#include "ofApp.h"

void ofApp::update()
{
    // Curve center
    float cx = ofGetWidth() * 0.5f ;
    float cy = ofGetHeight() * 0.5f ;
    //float cz = 0.f ;
    
    // Curve radius
    float rx = cx * 0.5f ;
    float ry = cy * 0.5f ;
    //float rz = rx ;
    
    // Angle animation
    float dx = ofGetElapsedTimef() * 0.3f ;
    float dy = -ofGetElapsedTimef() * 0.3f ;
    // float dz = ofGetElapsedTimef() * 0.01f ;
    
    // Push vertices to polyline
    polyline.clear() ;
    for( float angle = 0.f, angleMax = 2.f * PI ; angle < angleMax ; angle += 0.005f )
    {
        ofPoint p ;
        p.x = rx * cos( dx + angle * 15.f ) ;
        p.y = ry * sin( dy + angle * 23.f ) ;
        p.rotateRad( angle, ofPoint( 1.f, 0.f, 0.f ) ) ;
        p.x += cx;
        p.y += cy;
        // p.z += cz;
        
        polyline.addVertex( p );
    }
    
    
    glm::vec2 center  = glm::vec2 (ofGetWidth() * 0.5, ofGetHeight() * 0.5);
    int nRotations    = 1;
    float maxAngle    = PI * nRotations;                  // angle in radians
    
    for (float theta = 0.; theta < maxAngle; theta += .1)    // increase angle (in radians)
    {
        float radius = 20 ;  // increase radius around spiral
        
        ofPoint Rb ;
        Rb.x = center.x + (cos(theta) * radius * 9) * 2;
        Rb.y = center.y + (sin(theta) * radius * 10 );
        
        pv.addVertex(Rb);
        ofDrawCircle(Rb, 40);
    }
    
    polyline2.lineTo(300, 50);
    ofPoint point2(450,120);
    polyline2.arc(point2,100,100,0,180);
    
    //    elementPositionPercent_02 += 0.0002f ;
    //    if( elementPositionPercent_02 > 1.f ) elementPositionPercent_02 = 0.f ;
    //    elementPosition_02 = polyline.getPointAtPercent( elementPositionPercent_02 ) ;
    //
    // Animate the disk on the curve
    elementPositionPercent += 0.0002f ;
    if( elementPositionPercent > 1.f ) elementPositionPercent = 0.f ;
    elementPosition = polyline.getPointAtPercent( elementPositionPercent ) ;
}

void ofApp::draw()
{   pv.draw();
    polyline.draw() ;
    ofDrawCircle( elementPosition, 15.f );
    
    
    
    //    ofSetColor(ofColor::blue);
    //    polyline2.draw();
    //     ofDrawCircle( polyline2.getPointAtPercent(elementPositionPercent),30.f);
    
    //type
    //ofColor color = ofColor::fromHex(0xFFF200);
    //ofSetColor(color)h;
    //ofDrawBitmapString("hiiiiiiiiii",point2.pos);
    
}
