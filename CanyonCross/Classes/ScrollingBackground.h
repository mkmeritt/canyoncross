//
//  ScrollingBackground.h
//  CanyonCross
//
//  Created by The Matrix on 2015-04-29.
//  In this class we will make the parralax 
//

#ifndef __CanyonCross__ScrollingBackground__
#define __CanyonCross__ScrollingBackground__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

#endif /* defined(__CanyonCross__ScrollingBackground__) */

class ScrollingBackground : public ParallaxNode
{

public:

    static ScrollingBackground* create();
    static ScrollingBackground* createWithOnlySky();
    void updatePosition();
    void startParallax();
    

};