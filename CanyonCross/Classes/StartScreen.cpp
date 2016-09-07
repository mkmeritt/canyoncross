//
//  StartScreen.cpp
//  CanyonCross
//
//  Created by Mark Meritt on 2016-02-21.
//
//

#include "StartScreen.hpp"

StartScreen::StartScreen()
{
    
}

Scene* StartScreen::scene()
{
    Scene* scene = NULL;
    
    scene = Scene::create();
    
    auto layer = StartScreen::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool StartScreen::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    fadeOut = FadeOut::create(1.0f);
    fadeIn = FadeIn::create(1.0f);
    
    bg = ScrollingBackground::createWithOnlySky();
    
    addChild(bg);
    
    title = Sprite::create("UI/Start Screen Title.png");
    
    Vec2 pos = Vec2(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height/2);
    
    pos.add(Director::getInstance()->getVisibleOrigin());
    
    title->setPosition(pos);
    
    title->setScale(0.4f);
    
    addChild(title);
    
    start = Sprite::create("UI/Start Screen Start Button.png");
    
    start->setScale(0.8f);
    
    start->setPosition(pos);
    
    addChild(start);
    
    seq = Sequence::createWithTwoActions(fadeOut, fadeIn);
    
    rep = RepeatForever::create(seq);
    
    title->retain();
    start->retain();
    
    start->runAction(rep);

    //bird->runAction(bird->attack());
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(StartScreen::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(StartScreen::onTouchEnded, this);
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    schedule(schedule_selector(StartScreen::update));

    
    return true;
}

void StartScreen::update(float time)
{
    bg->updatePosition();
    bg->startParallax();

}

bool StartScreen::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *evt)
{
    return true;
}

void StartScreen::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *evt)
{
    auto scene = CanyonLevel::createScene();
    Director::getInstance()->replaceScene(scene);
}

StartScreen::~StartScreen()
{
  
}