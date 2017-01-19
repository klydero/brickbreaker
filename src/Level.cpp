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
void Level::update(Ball& ball, int& score, Paddle& paddle){
    for (int i = 0; i < rows.size(); i++) {
        for(int j = 0; j < rows[i].size(); j++) {
            rows[i][j].update(ball);
        }
    }
    
    for (int i = 0; i < rows.size(); i++) {
        for(int j = 0; j < rows[i].size(); j++) {
            if (rows[i][j].shouldDestroy()) {
                score += rows[i][j].score;
                rows[i].erase(rows[i].begin() + j); //I think that this part of the code is loading the next level but maybe it can't find the next level so the game is crashing but im not sure.
                cout << score << endl;
            }
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
