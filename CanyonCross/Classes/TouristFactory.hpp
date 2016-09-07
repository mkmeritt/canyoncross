//
//  TouristFactory.hpp
//  CanyonCross
//
//  Created by Mark Meritt on 2016-03-03.
//
//

#ifndef TouristFactory_hpp
#define TouristFactory_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Tourist.h"
#include "TouristSlot.hpp"

using namespace cocos2d;

const int SIZE = 3;

class TouristFactory:public Sprite
{
private:
    
    TouristSlot* slots;
    
    Tourist* tourists[SIZE];

    
public:
    
    TouristFactory();
    
    void addTourist();
    
    void removeTourist();
    
};

#endif /* TouristFactory_hpp */
