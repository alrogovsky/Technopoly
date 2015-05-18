//
//  LobbyCreation.cpp
//  Technopoly
//
//  Created by Олег Ермаков on 12.05.15.
//
//

#include "LobbyCreation.h"
#include "MainMenu.h"
#include "MainTableScene.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

Scene* LobbyCreation::createScene()
{
    // создание сцены
    auto scene = Scene::create();
    
    // создание слоя
    auto layer = LobbyCreation::create();
    
    // добавление объектов в слой
    scene->addChild(layer);
    
    // возврат сцены
    return scene;
}
bool LobbyCreation::init()
{
   
    if ( !Layer::init() )
    {
        return false;
    }
    
    //размеры окна
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    //фон
    auto sprite = Sprite::create("paper.jpg");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    //заголовок окна
    auto label = Label::createWithTTF("Создание лобби:", "isotextpro/PFIsotextPro-Bold.ttf", 48);
    label->setColor(Color3B::BLACK);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                           origin.y + visibleSize.height - label->getContentSize().height));
    
    //ввод
   // std::string pNormalSprite = "menus/m17.png";
    //Widget::EditBox::create
    auto textField = cocos2d::ui::TextField::create("Название Лобби","isotextpro/PFIsotextPro-Regular.ttf",30);

    
    // set the maximum number of characters the user can enter for this TextField
    textField->setMaxLength(10);
    textField->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height*2
                                - textField->getContentSize().height));
    
    //Кнопка новой игры
    auto backLabel = Label::createWithTTF("Назад", "isotextpro/PFIsotextPro-Regular.ttf", 34);
    backLabel->setColor(Color3B::BLACK);
    auto backButton = MenuItemLabel::create(backLabel, CC_CALLBACK_1(LobbyCreation::onBack, this));
    
    
    
    backButton->setPosition(Vec2(origin.x + backButton->getContentSize().width/1.5,
                              origin.y + visibleSize.height - label->getContentSize().height/1.5));
    
    auto goNextLabel = Label::createWithTTF("Далее", "isotextpro/PFIsotextPro-Regular.ttf", 34);
    goNextLabel->setColor(Color3B::BLACK);
    auto goNextButton = MenuItemLabel::create(goNextLabel, CC_CALLBACK_1(LobbyCreation::onNext, this));
    
    
    
    backButton->setPosition(    Vec2(origin.x + backButton->getContentSize().width/1.5,
                                     origin.y + visibleSize.height - label->getContentSize().height/1.5));
    goNextButton->setPosition(  Vec2(origin.x + visibleSize.width/2,
                                     origin.y + backButton->getContentSize().height * 3 ));

    
    Vector<MenuItem*> MenuItems;
    MenuItems.pushBack(backButton);
    MenuItems.pushBack(goNextButton);
    
    auto menu = Menu::createWithArray(MenuItems);
    menu->setPosition(Vec2::ZERO);
    //добавление элементов на сцену
    this->addChild(textField, 1);
    this->addChild(sprite, 0);
    this->addChild(label, 1);
    this->addChild(menu, 1);
    
    return true;

}

void LobbyCreation::onNext(cocos2d::Ref* pSender)
{
    auto NewGameScene = MainTable::createScene();
    Director::getInstance()->replaceScene(NewGameScene);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void LobbyCreation::onBack(cocos2d::Ref* pSender)
{
    auto NewGameScene = MainMenu::createScene();
    Director::getInstance()->replaceScene(NewGameScene);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}