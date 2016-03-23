//
//  Paddle.h
//  BrickBreakerGame
//
//  Created by Miriam Kac on 9/16/15.
//
//

#ifndef __BrickBreakerGame__Paddle__
#define __BrickBreakerGame__Paddle__

#include "ofMain.h"

class Paddle {
public:
    
    void setup();
    void move();
    void draw();
    
    int width;
    int height;
    float speed;
    float bouncyness;
    ofVec2f position;
    ofColor color;

};

#endif /* defined(__BrickBreakerGame__Paddle__) */
