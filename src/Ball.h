//
//  Ball.h
//  BrickBreakerGame
//
//  Created by Miriam Kac on 9/16/15.
//
//

#ifndef __BrickBreakerGame__Ball__
#define __BrickBreakerGame__Ball__

#include "ofMain.h"
#include "Paddle.h"
#include "ofBaseApp.h"
#include "Particles.h"

class Ball{
    
public:
    
    void setup();
    void move(const Paddle& paddle);
    void draw();
    void reset();
    void launch();
    
    void registerEvents(ofBaseApp* app);
    
    float speed;
    int size;
    ofVec2f position;
    ofVec2f direction;
    ofColor color;
    float bounciness;
    std::vector<Particles> particles;
    
    
    bool intersectsRect(float cx,
                        float cy,
                        float radius,
                        float left,
                        float top,
                        float right,
                        float bottom) const;
    
    
    protected:
    
    bool _resetting;
};

#endif /* defined(__BrickBreakerGame__Ball__) */
