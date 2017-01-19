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
    void update(Ball& ball, Paddle& paddle);
    void draw();
    void launchBall();
    void placeBallForLaunch();
    
    bool ballReadyForLaunch();
    
    bool isMenuShowing();
    
    void mousePressed(int x, int y, int button);
    
    bool isGameOver();
    
    int score;
    LevelManager lm;
    
    void brickHit(int x, int y);
    
protected:
    std::vector<Particles>particles;

    ofImage _menuScreen;
    ofImage _endScreen;
    
    bool _showMenu;
    bool _showEnd;
    
};


#endif /* defined(__BrickBreakerGame__GameManager__) */
