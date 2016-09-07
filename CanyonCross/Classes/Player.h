//
//  Player.h
//  CanyonCross
//
//  Created by The Matrix on 2015-04-29.
//  In this class we will create the main character - the biker
//

#ifndef __CanyonCross__Player__
#define __CanyonCross__Player__

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;


class Player : public Sprite
{
private:
    Point position;
    
    SpriteBatchNode* spritebatch;
    SpriteFrameCache* cache;

    PhysicsBody* phys;

    Sprite* pSprite;
    
    void animateCycle(char cycle);
    
    virtual bool init() override;
    
public:
    
    Player();
    ~Player();
    
    Sprite* getSprite();
    
    virtual void update(float dt) override;
        
  
        
    CREATE_FUNC(Player);

};

#endif /* defined(__CanyonCross__Player__) */


