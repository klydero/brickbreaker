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
    score = _score;
    color = _color;
    position = _position;
    width = _width;
    height = _height;
<<<<<<< Updated upstream
<<<<<<< HEAD
<<<<<<< HEAD
    hitTimes = 0;


=======
    
    hitTimes = 0;

>>>>>>> origin/master
=======
    
    hitTimes = 0;

>>>>>>> origin/master
=======
    hitTimes = 0;


>>>>>>> Stashed changes
    isNull = false;
}

Brick::~Brick() {
    
}

void Brick::setup(){
    
    
   
    
}

//returns true if brick has been destroyed

void Brick::update(Ball& ball){
    
    if (ball.intersectsRect(ball.position.x,
                            ball.position.y,
                            ball.size,
                            position.x - width/2,
                            position.y - height/2,
                            position.x + width/2,
                            position.y + height/2)) {
        
        BRICK_SIDE brickSide = getCollisionSide(ball);
        if (brickSide == SIDE_TOP || brickSide == SIDE_BOTTOM) {
            
            
        } else {
            ball.direction.x *= -1;
        }
        

<<<<<<< Updated upstream
        hitTimes++;
        
=======

        hitTimes ++;
>>>>>>> Stashed changes
    

    }
    
    int numberOfParticles = 20;
    
    
    for (int i = 0; i < numberOfParticles; i++) {
        
        
        Particles p;
        p.position.x = position.x;
        p.position.y = position.y;
        
        p.velocity.x = ofRandom(-10, 10);
        p.velocity.y = ofRandom(-10, 10);
        
        p.drag = 1;
        
        particles.push_back(p);
        
        ball.direction.y *= -1; }
    
    
}

void Brick::draw(){
    
    ofSetColor(color);
    ofRect(position.x -width/2, position.y - height/2, width, height);
    
    
}

void Brick::hit(){
    
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

    

<<<<<<< Updated upstream
void Brick::hit(){
    

}

bool Brick::shouldDestroy() {
    return hitTimes == toughness;

}
=======
}




>>>>>>> Stashed changes

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
    
    

    bumpsound.load("sounds/bumpsound.mp3");
    bumpsound.setVolume(1.0f);
    bumpsound.play();
}

bool Brick::_isAboveLine(ofVec2f point1, ofVec2f point2, ofVec2f ballPosition) {
    return ((point2.x - point1.x) * (ballPosition.y - point1.y) - (point2.y - point1.y) * (ballPosition.x - point1.x)) > 0;
}


bool Brick::shouldDestroy(){

    
    
    if (hitTimes == toughness){
        
        return true;
    }

    return false;
    
}
