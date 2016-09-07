//
//  Bird.cpp
//  CanyonCross
//
//  Created by The Matrix on 2015-04-29.
//
//

#include "Bird.h"

Bird::Bird()
{
    init();
    
    crossed = false;
}

bool Bird::init()
{
    int num = rand() % 4;
    
    switch (num) {
        case 0:
            birdColour = blue;
            break;
            
        case 1:
            birdColour = green;
            break;
            
        case 2:
            birdColour = orange;
            break;
            
        case 3:
            birdColour = purple;
            break;
            
        case 4:
            birdColour = yellow;
            break;
    }
    
    animate(0);
    
    return true;

}

void Bird::animate(char ch)
{
    SpriteFrameCache* cache = SpriteFrameCache::getInstance();
    
    if(birdColour == blue) {
        spritebatch = SpriteBatchNode::create("Birds/Blue/bluebird.png");
        cache->addSpriteFramesWithFile("Birds/Blue/bluebird.plist");
    }
    
    if(birdColour == green)
    {
        spritebatch = SpriteBatchNode::create("Birds/Green/greenbird.png");
        cache->addSpriteFramesWithFile("Birds/Green/greenbird.plist");
    }
    
    if(birdColour == orange)
    {
        spritebatch = SpriteBatchNode::create("Birds/Orange/orangebird.png");
        cache->addSpriteFramesWithFile("Birds/Orange/orangebird.plist");
    }
    
    if(birdColour == purple)
    {
        spritebatch = SpriteBatchNode::create("Birds/Purple/purplebird.png");
        cache->addSpriteFramesWithFile("Birds/Purple/purplebird.plist");
    }
    
    if(birdColour == yellow)
    {
        spritebatch = SpriteBatchNode::create("Birds/Yellow/yellowbird.png");
        cache->addSpriteFramesWithFile("Birds/Yellow/yellowbird.plist");
    }
    
    char str4[100] = {0};
    sprintf(str4, "birdcycle%1d", ch);
    bSprite = Sprite::createWithSpriteFrameName(str4);
    bSprite->setPosition(position);
    spritebatch->addChild(bSprite);
    
    this->addChild(spritebatch);
    
    Vector<SpriteFrame*> animFrames(6);
    
    for (int i = 1; i < 7; i++)
    {
        sprintf(str4, "birdcycle%1d", i);
        SpriteFrame* frame = cache->getSpriteFrameByName(str4);
        animFrames.pushBack(frame);
    }
    
    Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
    bSprite->runAction(RepeatForever::create(Animate::create(animation)));
}

void Bird::attack(Point ctrlPoint1, Point ctrlPoint2, Point end, float time)
{
    bezier.controlPoint_1 = ctrlPoint1;
    bezier.controlPoint_2 = ctrlPoint2;
    bezier.endPosition = end;
    
    auto action = BezierTo::create(time, bezier);
    
    bSprite->runAction(action);
}

void Bird::update(float dt)
{
 
}

Bird::~Bird()
{
    bSprite->release();
}