#pragma once

#include "ofMain.h"
#include "Square.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
        void draw();
    
    float x;
    float y;
    float w;
    float h;
    
    Square square;
    Square square2;
    
    Square squares[10];

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
		
};