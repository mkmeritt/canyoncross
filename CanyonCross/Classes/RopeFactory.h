//
//  RopeFactory.h
//  CanyonCross
//
//  Created by The Matrix on 2015-07-20.
//
//

#ifndef __CanyonCross__RopeFactory__
#define __CanyonCross__RopeFactory__

#include <stdio.h>
#include <iostream>
#include <list>
#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

class RopeFactory: public Sprite
{
private:
    int num;
    
    float x;
    
    Sprite* rockSprite;
    
    ////ROPE
    Sprite* ropeSprite;
    
    Vector<Sprite*> *rockSpriteList;
    
    Vec2 *startPos;
    
    bool neverDid = false;
    
    Size s1, s2, s3;
    
    Size area;

    bool reset = false;   //reset rock position

    bool factoryON = true;
        
public:
    
    RopeFactory();
    ~RopeFactory();

    Sprite* getRock();
  
    int getNum();
        
    void factory(int rockType);
    
    void singleRock();
    
    void addRocks(float num);
    
    void deleteRocks(float num);
    
    void rockMove();
    
    void update(float dt);
    
    void factoryUpdate(float dt);
    
  //  CREATE_FUNC(RopeFactory);

};

#endif /* defined(__CanyonCross__RopeFactory__) */
