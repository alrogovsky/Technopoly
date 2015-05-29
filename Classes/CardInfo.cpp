//
//  CardInfo.cpp
//  Technopoly
//
//  Created by Олег Ермаков on 21.05.15.
//
//
#include "CardInfo.h"
USING_NS_CC;

Scene* CardInfo::createScene(std::string name)
{
    // создание сцены
    auto scene = Scene::create();
    // создание слоя
    auto layer = CardInfo::create(name);
    
    
    // добавление объектов в слой
    scene->addChild(layer);
    
    // возврат сцены
    return scene;
}
bool CardInfo::init(std::string intname)
{
    //инициализация
    if ( !Layer::init() )
    {
        return false;
    }
    
    //видимый размер (разрешение экрана)
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

   // std::string name = std::to_string(intname);
   
    
    auto background = Sprite::create("paper.jpg");
    background->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    background->setOpacity(400);
    
    auto sprite = Sprite::create("cards/HighRes/" + intname + ".jpg");
    sprite->setPosition(Vec2(visibleSize.width + origin.x, visibleSize.height/2 + origin.y));
    sprite->setAnchorPoint(Vec2(1,0.5));

    
    auto exit = MenuItemImage::create("menus/m8.png", "menus/m14.png",
                          [&](Ref* sender){
                              
                              auto MainScene = this->getParent()->getParent();
                              auto menu1 = (Menu*) MainScene->getChildByName("menu");
                              menu1->setEnabled(true);
                              
                              auto menu2 = (Menu*) MainScene->getChildByName("table")->getChildByName("tableMenu");
                              menu2->setEnabled(true);
                              this->removeAllChildren();
                              this->getParent()->removeChild(this);
                             // this->autorelease();
                          });
    exit->setPosition(Vec2(origin.x + exit->getContentSize().width,
                      origin.y + visibleSize.height - exit->getContentSize().height));
    
    auto exitButton = Menu::create(exit, NULL);
    exitButton->setPosition(origin);
    
   // int a = CardIndex;
    this->addChild(sprite,1);
    this->addChild(background,0);
    this->addChild(exitButton, 1);
    return true;
}

