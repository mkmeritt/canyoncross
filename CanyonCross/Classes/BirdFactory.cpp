//
//  BirdFactory.cpp
//  CanyonCross
//
//  Created by Mark Meritt on 2016-02-21.
//
//

#include "BirdFactory.hpp"

BirdFactory::BirdFactory()
{
    buildPath();
    
    spawnBird(1.0f);
}

void BirdFactory::spawnBird(float num)
{
    auto bird = new Bird();
    addChild(bird);
    
    bird->attack(leftPoints.front(), targets.front(), rightPoints.front(), 2.0f);

}

void BirdFactory::removeBird(float num)
{
    
}

void BirdFactory::buildPath()
{
    //possible left points
    Point l1 = Point(0, Director::getInstance()->getVisibleSize().height / 2);
    leftPoints.push_back(l1);
    
    
    //possible right points
    Point r1 = Point(Director::getInstance()->getWinSize().width + 100, Director::getInstance()->getVisibleSize().height / 2);
    rightPoints.push_back(r1);
    
    //possible target points
    Point t1 = slot1Pos;
    Point t2 = slot2Pos;
    Point t3 = slot3Pos;
    targets.push_back(t1);
    targets.push_back(t2);
    targets.push_back(t3);
    
    random_shuffle(targets.begin(), targets.end());
    
    Point target = targets.front();
    
    path.push_back(leftPoints.front());
    path.push_back(target);
    path.push_back(rightPoints.front());
}

void BirdFactory::update(float dt)
{
   // if(spawnBird() != NULL)
   //     spawnBird()->update(dt);
}

BirdFactory::~BirdFactory()
{
    
}