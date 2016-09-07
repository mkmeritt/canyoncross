//
//  StartScreen.hpp
//  CanyonCross
//
//  Created by Mark Meritt on 2016-02-21.
//
//

#ifndef StartScreen_hpp
#define StartScreen_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "CanyonLevel.h"

using namespace cocos2d;
using namespace cocos2d::ui;

class StartScreen: public Layer
{
private:
    ScrollingBackground* bg;
    Sprite* title;
    Sprite* start;
    
    FadeIn* fadeIn;
    FadeOut* fadeOut;
    
    Sequence* seq;
    RepeatForever* rep;
        
public:
    StartScreen();
    ~StartScreen();
    static Scene* scene();
    virtual bool init();
    
    void update(float time);
    
    bool onTouchBegan(Touch* touch, Event* evt);
    void onTouchEnded(Touch* touch, Event* evt);
    
    CREATE_FUNC(StartScreen);

};

#endif /* StartScreen_hpp */
