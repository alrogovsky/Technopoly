//
//  Gameplay.cpp
//  Technopoly
//
//  Created by Олег Ермаков on 15.05.15.
//
//

#include "Gameplay.h"

using namespace cocos2d;

//User Class
User::User()
{
    this->_resources = firstTimeRecources;
}
void User::changeResources(int delta)
{
    this->_resources += delta;
}
void User::setName(std::string name)
{
    this->_name = name;
}
int User::getResources()
{
    return _resources;
}
std::string User::getName()
{
    return _name;
}

//Card Class
//int Card::count = 0;
Card::Card()
{
    _name = "";
    _description = "";
    cardGroup = nullptr;
   // index = count++;
}
Card::~Card()
{
    if (cardGroup!=nullptr)
        delete cardGroup;
    //count--;
}
void Card::setName(std::string cardName)
{
    _name = cardName;
}
void Card::setDescription(std::string cardDescription)
{
    _description = cardDescription;
}
void Card::setGroup(Group* newcardGroup)
{
    cardGroup = newcardGroup;
}
void Card::setIndex(int index)
{
    _index = index;
}
std::string Card::getName()
{
    return _name;
}
std::string Card::getDescription()
{
    return _description;
}
int Card::getIndex()
{
    return _index;
}

Group* Card::getGroup()
{
    return this->cardGroup;
}

//SubjectCard
SubjectCard::SubjectCard():Card()
{
    this->tax = -100;
    this->house_count = 0;
    this->hotel_price = 0;
    Player = nullptr;
    type = TypeCard::Subject;
}
SubjectCard::~SubjectCard()
{
    if(Player!=nullptr)
        delete Player;
}
void SubjectCard::Action(User* Player)
{
    Player->changeResources(this->tax);
}

//Action
ActionCard::ActionCard()
{
    type = TypeCard::Action;
}
void ActionCard::Action(User* Player)
{
    Player->getResources();
}

//Group
void Group::addCard(Card* card)
{
    cards.push_back(card);
    card->setGroup(this);
}
std::string Group::getName()
{
    return _name;
}
std::string Group::getDescription()
{
    return _description;
}
void Group::setName(std::string cardName)
{
    _name = cardName;
}
void Group::setDescription(std::string cardDescription)
{
    _description = cardDescription;
}