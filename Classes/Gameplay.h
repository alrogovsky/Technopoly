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

class Card{
    virtual void Action() = 0;
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

#endif /* defined(__Technopoly__Gameplay__) */
