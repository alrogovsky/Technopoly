//
//  CardInfo.cpp
//  Technopoly
//
//  Created by Олег Ермаков on 21.05.15.
//
//
#include "CardInfo.h"
USING_NS_CC;

Scene* CardInfo::createScene()
{
    // создание сцены
    auto scene = Scene::create();
    
    // создание слоя
    auto layer = CardInfo::create();
    
    // добавление объектов в слой
    scene->addChild(layer);
    
    // возврат сцены
    return scene;
}
bool CardInfo::init()
{
    //инициализация
    if ( !Layer::init() )
    {
        return false;
    }
    
    //видимый размер (разрешение экрана)
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    return true;
}