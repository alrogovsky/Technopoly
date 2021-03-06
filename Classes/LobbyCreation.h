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
#include "ui/CocosGUI.h"
#include "UITextField.h"


class LobbyCreation : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
   // void UITextFieldTest_LineWrap::textFieldEvent(Ref *pSender, cocos2d::ui::TextField::EventType type);
    void onBack(cocos2d::Ref* pSender);
    void onNext(cocos2d::Ref* pSender);
    int scale_k = 5;
    
    CREATE_FUNC(LobbyCreation);
};

#endif