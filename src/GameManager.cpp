//
//  GameManager.cpp
//  BrickBreakerGame
//
//  Created by Miriam Kac on 9/16/15.
//
//

#include "GameManager.h"

void GameManager::setup(){
    
    _menuScreen.load("IMG_3093.JPG");
    _showMenu = true;
    lm.loadLevel(1);
    
}


void GameManager::update(Ball& ball) {
    lm.update(ball);
}

void GameManager::draw() {
    if (_showMenu == true){
        ofPushStyle();
        ofSetColor(255, 255, 255);
        _menuScreen.draw(0,0, ofGetWidth(), ofGetHeight());
        ofPopStyle();
    
    }
    else{
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
