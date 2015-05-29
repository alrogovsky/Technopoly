//
//  Data.cpp
//  Technopoly
//
//  Created by Олег Ермаков on 29.05.15.
//
//

#include <stdio.h>
#include "Gameplay.h"
#include "MainTableScene.h"

//Card dataCards [MainTable::numbers_of_cards];
void InitData()
{
    User player;
    Card* dataCards [MainTable::numbers_of_cards];
    SubjectCard a;
    dataCards[0] = &a;
    dataCards[0]->Action(&player);
    
}

//SubjectCard a;
