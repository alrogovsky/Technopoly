//
//  MainMenu.h
//  Technopoly
//
//  Created by Олег Ермаков on 11.05.15.
//
//

#ifndef __Technopoly__MainMenu__
#define __Technopoly__MainMenu__

#include "cocos2d.h"
#include "MainTableScene.h"
#include "LobbyCreation.h"
#include <boost/random.hpp>

class MainMenu : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    int scale_k = 4;
    
    // a selector callback
    
    void onNewGame(cocos2d::Ref* pSender);
    void onOptions(cocos2d::Ref* pSender);
    void onQuit(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);
};

#endif /* defined(__Technopoly__MainTableScene__) */
