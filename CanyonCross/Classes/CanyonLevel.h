//
//  CanyonLevel.h
//  CanyonCross
//
//  Created by The Matrix on 2015-04-29.
//  Canyon Level
//

#ifndef __CanyonCross__CanyonLevel__
#define __CanyonCross__CanyonLevel__

#define PTM_RATIO 32.0


#include <stdio.h>
#include "Player.h"
#include "ScrollingBackground.h"
#include "RopeFactory.h"
#include "TouristFactory.hpp"
#include "BirdFactory.hpp"

using namespace cocos2d;

#endif /* defined(__CanyonCross__CanyonLevel__) */

class CanyonLevel:public Layer
{
private:
    Player* character;
    ScrollingBackground* parallax;
    BirdFactory* birdFactory;
    RopeFactory* ropeFactory;
    TouristFactory* touristFactory;
    Size siz;
    Camera* camera;
            
    
public:
    ~CanyonLevel();
    static Scene* createScene();
  
    virtual bool init();
    
    void update(float time);
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    virtual bool onTouchBegan(Touch* touch, Event* evt);
    
    virtual void onTouchMoved(Touch* touch, Event* evt);
    
    virtual void onTouchEnded(Touch* touch, Event* evt);

    
    // implement the "static create()" method manually
    CREATE_FUNC(CanyonLevel);
    
};