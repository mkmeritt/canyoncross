//
//  BirdFactory.hpp
//  CanyonCross
//
//  Created by Mark Meritt on 2016-02-21.
//
//

#ifndef BirdFactory_hpp
#define BirdFactory_hpp

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include "cocos2d.h"
#include "Bird.h"
#include "TouristSlot.hpp"

using namespace cocos2d;
using namespace std;

class BirdFactory: public Sprite
{
private:
    
    vector<Point> leftPoints;
    vector<Point> targets;
    vector<Point> rightPoints;
    
    vector<Point> path;
    
    float time;
    
    char n = 0;
    
public:
    
    void update(float dt);
    
    void buildPath();
    
    void spawnBird(float num);
    
    void removeBird(float num);
    
    BirdFactory();
    ~BirdFactory();
    
};
#endif /* BirdFactory_hpp */
