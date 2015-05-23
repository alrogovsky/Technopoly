//
//  Gameplay.h
//  Technopoly
//
//  Created by Олег Ермаков on 15.05.15.
//
//

#ifndef __Technopoly__Gameplay__
#define __Technopoly__Gameplay__

#include "cocos2d.h"
#include "string.h"

class User{
private:
    int _resources;
    std::string name;
public:
  //  int resources() {return _resources;);
};

class Card : public cocos2d::Sprite{
public:
    virtual void Action() = 0;
    Card();
    ~Card();
    static Card* create();
    void addEvents();
    void ClickEvent(cocos2d::Touch* touch, cocos2d::Vec2 _p);
};

class SubjectCard : Card{
private:
    int card_price;
    int house_price;
    int house_count;
    int hotel_price;
    int tax;
public:
    void Action();
};

class TrainingCard : Card{
private:
    int card_price;
public:
    void Action();
};


class ActionCard : Card{
    
};

class MySprite : public cocos2d::Sprite
{
public:
    MySprite();
    ~MySprite();
    static MySprite* create();
    
    void initOptions();
    
    void addEvents();
    void touchEvent(cocos2d::Touch* touch);
    
private:
    
};

#endif /* defined(__Technopoly__Gameplay__) */
