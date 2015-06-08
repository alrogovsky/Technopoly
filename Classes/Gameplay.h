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

using namespace std;
enum TypeCard {Subject,Training,Action};
class Card;
class Group;

class User{
private:
    int _resources;
    std::string _name;
    int _index;
    static const int firstTimeRecources = 1500;
public:
    User();
     vector<Card*> cards;
    void setName(std::string);
    void changeResources(int);
    void addCard(Card*);
    void move(int);
    int getResources();
    std::string getName();
  //  int resources() {return _resources;);
};

class Card{
private:
    std::string _name;
    std::string _description;
    int _index;
   // static int count;
public:
    Card();
    ~Card();
    Group* cardGroup;
    TypeCard type;
    virtual void Action(User*) = 0;
    void setName(std::string);
    void setDescription(std::string);
    void setIndex(int);
    void setGroup(Group*);
    std::string getName();
    std::string getDescription();
    int getIndex();
    Group* getGroup();
    //Card();
    //static Card* create();
};

class SubjectCard : public Card{
private:
    int card_price;
    int house_price;
    int house_count;
    int hotel_price;
    User* Owner;
    int tax;
public:
    SubjectCard();
    ~SubjectCard();
    void sellToOwner(User* player);
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
    ActionCard();
    void Action(User*);
};

class Group
{
    std::string _name;
    std::string _description;
public:
    vector<Card*> cards;
    void addCard(Card*);
    void setName(std::string);
    void setDescription(std::string);
    std::string getName();
    std::string getDescription();

};

#endif /* defined(__Technopoly__Gameplay__) */
