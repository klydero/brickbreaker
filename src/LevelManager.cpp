//
//  LevelManager.cpp
//  BrickBreakerGame
//
//  Created by bdorse on 10/28/15.
//
//

#include "LevelManager.h"


LevelManager::LevelManager() {
    currentLevel = 0;
}

LevelManager::~LevelManager() {
    
}

void LevelManager::update(Ball& ball) {
    levels[currentLevel-1].update(ball);
}

void LevelManager::draw(){
    levels[currentLevel-1].draw();
}

bool LevelManager::loadLevel(int levelNumber){
    
    currentLevel = levelNumber;

    vector<string> lines = ofSplitString(ofBufferFromFile("level" + ofToString(levelNumber) + ".txt").getText(), "\n");
    vector<vector<Brick> > rows;
    int brickWidth = ofGetWidth()/10;
    int brickHeight = ofGetHeight()/15;
    
    
    for(int i = 0; i < lines.size(); i++){
        
        string line = lines[i];
        vector<Brick> row;
        
        for(int j = 0; j<lines[i].size();j++){
            
            char block = line[j];
            
            if (block == '0'){
                
            }
            if (block == '1'){
                row.push_back(Brick(1, 10, ofColor::red, ofVec2f(((j+1)*brickWidth) - brickWidth / 2,((i+1)*brickHeight) - brickHeight / 2), brickWidth, brickHeight));
            }
            if (block == '2'){
                row.push_back(Brick(2, 20, ofColor::blueViolet, ofVec2f((j+1)*brickWidth - brickWidth / 2,(i+1)*brickHeight - brickHeight / 2), brickWidth, brickHeight));
            }
            if (block == '3'){
                row.push_back(Brick(3, 50, ofColor::purple, ofVec2f((j+1)*brickWidth - brickWidth / 2,(i+1)*brickHeight- brickHeight / 2), brickWidth, brickHeight));
            }
            if (block == '4'){
                row.push_back(Brick(4, 100, ofColor::chocolate, ofVec2f((j+1)*brickWidth - brickWidth / 2,(i+1)*brickHeight - brickHeight / 2), brickWidth, brickHeight));
            }
        }
        
        rows.push_back(row);
        
    }
    
    levels.push_back(Level(rows));
}


void LevelManager::nextLevel(){
    loadLevel(currentLevel+1);
}

