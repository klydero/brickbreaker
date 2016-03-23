//
//  Level.cpp
//  BrickBreakerGame
//
//  Created by bdorse on 10/28/15.
//
//

#include "Level.h"


Level::Level(vector<vector<Brick> > _rows){
    
    rows = _rows;
    
    
}

void Level::update(Ball& ball){
    for (int i = 0; i < rows.size(); i++) {
        for(int j = 0; j < rows[i].size(); j++) {
            rows[i][j].update(ball);
        }
    }
}

void Level::draw(){
    for (int i = 0; i < rows.size(); i++) {
        for(int j = 0; j < rows[i].size(); j++) {
            rows[i][j].draw();
        }
    }
    
}

Level::~Level(){
    
}