//
//  Data.cpp
//  Technopoly
//
//  Created by Олег Ермаков on 30.05.15.
//
//


/*
 
В одних и тех же группах:
1) 1,3
2) 6,8,9
3) 11,13,14
4) 16,18,19
5) 21,23,24
6) 26,27,29
7) 31,32,34
8) 37,39
*/

#include "MainTableScene.h"
#define NumberOfSubjectCards 22
#define NumberOfOSCards 4
#define NumberOfComChest 3
#define NumberOfTaxPay 2
#define NumberOfChance 3
#define NumberOfTraining 2
#define NumberOfCorners 4

Card** MainTable::dataCards = new  Card* [MainTable::numbers_of_cards];
Group* MainTable::Groups = new  Group [MainTable::numbers_of_groups];
void InitData()
{
    //хранение индексов
    int indexSubject[NumberOfSubjectCards] =                    //все карты предметов
    {1,3,6,8,9,11,13,14,16,18,19,21,23,24,26,27,29,31,32,34,37,39};
    int indexOS[NumberOfOSCards] = {5,15,25,35};
    int indexChest[NumberOfComChest] = {2,17,33};
    int indexTax[NumberOfTaxPay] = {4,38};
    int indexChance[NumberOfChance] = {7,22,36};
    int indexTraining[NumberOfTraining] = {12,28};
    int indexCorner[NumberOfCorners] = {10,20,30,0};
    
    //инициализация каждой группы карт
    for(int i=0; i<NumberOfSubjectCards; i++)
    {
        MainTable::dataCards[indexSubject[i]] = new SubjectCard();
        MainTable::dataCards[indexSubject[i]]->setName("Название конкретной карты");
        MainTable::dataCards[indexSubject[i]]->setDescription("Какое-то описание карты");
        MainTable::dataCards[indexSubject[i]]->setIndex(indexSubject[i]);
    }
    for(int i=0; i<NumberOfOSCards; i++)
    {
        MainTable::dataCards[indexOS[i]] = new ActionCard();
        MainTable::dataCards[indexOS[i]]->setName("Название");
        MainTable::dataCards[indexOS[i]]->setDescription("Описание");
        MainTable::dataCards[indexOS[i]]->setIndex(indexOS[i]);
    }
    for(int i=0; i<NumberOfComChest; i++)
    {
        MainTable::dataCards[indexChest[i]] = new ActionCard();
        MainTable::dataCards[indexChest[i]]->setName("Название");
        MainTable::dataCards[indexChest[i]]->setDescription("Описание");
        MainTable::dataCards[indexChest[i]]->setIndex(indexChest[i]);
    }
    for(int i=0; i<NumberOfTaxPay; i++)
    {
        MainTable::dataCards[indexTax[i]] = new ActionCard();
        MainTable::dataCards[indexTax[i]]->setName("Название");
        MainTable::dataCards[indexTax[i]]->setDescription("Описание");
        MainTable::dataCards[indexTax[i]]->setIndex(indexTax[i]);
    }
    for(int i=0; i<NumberOfChance; i++)
    {
        MainTable::dataCards[indexChance[i]] = new ActionCard();
        MainTable::dataCards[indexChance[i]]->setName("Название");
        MainTable::dataCards[indexChance[i]]->setDescription("Описание");
        MainTable::dataCards[indexChance[i]]->setIndex(indexChance[i]);
    }
    for(int i=0; i<NumberOfTraining; i++)
    {
        MainTable::dataCards[indexTraining[i]] = new ActionCard();
        MainTable::dataCards[indexTraining[i]]->setName("Название");
        MainTable::dataCards[indexTraining[i]]->setDescription("Описание");
        MainTable::dataCards[indexTraining[i]]->setIndex(indexTraining[i]);
    }
    for(int i=0; i<NumberOfCorners; i++)
    {
        MainTable::dataCards[indexCorner[i]] = new ActionCard();
        MainTable::dataCards[indexCorner[i]]->setName("Название");
        MainTable::dataCards[indexCorner[i]]->setDescription("Описание");
        MainTable::dataCards[indexCorner[i]]->setIndex(indexCorner[i]);
    }
   

    //MainTable::dataCards[0] = new ActionCard();
    MainTable::dataCards[0]->setName("Круг Пройден!");
    MainTable::dataCards[0]->setDescription("При прохождении данного поля, вы получаете 200 ресурсов");
    
    MainTable::Groups[0].addCard(MainTable::dataCards[1]);
    MainTable::Groups[0].addCard(MainTable::dataCards[3]);
    MainTable::Groups[0].setName("Вступительные испытания");
    MainTable::Groups[0].setDescription("Наисложнейшие тесты, отбирающие луч... нет, даже так... ЛУЧШИХ из ЛУЧШИХ");
    
    MainTable::Groups[1].addCard(MainTable::dataCards[6]);
    MainTable::Groups[1].addCard(MainTable::dataCards[8]);
    MainTable::Groups[1].addCard(MainTable::dataCards[9]);
    MainTable::Groups[1].setName("С/С++");
    MainTable::Groups[1].setDescription("СиСИСИСИСИСИСИСИСИСИСИСИСИСИСИСИСИСИСИСИСИСИСИСИС\nСИСИСИСИСИСИСИСИСИСИ\nСИСИСИС");
    
    MainTable::Groups[2].addCard(MainTable::dataCards[11]);
    MainTable::Groups[2].addCard(MainTable::dataCards[13]);
    MainTable::Groups[2].addCard(MainTable::dataCards[14]);
    MainTable::Groups[2].setName("WEB");
    MainTable::Groups[2].setDescription("не был на лекциях, но говорят интересно");
    
    MainTable::Groups[3].addCard(MainTable::dataCards[16]);
    MainTable::Groups[3].addCard(MainTable::dataCards[18]);
    MainTable::Groups[3].addCard(MainTable::dataCards[19]);
    MainTable::Groups[3].setName("Название группы карт");
    MainTable::Groups[3].setDescription("Описание группы карт");
    
    MainTable::Groups[4].addCard(MainTable::dataCards[21]);
    MainTable::Groups[4].addCard(MainTable::dataCards[23]);
    MainTable::Groups[4].addCard(MainTable::dataCards[24]);
    MainTable::Groups[4].setName("Название группы карт");
    MainTable::Groups[4].setDescription("Описание группы карт");
    
    MainTable::Groups[5].addCard(MainTable::dataCards[26]);
    MainTable::Groups[5].addCard(MainTable::dataCards[27]);
    MainTable::Groups[5].addCard(MainTable::dataCards[29]);
    MainTable::Groups[5].setName("Название группы карт");
    MainTable::Groups[5].setDescription("Описание группы карт");
    
    MainTable::Groups[6].addCard(MainTable::dataCards[31]);
    MainTable::Groups[6].addCard(MainTable::dataCards[32]);
    MainTable::Groups[6].addCard(MainTable::dataCards[34]);
    MainTable::Groups[6].setName("Название группы карт");
    MainTable::Groups[6].setDescription("Описание группы карт");
    
    MainTable::Groups[7].addCard(MainTable::dataCards[37]);
    MainTable::Groups[7].addCard(MainTable::dataCards[39]);
    MainTable::Groups[7].setName("Название группы карт");
    MainTable::Groups[7].setDescription("Описание группы карт");
}