//
//  LevelManager.h
//  BrickBreakerGame
//
//  Created by bdorse on 10/28/15.
//
//

#ifndef __BrickBreakerGame__LevelManager__
#define __BrickBreakerGame__LevelManager__

#include "ofMain.h"
#include "Level.h"

class LevelManager{
    
public:
    
    
    LevelManager();
    ~LevelManager();
    
    void draw();
    
    int currentLevel;
    bool nextLevel();
    bool loadLevel(int levelNumber);
    bool isLevelComplete();
    void update(Ball& ball, int& score, Paddle& paddle);
    
    
private:
    bool isGameOver;
    vector <Level> levels;
    
};




#endif /* defined(__BrickBreakerGame__LevelManager__) */
