//
//  Bricks.h
//  BrickBreakerGame
//
//  Created by Miriam Kac on 9/16/15.
//
//

#ifndef __BrickBreakerGame__Bricks__
#define __BrickBreakerGame__Bricks__

#include "ofMain.h"
#include "Ball.h"


class Brick {
public:
    
    enum BRICK_SIDE {
        SIDE_LEFT,
        SIDE_RIGHT,
        SIDE_TOP,
        SIDE_BOTTOM
    };
    
    Brick(){isNull = true;};
    Brick(int _toughness, int _score, ofColor _color, ofVec2f _position, int _width, int _height);
    ~Brick();
    
    void hit();
    void setup();
    void update(Ball& ball);
    void draw();
    BRICK_SIDE getCollisionSide(const Ball& ball);
    
    int toughness;
    ofColor color;
    ofVec2f position;
    int width;
    int height;
    int score;
    
    bool isNull;
    bool shouldDestroy();
    
    
protected:
    int hitTimes;
    
    bool _isAboveLine(ofVec2f point1, ofVec2f point2, ofVec2f ballPosition);
    
    
    
};




#endif /* defined(__BrickBreakerGame__Bricks__) */