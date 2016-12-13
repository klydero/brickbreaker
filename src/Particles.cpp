//
//  Particles.cpp
//  particleImages
//
//  Created by Miriam Kac on 10/5/16.
//
//

#include "Particles.h"



void Particles::setup(){
    
    
    
}


void Particles::update(){
    
    previousPosition = position;
    
    velocity += accelleration;
    velocity *= drag;
    position += velocity;
    age++;
    
    
    
}

void Particles::draw(){
    
    
    //ofDrawEllipse(position, 2, 2);
    
    ofDrawLine(previousPosition, position);
    
    
    
}