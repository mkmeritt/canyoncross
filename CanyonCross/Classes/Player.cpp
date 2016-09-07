//
//  Player.cpp
//  CanyonCross
//
//  Created by The Matrix on 2015-04-29.
//
//

#include "Player.h"
#define PTM_RATIO 32.0

Player::Player()
{
    init();
}

bool Player::init()
{
   
    position = Point(Director::getInstance()->getVisibleSize().width/2 + 60, Director::getInstance()->getVisibleSize().height/2 - 400);

    animateCycle(1);
    
    Size s = Size(320, 300);
    
    phys = PhysicsBody::createBox(s, PHYSICSBODY_MATERIAL_DEFAULT, Vec2(-500, 0));
    phys->setMass(100.0f);
    phys->setDynamic(true);
    phys->setRotationEnable(false);
    phys->setGravityEnable(true);
    pSprite->setPhysicsBody(phys);
    
    return true;
}

void Player::animateCycle(char cycle)
{
    char str[100] = {0};
    sprintf(str, "Player/cycle00%1d/cycle0%1d.png", cycle, cycle);
    spritebatch = SpriteBatchNode::create(str);
    SpriteFrameCache* cache = SpriteFrameCache::getInstance();
    
    char str2[100] = {0};
    sprintf(str2, "Player/cycle00%1d/cycle0%1d.plist", cycle, cycle);
    cache->addSpriteFramesWithFile(str2);
    
    char str3[100] = {0};
    sprintf(str3, "cycle%1d",cycle);
    pSprite = Sprite::createWithSpriteFrameName(str3);
    pSprite->setAnchorPoint(Vec2(0.5, 0.5));
    pSprite->setScale(0.8f);
    pSprite->setPosition(position);
    spritebatch->setPosition(position);
    spritebatch->setScale(0.8f);
    spritebatch->addChild(pSprite);
    this->addChild(spritebatch, 50);
    
    Vector<SpriteFrame*> animFrames(31);
    
    for(int i = 2; i < 32; i++)
    {
        sprintf(str3, "cycle%1d", i);
        SpriteFrame* frame = cache->getSpriteFrameByName(str3);
        animFrames.pushBack(frame);
    }
    
    Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
    pSprite->runAction(RepeatForever::create(Animate::create(animation)));
    
}

Sprite* Player::getSprite()
{
    return pSprite;
}

void Player::update(float dt)
{

}

Player::~Player()
{
    pSprite->release();
}


