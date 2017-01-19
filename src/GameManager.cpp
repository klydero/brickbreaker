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
    
    lm.gm = this;
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
    
    
    auto particleIterator = particles.begin();
    
    
    
    while (particleIterator != particles.end())
        
    {
        
        particleIterator->update();
        
        
        
        if (particleIterator->age > ofRandom(40, 50))
            
        {
            
            particleIterator = particles.erase(particleIterator);
            
        }
        
        else
            
        {
            
            //ofDrawRectangle(particleIterator-> position.x, particleIterator->position.y, 20, 20);
            
            ++particleIterator;
            
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
    
    
    
    
    auto particleIterator = particles.begin();
    
    
    
    while (particleIterator != particles.end())
        
    {
        
        particleIterator->update();
        
        
        
        if (particleIterator->age > ofRandom(40, 90))
            
        {
            
            particleIterator = particles.erase(particleIterator);
            
        }
        
        else
            
        {
            
            ofDrawCircle(particleIterator-> position.x, particleIterator->position.y, 10, 10);
            
            ++particleIterator;
            
        }
        
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


void GameManager::brickHit(int x, int y)
{
    cout << "brick was hit ... " << endl;
    
    int numberOfParticles = 20;
    
    for (int i = 0; i < numberOfParticles; i++) {
        
        
        Particles p;
        p.position.x = x;
        p.position.y = y;
        
        p.velocity.x = ofRandom(-10, 10);
        p.velocity.y = ofRandom(-10, 10);
        
        p.drag = 1;
        
        particles.push_back(p);
        
//        ball.direction.y *= -1;
        
    }
}
