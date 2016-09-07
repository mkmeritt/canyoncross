//
//  TouristSlot.hpp
//  CanyonCross
//
//  Created by Mark Meritt on 2016-03-05.
//
//

#ifndef TouristSlot_hpp
#define TouristSlot_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Player.h"

using namespace cocos2d;

static Point slot1Pos = Point(0, 0);
static Point slot2Pos = Point(0, 420);
static Point slot3Pos = Point(0, 630);

class TouristSlot: public Layer
{
private:

    bool occupied;
    
    Vec2 startVec;
    Vec2 endVec;
public:
    
    TouristSlot();
    
    void drawSlots();
    
    DrawNode* slot1;
    DrawNode* slot2;
    DrawNode* slot3;

    
    Vec2 getSlot1Center();
    
    Vec2 getSlot2Center();
    
    Vec2 getSlot3Center();
};

#endif /* TouristSlot_hpp */
