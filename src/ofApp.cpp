#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
   // ofSetDataPathRoot("../bin/data/");
    
    //ofBackgroundGradient(ofColor::coral, ofColor::lavender);
    paddle.setup();
    ball.setup();

    gm.setup();
    scoreFont.load("Bitwise.ttf", 20);
    backgroundImage.load("background.jpg");
    
    brickBreakerMusic.load("sounds/brickbreakeraudio.mp3");
    brickBreakerMusic.setVolume(0.4f);
    brickBreakerMusic.play();
    brickBreakerMusic.setLoop(true);
    
    clicksound.load("startsound.mp3");
    clicksound.setVolume(.0f);
//
    
    endTime = false;
    startTime = ofGetElapsedTimeMillis();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    paddle.move();
    ball.move(paddle);

    gm.update(ball, paddle);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    backgroundImage.draw(0,0);
    
    
    ball.draw();
    paddle.draw();
    gm.draw();
    
    ofSetColor(255);
    scoreFont.drawString("Score: " + ofToString(gm.score), 20, 20);
    
    float timer = ofGetElapsedTimeMillis() - startTime;
    
    if (timer <= endTime){
        
        endTime = true;
    }
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
    if (gm.isGameOver()){
        gm.lm.currentLevel = 0;
        setup();
    }
    
    //clicksound.play();
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

 
