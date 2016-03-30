#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    paddle.setup();
    ball.setup();
    
    gm.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    paddle.move();
    ball.move(paddle);
    gm.update(ball);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ball.draw();
    paddle.draw();
    gm.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' ') {
        ball.launch();
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
    gm.mousePressed( mouseX,  mouseY, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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

void ofApp::onGameOver(){
    
    
    
}
