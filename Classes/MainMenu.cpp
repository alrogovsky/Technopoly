//
//  MainMenu.cpp
//  Technopoly
//
//  Created by Олег Ермаков on 11.05.15.
//
//

#include "MainMenu.h"
#include "MainTableScene.h"
#include "LobbyCreation.h"
#include <boost/random.hpp>


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
    
    // Рандома
    boost::random::mt11213b rng;
    unsigned int seed = 0;
    rng.seed((++seed) + time(NULL));
    
    boost::random::uniform_int_distribution<> six(1,6);
    int x = six(rng);
    
    std::string newstring= std::to_string(x);
    //Название игры
    auto label = Label::createWithTTF(newstring, "isotextpro/PFIsotextPro-Bold.ttf", 48);
    label->setColor(Color3B::BLACK);
    
    //Кнопка новой игры
    auto NewGameButton = Label::createWithTTF("Новая игра", "isotextpro/PFIsotextPro-Regular.ttf", 34);
    NewGameButton->setColor(Color3B::BLACK);
    
    //Кнопка опций
    auto OptionsButton = Label::createWithTTF("Настройки", "isotextpro/PFIsotextPro-Regular.ttf", 34);
    OptionsButton->setColor(Color3B::BLACK);
    
    //Кнопка выхода из игры
    auto CloseGameButton = Label::createWithTTF("Выйти", "isotextpro/PFIsotextPro-Regular.ttf", 34);
    CloseGameButton->setColor(Color3B::BLACK);

    //Добавление функций кнопкам
    auto closeitem = MenuItemLabel::create(CloseGameButton, CC_CALLBACK_1(MainMenu::onQuit, this));
    auto options = MenuItemLabel::create(OptionsButton, CC_CALLBACK_1(MainMenu::onOptions, this));
    auto newgame = MenuItemLabel::create(NewGameButton, CC_CALLBACK_1(MainMenu::onNewGame, this));

    
    //Расположение элементов на экране
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                              origin.y + visibleSize.height - label->getContentSize().height));
    newgame->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height * 3 -
                                newgame->getContentSize().height));
    options->setPosition(Vec2(origin.x + visibleSize.width/2,
                              origin.y + visibleSize.height - label->getContentSize().height * 3 -
                              newgame->getContentSize().height * 2 - options->getContentSize().height));
    closeitem->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height * 3 -
                                newgame->getContentSize().height * 2 - options->getContentSize().height * 2 - closeitem->getContentSize().height));

    
    //Добавление всех объектов меню в один объект
    Vector<MenuItem*> MenuItems;
    MenuItems.pushBack(closeitem);
    MenuItems.pushBack(options);
    MenuItems.pushBack(newgame);
    auto menu = Menu::createWithArray(MenuItems);
    menu->setPosition(Vec2::ZERO);
    
    //создание фона
    auto sprite = Sprite::create("paper.jpg");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    //добавление элементов на сцену
    this->addChild(sprite, 0);
    this->addChild(menu, 1);
    this->addChild(label, 1);
    
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
