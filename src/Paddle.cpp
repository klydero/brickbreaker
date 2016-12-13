//
//  Paddle.cpp
//  BrickBreakerGame
//
//  Created by Miriam Kac on 9/16/15.
//
//

#include "Paddle.h"

void Paddle::setup() {

    width  = 80;
    height = 15;
    speed = 15;
    color.set(255, 64, 91);
    position.set(ofGetWidth()/2, ofGetHeight() - 30);
}

void Paddle::move() {
    
    if (ofGetKeyPressed(OF_KEY_RIGHT) && position.x + width/2 <= ofGetWidth()) {
        position.x += speed;
    }
    
    if (ofGetKeyPressed(OF_KEY_LEFT) && position.x - width/2 >= 0) {
        position.x -= speed;
    }
    
}

void Paddle::draw() {
    ofPushStyle();
        ofSetColor(color);
        ofRect(position.x - width/2, position.y - height/2, width, height);
    ofPopStyle();
}