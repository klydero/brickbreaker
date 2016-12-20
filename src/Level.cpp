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

<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
            if (rows[i][j].shouldDestroy()) {
                 score += rows[i][j].score;
                rows[i].erase(rows[i].begin()+j);
                cout << score << endl;
            }

<<<<<<< Updated upstream
            if (rows[i][j].shouldDestroy()){
                rows[i].erase(rows[i].begin()+ j);
                
                
            }
<<<<<<< HEAD
=======
            
<<<<<<< HEAD
>>>>>>> origin/master
=======
>>>>>>> origin/master
=======

//            if (rows[i][j].shouldDestroy()){
//                rows[i].erase(rows[i].begin()+ j);
//                
//                
//            }
    
      
                
                
            }
>>>>>>> Stashed changes

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
