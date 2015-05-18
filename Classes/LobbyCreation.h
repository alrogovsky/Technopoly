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

class LobbyCreation : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    
   // void onStart(cocos2d::Ref* pSender);
   // void onBack(cocos2d::Ref* pSender);
   // void onQuit(cocos2d::Ref* pSender);
    void onBack(cocos2d::Ref* pSender);
    void onNext(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(LobbyCreation);
};

#endif /* defined(__Technopoly__MainTableScene__) */
