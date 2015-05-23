//
//  LobbyCreation.h
//  Technopoly
//
//  Created by Олег Ермаков on 12.05.15.
//
//

#ifndef __Technopoly__LobbyCreation__
#define __Technopoly__LobbyCreation__

#include "cocos2d.h"
#include "MainMenu.h"

class LobbyCreation : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    void onBack(cocos2d::Ref* pSender);
    void onNext(cocos2d::Ref* pSender);

    CREATE_FUNC(LobbyCreation);
};

#endif