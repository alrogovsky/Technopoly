//
//  MainMenu.cpp
//  Technopoly
//
//  Created by Олег Ермаков on 11.05.15.
//
//

#include "MainMenu.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
Scene* MainMenu::createScene()
{
    // создание сцены
    auto scene = Scene::create();
    
    // создание слоя
    auto layer = MainMenu::create();
    
    // добавление объектов в слой
    scene->addChild(layer);
    
    // возврат сцены
    return scene;
}
bool MainMenu::init()
{
    //инициализация
    if ( !Layer::init() )
    {
        return false;
    }
    
    //видимый размер (разрешение экрана)
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //кнопака начать игру
    auto NewGameButton = cocos2d::ui::Button::create("button_new_game.png");
    auto size_button = NewGameButton->getContentSize();
    float height_button = size_button.width / visibleSize.width;
    NewGameButton->setScale(1 / (height_button * scale_k));
    
    NewGameButton->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                onNewGame(sender);
                break;
            default:
                break;
        }
    });
    //название игры
    auto label = Sprite::create("button_technipoly.png");
    label->setScale(1 / (height_button * scale_k));
    
    //кнопка настройки
    auto OptionsButton = cocos2d::ui::Button::create("button_options.png");
    OptionsButton->setScale(1 / (height_button * scale_k));
    
    OptionsButton->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                onOptions(sender);
                break;
            default:
                break;
        }
    });
    
    //кнопка выход
    auto CloseGameButton = cocos2d::ui::Button::create("button_exit.png");
    CloseGameButton->setScale(1 / (height_button * scale_k));
  
    CloseGameButton->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                onQuit(sender);
                break;
            default:
                break;
        }
    });
    
    int delta = (visibleSize.height - label->getContentSize().height - NewGameButton->getContentSize().height - OptionsButton->getContentSize().height - CloseGameButton->getContentSize().height) / 3;
    
    //Расположение элементов на экране
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                              origin.y + visibleSize.height - label->getContentSize().height * 0.5));
    
    NewGameButton->setPosition(Vec2(origin.x + visibleSize.width/2,
                                label->getPositionY() - OptionsButton->getContentSize().height * 0.5  - delta));

    OptionsButton->setPosition(Vec2(origin.x + visibleSize.width/2,
                                    NewGameButton->getPositionY()  - label->getContentSize().height * 0.5 - OptionsButton->getContentSize().height * 0.5  -  delta));
                           
    CloseGameButton->setPosition(Vec2(origin.x + visibleSize.width/2,
                                     OptionsButton->getPositionY() - label->getContentSize().height * 0.5 - CloseGameButton->getContentSize().height * 0.5 - delta ));
    

    //создание фона
    auto background = Sprite::create("background.png");
    background->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    //добавление элементов на сцену
    this->addChild(background, 0);
    this->addChild(label, 1);
    this->addChild(NewGameButton, 1);
    this->addChild(OptionsButton, 1);
    this->addChild(CloseGameButton, 1);   
  
    return true;
}

void MainMenu::onNewGame(cocos2d::Ref* pSender)
{
    auto NewGameScene = LobbyCreation::createScene();
    Director::getInstance()->replaceScene(NewGameScene);
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void MainMenu::onOptions(cocos2d::Ref* pSender)
{
    auto NewGameScene = MainTable::createScene();
    Director::getInstance()->replaceScene(NewGameScene);
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void MainMenu::onQuit(cocos2d::Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
