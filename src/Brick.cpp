#include "Brick.h"
#include "GameManager.h"


Brick::Brick(GameManager* _gm ,int _toughness, int _score, ofColor _color, ofVec2f _position, int _width, int _height){
    gm = _gm;
    toughness = _toughness;
    score = _score;
    color = _color;
    position = _position;
    width = _width;
    height = _height;
<<<<<<< Updated upstream


    hitTimes = 0;



    hitTimes = 0;




=======
    
    
    hitTimes = 0;
    
    
    
    hitTimes = 0;
    
    
    
    
>>>>>>> Stashed changes
    isNull = false;
    
    
    
}

Brick::~Brick() {
    
}

void Brick::setup(){
    
    brickhitsound.load("sounds/bumpsound.mp3");
    brickhitsound.setVolume(1.0f);
    
    
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
        
        
        gm->brickHit(ball.position.x, ball.position.y);
        
        
        BRICK_SIDE brickSide = getCollisionSide(ball);
        if (brickSide == SIDE_TOP || brickSide == SIDE_BOTTOM) {
            
            
            
            
        } else {
            ball.direction.x *= -1;
        }
        
<<<<<<< Updated upstream


        hitTimes++;
        

    

    }
    
    

    for (int i = 0; i < numberOfParticles; i++) {
=======
>>>>>>> Stashed changes
        
        
        hitTimes++;
        
        
        
        
<<<<<<< Updated upstream
        ball.direction.y *= -1; }

=======
    }
    
    
    
   
    
>>>>>>> Stashed changes
    
}


void Brick::draw(){
    
    ofSetColor(color);
    ofRect(position.x -width/2, position.y - height/2, width, height);
    
    
    
<<<<<<< Updated upstream


=======
    
    
>>>>>>> Stashed changes
    
}

void Brick::hit(){
    
    
<<<<<<< Updated upstream
   
   

=======
    
    
    
>>>>>>> Stashed changes
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


bool Brick::shouldDestroy(){
    
    
    
    if (hitTimes >= toughness){
        
        
        
        return true;
        
    }
    
    return false;
    
}