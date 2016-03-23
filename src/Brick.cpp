//
//  Bricks.cpp
//  BrickBreakerGame
//
//  Created by Miriam Kac on 9/16/15.
//
//

#include "Brick.h"

Brick::Brick(int _toughness, int _score, ofColor _color, ofVec2f _position, int _width, int _height){
    toughness = _toughness;
    color = _color;
    position = _position;
    width = _width;
    height = _height;
    
    isNull = false;
}

Brick::~Brick() {
    
}

void Brick::setup(){
    
}

void Brick::update(Ball& ball){
    
    if (ball.intersectsRect(ball.position.x,
                            ball.position.y,
                            ball.size,
                            position.x - width/2,
                            position.y - height/2,
                            position.x + width/2,
                            position.y + height/2)) {
        
        BRICK_SIDE brickSide = getCollisionSide(ball);
        cout << brickSide << endl;
        if (brickSide == SIDE_TOP || brickSide == SIDE_BOTTOM) {
            ball.direction.y *= -1;
        } else {
            ball.direction.x *= -1;
        }
    }
}

void Brick::draw(){
    
    ofSetColor(color);
    ofRect(position.x -width/2, position.y - height/2, width, height);
    
}

void Brick::hit(){
    
}

Brick::BRICK_SIDE Brick::getCollisionSide(const Ball& ball) {
    
    //A == topLeft
    //B == topRight
    //C == bottomRight
    //D == bottomLeft
    
    bool isAboveAC = _isAboveLine(ofVec2f(position.x - width/2, position.y - height/2),
                                  ofVec2f(position.x + width/2, position.y + height/2),
                                  ball.position);
    
    bool isAboveDB = _isAboveLine(ofVec2f(position.x - width/2, position.y + height/2),
                                  ofVec2f(position.x + width/2, position.y - height/2),
                                  ball.position);
    
    if (isAboveAC)
    {
        if (isAboveDB)
        {
            //top edge has intersected
            return SIDE_TOP;
        }
        else
        {
            //right edge intersected
            return SIDE_RIGHT;
        }
    }
    else
    {
        if (isAboveDB)
        {
            //left edge has intersected
            return SIDE_LEFT;
        }
        else
        {
            //bottom edge intersected
            return SIDE_BOTTOM;
        }
    }
}

bool Brick::_isAboveLine(ofVec2f point1, ofVec2f point2, ofVec2f ballPosition) {
    return ((point2.x - point1.x) * (ballPosition.y - point1.y) - (point2.y - point1.y) * (ballPosition.x - point1.x)) > 0;
}

