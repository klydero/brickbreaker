//
//  Level.h
//  BrickBreakerGame
//
//  Created by bdorse on 10/28/15.
//
//

#ifndef __BrickBreakerGame__Level__
#define __BrickBreakerGame__Level__

#include "ofMain.h"
#include "Brick.h"

class Level {

public:

    Level(vector<vector<Brick> > _rows);
    ~Level();
    
    
    void update(Ball& ball);
    void draw();

    vector<vector<Brick> > rows;
    
};



#endif /* defined(__BrickBreakerGame__Level__) */
