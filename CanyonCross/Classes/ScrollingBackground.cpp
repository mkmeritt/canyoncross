//
//  ScrollingBackground.cpp
//  CanyonCross
//
//  Created by The Matrix on 2015-04-29.
//
//

#include "ScrollingBackground.h"

class PointObject : public Ref
{
public:
    inline void setRation(Point ratio) {_ratio = ratio;}
    inline void setOffset(Point offset) {_offset = offset;}
    inline void setChild(Node *var) {_child = var;}
    inline Point getOffset() const {return _offset;}
    inline Node* getChild() const {return _child;}
private:
    Point _ratio;
    Point _offset;
    Node* _child;
};

ScrollingBackground* ScrollingBackground::create()
{
    ScrollingBackground* node = new ScrollingBackground();
    
    if(node)
    {
        node->autorelease();
       auto sky = Sprite::create("Background/sky01.png");
       auto sky2 = Sprite::create("Background/sky01.png");
        
        sky->setAnchorPoint(Vec2::ZERO);
        sky2->setAnchorPoint(Vec2::ZERO);
        sky->setScale(2.0f, 1.0f);
        sky2->setScale(2.0f, 1.0f);
        
        node->addChild(sky, -10, Point(1.0, 0.0), Point(0,450));
        node->addChild(sky2, -10, Point(1.0, 0.0), Point(sky->getPositionX() + sky->getTextureRect().size.width,450));
        
        
        auto rock = Sprite::create("Background/canyon02.png");
        auto rock2 = Sprite::create("Background/canyon02.png");
        rock->setAnchorPoint(Point::ZERO);
        rock->setScale(1.0f);
        rock2->setScale(1.0f);
        rock2->setAnchorPoint(Point::ZERO);
        
      
        
        node->addChild(rock, -1, Point(0.1, 0.1), Point(0,0));
        node->addChild(rock2, -1, Point(0.1, 0.1), Point(rock->getPositionX() + rock->getTextureRect().size.width, 0));

          auto cloud = Sprite::create("Clouds/Clouds01.png");
        
        node->addChild(cloud, 2, Point(0.5, 0.5), Point(1000,900));
   
        auto rockset = Sprite::create("Rocks/background rocks/bgrock01.png");
        rockset->setAnchorPoint(Point::ZERO);
        rockset->setScale(1.0f);
        
        node->addChild(rockset, -1, Point(0.2, 0.2), Point(0, -700));
        
        auto rockset2 = Sprite::create("Rocks/background rocks/bgrock02.png");
        rockset2->setAnchorPoint(Point::ZERO);
        rockset2->setScale(1.0f);

    }
    else
    {
        delete node;
        node = 0;
    }
    
    
    return node;
}

ScrollingBackground* ScrollingBackground::createWithOnlySky()
{
    ScrollingBackground* node = new ScrollingBackground();
    
    if(node)
    {
        node->autorelease();
        
        auto sky = Sprite::create("Background/sky01.png");
        
        sky->setAnchorPoint(Vec2::ZERO);
        sky->setScale(1.0f, 1.0f);

        
        node->addChild(sky, -100, Point(0.0, 0.0), Point(0,0));
        
        auto rockset = Sprite::create("Rocks/background rocks/bgrock01.png");
        rockset->setAnchorPoint(Point::ZERO);
        rockset->setScale(1.0f);
        
        node->addChild(rockset, -10, Point(0.2, 0.0), Point(0, -500));
        
        auto rockset2 = Sprite::create("Rocks/background rocks/bgrock02.png");
        rockset2->setAnchorPoint(Point::ZERO);
        rockset2->setScale(1.0f);
        
        node->addChild(rockset2, -1, Point(0.5, 0.0), Point(0, -700));
        
        auto cloud = Sprite::create("Clouds/Clouds01.png");
        
        node->addChild(cloud, 2, Point(0.5, 0.5), Point(500,900));
        
        auto rock = Sprite::create("Background/canyon02.png");
        rock->setAnchorPoint(Point::ZERO);
        rock->setScale(1.0f);
      
        node->addChild(rock, -11, Point(0.0, 0.0), Point(0,0));

    }
    
    else
    {
        delete node;
        node = 0;
    }
    
    return node;
}

void ScrollingBackground::updatePosition()
{
    int safeOffset = -10;
    
    //get size of screen
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    //get each child in parallax node
    for(int i = 0; i < _children.size(); i++)
    {
        auto node = _children.at(i); //set the node
        
        if(convertToWorldSpace(node->getPosition()).x + node->getContentSize().width < safeOffset) //if said node is outside visible area
        {
            for(int i = 0; i <  _parallaxArray->num; i++)
            {
                auto po = (PointObject*)_parallaxArray->arr[i];
                if(po->getChild() == node)
                {
                    po->setOffset(po->getOffset() + Point(visibleSize.width + node->getContentSize().width + 800, 0));
                    
                }
                
                if(po->getChild()->getName() == "sky2")
                {
                    auto sprite2 = po->getChild();
                    
                if(po->getChild()->getName() == "sky")
                {
                    auto sprite = po->getChild();
                    
                    if(!sprite->isVisible())
                    {
                        sprite->setPositionX(sprite2->getPositionX() + sprite2->getContentSize().width);
                    }
                }
                    
                    
            }
            }
        }
    }
    

}

void ScrollingBackground::startParallax()
{
    Point scrollDecrement = Point(5,0);
    this->setPosition(this->getPosition() - scrollDecrement);
}