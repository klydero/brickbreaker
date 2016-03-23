#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include "GameManager.h"

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void onGameOver();
    
        Ball ball;
        Paddle paddle;
        Brick brick;
        GameManager gm;

};
