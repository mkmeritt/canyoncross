//
//  CanyonLevel.cpp
//  CanyonCross
//
//  Created by The Matrix on 2015-04-29.
//
//


#include "CanyonLevel.h"

USING_NS_CC;

Scene* CanyonLevel::createScene()
{
    
    auto scene = Scene::createWithPhysics();

    auto layer = CanyonLevel::create();
    
   // scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    scene->addChild(layer);
    
    return scene;
}

bool CanyonLevel::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    parallax = ScrollingBackground::createWithOnlySky();
    
    addChild(parallax);
    
    ropeFactory = new RopeFactory();
   
    addChild(ropeFactory);
    
    character = new Player();
    
    addChild(character, 20);
    
    touristFactory = new TouristFactory();
    
    touristFactory->addTourist();
    
    addChild(touristFactory, 11);
    
    birdFactory = new BirdFactory();
    
    addChild(birdFactory);

    schedule(schedule_selector(CanyonLevel::update));
    
    return true;
}

bool CanyonLevel::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *evt)
{
    return true;
}

void CanyonLevel::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *evt)
{
    
}

void CanyonLevel::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *evt)
{
    
}

void CanyonLevel::update(float dt)
{
    parallax->updatePosition();
    parallax->startParallax();
   // ropeFactory->update(dt);
    character->update(dt);
    birdFactory->update(dt);
    this->runAction(Follow::create(character, Rect(0, 0, siz.width * 2 - 100, siz.height)));
}

void CanyonLevel::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

CanyonLevel::~CanyonLevel()
{
    
}

