//
//  Gameplay.cpp
//  Technopoly
//
//  Created by Олег Ермаков on 15.05.15.
//
//

#include "Gameplay.h"

using namespace cocos2d;

MySprite::MySprite() {}

MySprite::~MySprite() {}

MySprite* MySprite::create()
{
    MySprite* pSprite = new MySprite();
    
    if (pSprite->cocos2d::Sprite::create("1.png"))
    {
        pSprite->autorelease();
        
        pSprite->initOptions();
        
        pSprite->addEvents();
        
        return pSprite;
    }
    
    CC_SAFE_DELETE(pSprite);
    return NULL;
}

void MySprite::initOptions()
{
    // do things here like setTag(), setPosition(), any custom logic.
}

void MySprite::addEvents()
{
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event)
    {
        cocos2d::Vec2 p = touch->getLocation();
        cocos2d::Rect rect = this->getBoundingBox();
        
        if(rect.containsPoint(p))
        {
            return true; // to indicate that we have consumed it.
        }
        
        return false; // we did not consume this event, pass thru.
    };
    
    listener->onTouchEnded = [=](cocos2d::Touch* touch, cocos2d::Event* event)
    {
        touchEvent(touch);
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void MySprite::touchEvent(cocos2d::Touch* touch)
{
    CCLOG("touched MySprite");
}