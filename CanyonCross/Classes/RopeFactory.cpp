//
//  RopeFactory.cpp
//  CanyonCross
//
//  Created by The Matrix on 2015-07-20.
//
//

#include "RopeFactory.h"

RopeFactory::RopeFactory()
{
    
    x = 2000;

    
rockSpriteList = new Vector<Sprite*>(20);
    
area = Director::getInstance()->getVisibleSize();
    
    this->singleRock();
    
//schedule(schedule_selector(RopeFactory::factoryUpdate), 1.5f);  //1st
    
//schedule(schedule_selector(RopeFactory::deleteRocks), 0.0f);    //2nd
    
//schedule(schedule_selector(RopeFactory::addRocks), 1.5f);       //3rd
    
startPos = new Vec2(x, 0);

}

void RopeFactory::singleRock()
{
    rockSprite = Sprite::create("Rocks/single rocks/rock01.png");
    
    ropeSprite = Sprite::create("Rope/ropebits0001.png");
    
    ropeSprite->setPosition(rockSprite->getContentSize().width - 100, rockSprite->getContentSize().height);
    
    rockSprite->addChild(ropeSprite);
    
    Vec2 pos = Vec2(Director::getInstance()->getVisibleSize().width / 2 + 60, -40);
    
    rockSprite->setPosition(pos);
    
    rockSprite->setScale(0.3f);
    
    s1 = Size(rockSprite->getContentSize());
    
    auto phys1 = PhysicsBody::createBox(s1);
    
    phys1->setGravityEnable(false);
    phys1->setDynamic(false);
    
    rockSprite->setPhysicsBody(phys1);
    
    this->addChild(rockSprite);
}

//int RopeFactory::getNum()
//{
//return num;
//}
//
//void RopeFactory::factory(int rockType)
//{
//auto rockA = Sprite::create("Rocks/single rocks/rock01.png");
//auto rockB = Sprite::create("Rocks/single rocks/rock02.png");
//auto rockC = Sprite::create("Rocks/single rocks/rock03.png");
//
//rockA->setScale(0.4f);
//
//rockB->setScale(0.4f);
//
//rockC->setScale(0.4f);
//
//s1 = Size(rockA->getContentSize());
//s2 = Size(rockB->getContentSize());
//s3 = Size(rockC->getContentSize());
//
//
//auto phys1 = PhysicsBody::createBox(s1);
//auto phys2 = PhysicsBody::createBox(s2);
//auto phys3 = PhysicsBody::createBox(s3);
//
//
//phys1->setGravityEnable(false);
//phys1->setDynamic(false);
//
//phys2->setGravityEnable(false);
//phys2->setDynamic(false);
//
//phys3->setGravityEnable(false);
//phys3->setDynamic(false);
//
//rockA->setPhysicsBody(phys1);
//rockB->setPhysicsBody(phys2);
//rockC->setPhysicsBody(phys3);
//
//
//switch(rockType)
//{
//case 0:
//        rockA->setPosition(*startPos);
//        rockSpriteList->pushBack(rockA);
//    break;
//
//case 1:
//         rockB->setPosition(*startPos);
//         rockSpriteList->pushBack(rockB);
//    break;
//    
//case 2:
//         rockC->setPosition(*startPos);
//         rockSpriteList->pushBack(rockC);
//    break;
//}
//    
//   
//}
//
//void RopeFactory::addRocks(float num)
//{
//    
//
//       for(int i = 0; i < rockSpriteList->size(); i++)
//    {
//   
//    if(i < 21)
//    {
//         if(rockSpriteList->at(i)->getParent() == nullptr)
//         {
//            addChild(rockSpriteList->at(i));
//             
//         }
//        
//        CCLOG("i: %d", i);
//        
//    }
//
//
//    }
//    
//    
//    if(rockSpriteList->size() > 20){
//        CCLOG("pos: %f", rockSpriteList->at(20)->getPositionX());
//    }
//
//
//    
//}
//
//void RopeFactory::deleteRocks(float num)
//{
//
//   
//    for(int i = 0; i < rockSpriteList->size(); i++)
//    {
//        
//    if(i > 20){
//        
//        
//                if(rockSpriteList->at(20)->getPositionX() < -50)
//                {
//                    
//                    float tmpX = rockSpriteList->at(20)->getPositionX();
//                    
//                    removeAllChildren();
//                    
//                    rockSpriteList->clear();
//                    
//                    startPos->x = tmpX + 1500;
//                }
//        
//    }
//    
//    
//    
//    
//    }
//   
//
//
//}
//
void RopeFactory::rockMove()
{
    
Point scrollDecrement = Point(10.5,0);

    for(int i = 0; i < rockSpriteList->size(); i++)
    {
            rockSpriteList->at(i)->setPosition(rockSpriteList->at(i)->getPosition() - scrollDecrement);
    }
     
}

void RopeFactory::update(float dt)
{
num = rand() % 2 + 0;

this->rockMove();
   
   
  //  CCLOG("container size: %lu", rockSpriteList->size());

}
//
//void RopeFactory::factoryUpdate(float dt)
//{
//    this->factory(num);
//}

RopeFactory::~RopeFactory()
{
    
}