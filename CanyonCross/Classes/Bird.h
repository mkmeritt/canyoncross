//
//  Bird.h
//  CanyonCross
//
//  Created by The Matrix on 2015-04-29.
//  The bird class contains the enemy birds
//  This class will need a hawk, eagle and vulture class
//  derived from it

#ifndef __CanyonCross__Bird__
#define __CanyonCross__Bird__

#include <stdio.h>
#include "cocos2d.h"
#include "TouristSlot.hpp"

using namespace cocos2d;

#endif /* defined(__CanyonCross__Bird__) */

class Bird:public Sprite
{
   
    enum colour {blue, green, orange, purple, yellow};
    
private:
    
    colour birdColour;
    
    Sprite* bSprite;
    
    Vec2 position;
    
    
    SpriteBatchNode* spritebatch;
    SpriteFrameCache* cache;
    
    ccBezierConfig bezier;
    
    TouristSlot* slots;
    
    void animate(char ch);
    
    virtual bool init() override;

public:
    
    void attack(Point ctrlPoint1, Point ctrlPoint2, Point end, float time);
    
    virtual void update(float dt) override;
    
    bool crossed;
    
    CREATE_FUNC(Bird);

    Bird();
    ~Bird();

 
};