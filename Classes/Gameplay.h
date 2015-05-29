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
#include "ui/CocosGUI.h"

void InitData();

class User{
private:
    int _resources;
    std::string _name;
    static const int firstTimeRecources = 100;
public:
    User();
    void setName(std::string);
    void changeResources(int);
    int getResources();
    std::string getName();
  //  int resources() {return _resources;);
};

class Card{
private:
    std::string _name;
    std::string _description;
public:
    Card();
    virtual void Action(User*) = 0;
    void setName(std::string);
    void setDescription(std::string);
    std::string getName();
    std::string getDescription();
    //Card();
    //static Card* create();
};

class SubjectCard : public Card{
private:
    int card_price;
    int house_price;
    int house_count;
    int hotel_price;
    int tax;
public:
    SubjectCard();
    void Action(User*);
    
};

class TrainingCard : public Card{
private:
    int card_price;
public:
    void Action(User*);
};


class ActionCard : public Card{
public:
    void Action(User*);
};


#endif /* defined(__Technopoly__Gameplay__) */
