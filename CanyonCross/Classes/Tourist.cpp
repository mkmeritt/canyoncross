//
//  Tourist.cpp
//  CanyonCross
//
//  Created by The Matrix on 2015-04-29.
//
//

#include "Tourist.h"

Tourist::Tourist()
{
  int num = rand() % 5 - 1;
    
    switch (num) {
        case 1:
            touristType = berniceandbernie;
            break;
            
        case 2:
            touristType = bigchestbarrie;
            break;
            
        case 3:
            touristType = carlashley;
            break;
            
        case 4:
            touristType = oldman;
            break;
            
        case 5:
            touristType = wufamily;
            break;
    }
    
}

bool Tourist::init()
{
    if(touristType == berniceandbernie)
        tSprite = Sprite::create("Tourists/berniceandbernie.png");
    
    
    if(touristType == bigchestbarrie)
        tSprite = Sprite::create("Tourists/bigchestbarrie.png");
    
    if(touristType == carlashley)
        tSprite = Sprite::create("Tourists/carlandashley.png");
    
    if(touristType == oldman)
        tSprite = Sprite::create("Tourists/oldman.png");
    
    if(touristType == wufamily)
        tSprite = Sprite::create("Tourists/woofamily.png");
        
    phys = PhysicsBody::createBox(tSprite->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT, Vec2(0, 50));
    phys->setMass(100.0f);
    phys->setDynamic(true);
    phys->setRotationEnable(false);
    phys->setGravityEnable(true);
    tSprite->setPhysicsBody(phys);
    
    
    return true;
}

void Tourist::animate()
{
    
}

void Tourist::jump()
{
    auto jump = JumpBy::create(0.5f, tSprite->getPosition(), 1.0f, 1);
    
    tSprite->runAction(jump);
}

bool Tourist::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *evt)
{
    this->jump();
    
    return true;
}

void Tourist::update(float dt)
{
    
}

Tourist::~Tourist()
{
    
}