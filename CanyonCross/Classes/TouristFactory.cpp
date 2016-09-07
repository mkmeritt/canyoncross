//
//  TouristFactory.cpp
//  CanyonCross
//
//  Created by Mark Meritt on 2016-03-03.
//
//

#include "TouristFactory.hpp"

TouristFactory::TouristFactory()
{
    slots = new TouristSlot();
    
    slots->drawSlots();
    
    addChild(slots);
    
    tourists[0] = new Tourist();
    tourists[0]->init();
    tourists[0]->tSprite->setScale(0.5);
    
    tourists[1] = new Tourist();
    tourists[1]->init();
    tourists[1]->tSprite->setScale(0.5);
    
    tourists[2] = new Tourist();
    tourists[2]->init();
    tourists[2]->tSprite->setScale(0.5);
    
}

void TouristFactory::addTourist()
{
    tourists[0]->tSprite->setPosition(slots->getSlot1Center());
    addChild(tourists[0]->tSprite);
    
    tourists[1]->tSprite->setPosition(slots->getSlot2Center());
    addChild(tourists[1]->tSprite);
    
    tourists[2]->tSprite->setPosition(slots->getSlot3Center());
    addChild(tourists[2]->tSprite);

}

void TouristFactory::removeTourist()
{
    
}