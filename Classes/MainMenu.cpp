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
    
    //фон
    auto background = Sprite::create("background.png");
    background->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    //кнопака начать игру
    auto NewGameButton = cocos2d::ui::Button::create("button_new_game.png");
    auto size_button = NewGameButton->getContentSize();
    float height_button = size_button.height/ visibleSize.height;
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
    auto BeginLabel = Sprite::create("button_technipoly.png");
    BeginLabel->setScale(1 / (height_button * scale_k));
    
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

    
    //расстояние между блоками
    int deltaCount = 3;
    int delta = (visibleSize.height - BeginLabel->getBoundingBox().size.height - NewGameButton->getBoundingBox().size.height - OptionsButton->getBoundingBox().size.height - CloseGameButton->getBoundingBox().size.height) / deltaCount;
    
    //стрелки
    auto arrow_width = 8 / 37.79 * height_button * scale_k;
    auto arrow1= Sprite::create("arrow_small_white.png");
    arrow1->setAnchorPoint(Vec2(0.5,0.5));
    arrow1->setScale(arrow_width ,delta /arrow1->getContentSize().height );
    
    auto arrow2= Sprite::create("arrow_small_white.png");
    arrow2->setAnchorPoint(Vec2(0.5,0.5));
    arrow2->setScale(arrow_width ,delta /arrow2->getContentSize().height );
    
    auto arrow3= Sprite::create("arrow_small_white.png");
    arrow3->setAnchorPoint(Vec2(0.5,0.5));
    arrow3->setScale(arrow_width ,delta /arrow3->getContentSize().height );

    //Расположение элементов на экране
    BeginLabel->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - BeginLabel->getBoundingBox().size.height * 0.5));
    arrow1->setPosition(Vec2(BeginLabel->getPositionX(),  BeginLabel->getPositionY() - BeginLabel->getBoundingBox().size.height * 0.5 - delta * 0.5 ));
    
    NewGameButton->setPosition(Vec2(BeginLabel->getPositionX(),
                                    BeginLabel->getPositionY() - BeginLabel->getBoundingBox().size.height * 0.5 - NewGameButton->getBoundingBox().size.height * 0.5 -  delta));
    arrow2->setPosition(Vec2(BeginLabel->getPositionX(),  NewGameButton->getPositionY() - NewGameButton->getBoundingBox().size.height * 0.5 - delta * 0.5 ));
    
    OptionsButton->setPosition(Vec2(BeginLabel->getPositionX(),
                                    NewGameButton->getPositionY()  - NewGameButton->getBoundingBox().size.height * 0.5 - OptionsButton->getBoundingBox().size.height * 0.5  -  delta));
    arrow3->setPosition(Vec2(BeginLabel->getPositionX(),  OptionsButton->getPositionY() - OptionsButton->getBoundingBox().size.height * 0.5 - delta * 0.5 ));
    CloseGameButton->setPosition(Vec2(BeginLabel->getPositionX(),
                                      OptionsButton->getPositionY() - OptionsButton->getBoundingBox().size.height * 0.5 - CloseGameButton->getBoundingBox().size.height * 0.5 - delta ));
    
    //анимация
    auto fin_and_jake = Sprite::create("fin_jake1.png");
    fin_and_jake->setAnchorPoint(Vec2(0, 0));
    fin_and_jake->setPosition(Vec2((BeginLabel->getPositionX() - BeginLabel->getBoundingBox().size.width * 0.5 - fin_and_jake->getBoundingBox().size.width) * 0.5 , CloseGameButton->getPositionY()));
    // now lets animate the sprite we moved
    
    Vector<SpriteFrame*> animFrames;
    animFrames.reserve(5);
    animFrames.pushBack(SpriteFrame::create("fin_jake2.png", Rect(0,0,196,126)));
    animFrames.pushBack(SpriteFrame::create("fin_jake3.png", Rect(0,0,196,126)));
    animFrames.pushBack(SpriteFrame::create("fin_jake4.png", Rect(0,0,196,126)));
    animFrames.pushBack(SpriteFrame::create("fin_jake5.png", Rect(0,0,196,126)));
    animFrames.pushBack(SpriteFrame::create("fin_jake6.png", Rect(0,0,196,126)));
    
    Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
    Animate* animate = Animate::create(animation);
    fin_and_jake->runAction(RepeatForever::create(animate));
    ///////

    //добавление элементов на сцену
    this->addChild(background, 0);
    this->addChild(BeginLabel, 1);
    this->addChild(arrow1, 1);
    this->addChild(NewGameButton, 1);
    this->addChild(arrow2, 1);
    this->addChild(OptionsButton, 1);
    this->addChild(arrow3, 1);
    this->addChild(CloseGameButton, 1);
    this->addChild(fin_and_jake, 2);
    return true;
}

void MainMenu::onNewGame(cocos2d::Ref* pSender)
{
    auto NewGameScene = LobbyCreation::createScene();
    Director::getInstance()->replaceScene(NewGameScene);
}

void MainMenu::onOptions(cocos2d::Ref* pSender)
{
    auto NewGameScene = MainTable::createScene();
    Director::getInstance()->replaceScene(NewGameScene);
}

void MainMenu::onQuit(cocos2d::Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
