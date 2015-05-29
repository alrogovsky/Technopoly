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
Card::Card()
{
    _name = "";
    _description = "";
}
void Card::setName(std::string cardName)
{
    _name = cardName;
}
void Card::setDescription(std::string cardDescription)
{
    _description = cardDescription;
}
std::string Card::getName()
{
    return _name;
}
std::string Card::getDescription()
{
    return _description;
}

//SubjectCard
SubjectCard::SubjectCard():Card()
{
    this->tax = -100;
    this->house_count = 0;
    this->house_price = 0;
    this->hotel_price = 0;
}
void SubjectCard::Action(User* Player)
{
    Player->changeResources(this->tax);
}