//
//  CardInfo.h
//  Technopoly
//
//  Created by Олег Ермаков on 21.05.15.
//
//

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#pragma once
#include "MainTableScene.h"

#define FullHeight 1
//

class CardInfo : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene(std::string name);
    
    //параметры
    
    virtual bool init(std::string name);
    
    void onBack(cocos2d::Ref* pSender);
    
    static CardInfo* create(std::string name)
    {
        CardInfo*pRet = new(std::nothrow) CardInfo();
        if (pRet && pRet->init(name))
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        } 
    }

};