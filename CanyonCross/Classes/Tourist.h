//
//  Tourist.h
//  CanyonCross
//
//  Created by The Matrix on 2015-04-29.
//  Deriving from the draggable sprites class, we make this
//  to create tourists that will be carried on the back of
//  the player

#ifndef __CanyonCross__Tourist__
#define __CanyonCross__Tourist__

#include <stdio.h>
#include "cocos2d.h"
#include "Player.h"

using namespace cocos2d;



class Tourist:public Sprite
{
    
    enum type {wufamily, oldman, richpaul, carlashley, bigchestbarrie, berniceandbernie};
    
    
private:
    type touristType;
    
    PhysicsBody* phys;

    
public:
    
    virtual void update(float dt) override;
    
    void animate();
    
    Sprite* tSprite;

    void jump();
    
    CREATE_FUNC(Tourist);
    
    virtual bool init() override;
    
    Tourist();
    ~Tourist();

    
    virtual bool onTouchBegan(Touch* touch, Event* evt);

    
};
#endif /* defined(__CanyonCross__Tourist__) */