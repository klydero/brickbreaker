//
//  Particles.hpp
//  particleImages
//
//  Created by Miriam Kac on 10/5/16.
//
//

#include "ofMain.h"

#ifndef Particles_hpp
#define Particles_hpp

#include <stdio.h>


class Particles{
    
    public:
    
    void setup();
    void update();
    void draw();
    
    ofVec3f previousPosition;
    
    ofVec3f velocity;
    ofVec3f position;
    ofVec3f accelleration;
    
    float drag = 0.95;
    
    uint64_t age = 0;
    
};











#endif /* Particles_hpp */
