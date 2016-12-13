//
//  GameManager.cpp
//  BrickBreakerGame
//
//  Created by Miriam Kac on 9/16/15.
//
//

#include "GameManager.h"

void GameManager::setup(){
    
    _menuScreen.load(ofToDataPath("start_screen.JPG"));
    _endScreen.load(ofToDataPath("end_screen.JPG"));
    _showMenu = true;
    _showEnd = false;
    score = 0;
    lm.loadLevel(1);
    
}


void GameManager::update(Ball& ball, Paddle& paddle) {
    lm.update(ball, score, paddle);
    if (lm.isLevelComplete()) {
        ball.reset();
        if(lm.nextLevel() == false) {
            _showEnd = true;
        }
        
        else{
            ball.speed+=2.5;
            
        }
        
    }
}

void GameManager::draw() {
    
    if (_showMenu == true){
        ofPushStyle();
        ofSetColor(255, 255, 255);
        _menuScreen.draw(0,0, ofGetWidth(), ofGetHeight());
        ofPopStyle();
    
    } else if (_showEnd == true) {
        ofPushStyle();
        ofSetColor(255, 255, 255);
        _endScreen.draw(0,0, ofGetWidth(), ofGetHeight());
        ofPopStyle();
    } else{
        lm.draw();
    }
    
}

void GameManager::launchBall() {
    
}

void GameManager::placeBallForLaunch() {
    
}


bool GameManager::ballReadyForLaunch() {
    
}

bool GameManager::isMenuShowing(){
    return _showMenu;

}


void GameManager:: mousePressed(int mouseX, int mouseY, int button ){
    _showMenu = false;
}

bool GameManager::isGameOver(){
    
    return _showEnd;
}
