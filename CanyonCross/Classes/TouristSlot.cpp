//
//  TouristSlot.cpp
//  CanyonCross
//
//  Created by Mark Meritt on 2016-03-05.
//
//

#include "TouristSlot.hpp"

TouristSlot::TouristSlot()
{
    occupied = false;
    
    startVec = Vec2(Director::getInstance()->getInstance()->getVisibleSize().width / 2 - 60, Director::getInstance()->getVisibleSize().height/2 - 270);
    
    endVec = Vec2(startVec.x + 300, startVec.y + 200);
}

void TouristSlot::drawSlots()
{
    slot1 = DrawNode::create();
    
    slot1->drawRect(startVec, endVec, Color4F::BLUE);
    
    addChild(slot1, 10);
    
    slot2 = DrawNode::create();
    
    slot2->drawRect(startVec, endVec, Color4F::RED);
    
    slot2->setPosition(slot1->getPositionX(), slot1->getPositionY() + 210);
    
    addChild(slot2, 10);

    slot3 = DrawNode::create();
    
    slot3->drawRect(startVec, endVec, Color4F::YELLOW);
    
    slot3->setPosition(slot2->getPositionX(), slot2->getPositionY() + 210);
    
    addChild(slot3, 10);


}

Vec2 TouristSlot::getSlot1Center(){
    
    Vec2 center = startVec.getMidpoint(endVec);
    
    return center;
    
}

Vec2 TouristSlot::getSlot2Center(){
    
    Vec2 newEndVec = Vec2(endVec.x, endVec.y + slot2Pos.y);
    
    Vec2 center = startVec.getMidpoint(newEndVec);
    
    return center;
    
}

Vec2 TouristSlot::getSlot3Center(){
    
    Vec2 newEndVec = Vec2(endVec.x, endVec.y + endVec.y + slot3Pos.y);
    
    Vec2 center = startVec.getMidpoint(newEndVec);
    
    return center;
    
}
