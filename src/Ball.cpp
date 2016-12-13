    //
//  Ball.cpp
//  BrickBreakerGame
//
//  Created by Miriam Kac on 9/16/15.
//
//

#include "Ball.h"

void Ball::setup() {
    
    color.set(138,0,184);
    size = 20;
    speed = 6;
    position.set(ofGetWidth(), ofGetHeight());
    direction.set(1, 1);
}

void Ball::move(const Paddle& paddle ) {
    
    if (!_resetting) {
    
        if (position.x + size / 2 >= ofGetWidth() ||
            position.x - size / 2 <= 0) {
            direction.x *= -1;
        }
        
        if (position.y - size / 2 <= 0) {
            direction.y *= -1;
        }
        
        if (intersectsRect(   position.x,
                              position.y,
                              size * 0.5,
                              paddle.position.x - paddle.width * 0.5,
                              paddle.position.y - paddle.height * 0.5,
                              paddle.position.x + paddle.width * 0.5,
                              paddle.position.y + paddle.height * 0.5)) {
            
            int numberOfParticles = 20;
            
            
            for (int i = 0; i < numberOfParticles; i++) {
                
                
                Particles p;
                p.position.x = position.x;
                p.position.y = position.y;
                
                p.velocity.x = ofRandom(-10, 10);
                p.velocity.y = ofRandom(-10, 10);
                
                p.drag = 1;
                
                particles.push_back(p);
                
                
            }

            
            direction.y *= -1;
            
        }
        
        position.x += speed * direction.x;
        position.y += speed * direction.y;
    
    } else {
        
        position.x = paddle.position.x;
        position.y = paddle.position.y - paddle.height/2  - size/2;
        
    }
    
    if (position.y + size/2 >= ofGetHeight()) {
        reset();
    }
    
}

void Ball::draw() {
    
    auto particleIterator = particles.begin();
    
    
    
    while (particleIterator != particles.end())
        
    {
        
        particleIterator->update();
        
        
        
        if (particleIterator->age > ofRandom(10, 50))
            
        {
            
            particleIterator = particles.erase(particleIterator);
            
        }
        
        else
            
        {
            
            ofDrawRectangle(particleIterator-> position.x, particleIterator->position.y, 20, 20);
            
            ++particleIterator;
            
        }
        
    }
    

    
    ofPushStyle();
    ofSetColor(color);
    ofEllipse(position.x, position.y, size, size);
    ofPopStyle();
}

void Ball::reset() {
    _resetting = true;
}

void Ball::launch() {
    _resetting = false;
}

bool Ball::intersectsRect(float cx, float cy, float radius, float left, float top, float right, float bottom) const
{
    float closestX = (cx < left ? left : (cx > right ? right : cx));
    float closestY = (cy < top ? top : (cy > bottom ? bottom : cy));
    float dx = closestX - cx;
    float dy = closestY - cy;
    
    return ( dx * dx + dy * dy ) <= radius * radius;
}



