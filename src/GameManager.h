//
//  GameManager.h
//  BrickBreakerGame
//
//  Created by Miriam Kac on 9/16/15.
//
//

#ifndef __BrickBreakerGame__GameManager__
#define __BrickBreakerGame__GameManager__

#include "ofMain.h"
#include "LevelManager.h"


class GameManager {
    
    
    public:
    
    void setup();
    void update(Ball& ball);
    void draw();
    void launchBall();
    void placeBallForLaunch();
    
    bool ballReadyForLaunch();
    
    bool isMenuShowing();
    
    void mousePressed(int x, int y, int button);
    
    ofEvent<void> gameOverEvent;
    
    LevelManager lm;
    
protected:
    
    ofImage _menuScreen;
    
    bool _showMenu;
    
};


#endif /* defined(__BrickBreakerGame__GameManager__) */
