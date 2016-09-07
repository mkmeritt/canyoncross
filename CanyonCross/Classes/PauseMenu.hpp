//
//  PauseMenu.hpp
//  CanyonCross
//
//  Created by Mark Meritt on 2016-02-21.
//
//

#ifndef PauseMenu_hpp
#define PauseMenu_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace cocos2d::ui;

class PauseMenu: public Layer
{
private:
    Sprite mainMenu;
    Button* play;
    Button* highScore;
    Button* restart;
    Button* exit;
    
public:
    
};
#endif /* PauseMenu_hpp */
