//
//  LobbyCreation.cpp
//  Technopoly
//
//  Created by Олег Ермаков on 12.05.15.
//
//

#include "LobbyCreation.h"
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
    auto background = Sprite::create("paper.jpg");
    background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    
    //первый блок "Ввести имя"
    auto BeginLabel = Sprite::create("vvesti_name.png");
    BeginLabel->setAnchorPoint(Vec2(0.5,0.5));
    float height_lable = BeginLabel->getContentSize().height / visibleSize.height;
    BeginLabel->setScale(1 / (height_lable * scale_k));
  
    
    //фон для textField
    auto textFieldBackground = Sprite::create("name.png");
    textFieldBackground->setAnchorPoint(Vec2(0.5,0.5));
    textFieldBackground->setScale(1 / (height_lable * scale_k));
    
    //ввод
   // std::string pNormalSprite = "menus/m17.png";
    //Widget::EditBox::create

    auto textField = cocos2d::ui::TextField::create("ВАШЕ ИМЯ","isotextpro/PFIsotextPro-Bold.ttf",72);
    textField->setMaxLength(9);
    textField->setScale(1 / (height_lable * scale_k));
    textField->setColor(Color3B::BLACK);
    textField->setName("fieldUserName");
    textField->setColor(Color3B::BLACK);
    
    //отступ между блоками
    auto delta = (visibleSize.height - BeginLabel->getBoundingBox().size.height - textFieldBackground->getBoundingBox().size.height) * 0.5;
    auto delta_size = delta - BeginLabel->getBoundingBox().size.height * 0.5 - textFieldBackground->getBoundingBox().size.height * 0.5;
    
    
    //толщина стрелки
    auto arrow_width = 8 / 37.79 * (height_lable * scale_k);
    //первая стрелка по вертикали
    auto arrow1 = Sprite::create("arrow_small.png");
    arrow1->setAnchorPoint(Vec2(0.5,0.5));
    arrow1->setScale(arrow_width ,delta_size  / arrow1->getContentSize().height ) ;
    
    
    //кнопко "Далее"
    auto button_next = cocos2d::ui::Button::create("next.png");
    button_next->setAnchorPoint(Vec2(0.5,0.5));
    button_next->setScale(1 / (height_lable * scale_k));
    button_next->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                onNext(sender);
                break;
            default:
                break;
        }
    });
    
    //вторая стрелка по вертикали
    auto arrow2 = Sprite::create("arrow_small.png");
    arrow2->setAnchorPoint(Vec2(0.5,0.5));
    arrow2->setScale(arrow_width, delta_size  / arrow2->getContentSize().height ) ;
    
        //кнопка "Назад"
    auto button_back = cocos2d::ui::Button::create("back.png");
    button_back->setAnchorPoint(Vec2(0.5,0.5));
    button_back->setScale(1 / (height_lable * scale_k));
    button_back->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                onBack(sender);
                break;
            default:
                break;
        }
    });
    
    //горизонтальная часть стрелки слева
    auto arrow_left1= Sprite::create("arrow_left1.png");
    arrow_left1->setAnchorPoint(Vec2(0,0.5));
    arrow_left1->setScale(button_back->getBoundingBox().size.width * 0.5 / arrow_left1->getContentSize().width , arrow_width);
    
    //вертикальная часть стрелки слева
    auto arrow_left2= Sprite::create("arrow_small.png");
    arrow_left2->setAnchorPoint(Vec2(0.5,0));
    arrow_left2->setScale(arrow_width,
        (BeginLabel->getPositionY() + button_back->getPositionY() + button_back->getBoundingBox().size.height) / arrow_left2->getContentSize().height);
    
    //расположение элементов на сцене
    BeginLabel->setPosition(Vec2(origin.x + visibleSize.width/2,
                           origin.y + visibleSize.height - BeginLabel->getBoundingBox().size.height ));
    
    arrow1->setPosition(Vec2(BeginLabel->getPositionX(), BeginLabel->getPositionY() - delta * 0.5));
    
    textFieldBackground->setPosition(Vec2(BeginLabel->getPositionX(),BeginLabel->getPositionY() - delta ));
    
    textField->setPosition(Vec2(textFieldBackground->getPositionX(), textFieldBackground->getPositionY()));
    
    arrow2->setPosition(Vec2(BeginLabel->getPositionX(), textFieldBackground->getPositionY() - delta / 2 ));
    
    button_next->setPosition(Vec2(BeginLabel->getPositionX(), textFieldBackground->getPositionY() - delta));
    
    button_back->setPosition(Vec2(BeginLabel->getPositionX() - button_back->getBoundingBox().size.width, BeginLabel->getPositionY() - delta * 0.5));
    arrow_left1->setPosition(Vec2(button_back->getPositionX() , BeginLabel->getPositionY()));
    
    arrow_left2->setPosition(Vec2(button_back->getPositionX() , BeginLabel->getPositionY() - button_back->getBoundingBox().size.height));
    
    

    //анимация
    auto fin_and_jake = Sprite::create("fin_jake1.png");
    fin_and_jake->setAnchorPoint(Vec2(0, 0));
    fin_and_jake->setPosition(Vec2((BeginLabel->getPositionX() - BeginLabel->getBoundingBox().size.width * 0.5 - fin_and_jake->getBoundingBox().size.width) * 0.5 , button_next->getPositionY() - fin_and_jake->getBoundingBox().size.height *  0.5));
    // now lets animate the sprite we moved
    
    Vector<SpriteFrame*> animFrames;
    animFrames.reserve(5);
    animFrames.pushBack(SpriteFrame::create("fin_jake2.png", Rect(0,0,196,126)));
    animFrames.pushBack(SpriteFrame::create("fin_jake3.png", Rect(0,0,196,126)));
    animFrames.pushBack(SpriteFrame::create("fin_jake4.png", Rect(0,0,196,126)));
    animFrames.pushBack(SpriteFrame::create("fin_jake5.png", Rect(0,0,196,126)));
    animFrames.pushBack(SpriteFrame::create("fin_jake6.png", Rect(0,0,196,126)));
    
    // create the animation out of the frames
    Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
    
    Animate* animate = Animate::create(animation);
    
    // run it and repeat it forever
    fin_and_jake->runAction(RepeatForever::create(animate));
    ///////
    
    //добавление элементов на сцену
    this->addChild(background, 0);
    this->addChild(BeginLabel, 1);
    this->addChild(textField, 1);
    this->addChild(textFieldBackground, 1);
    this->addChild(arrow1, 1);
    this->addChild(button_back, 1);
    this->addChild(arrow_left1, 1);
    this->addChild(arrow_left2, 1);
    this->addChild(button_next, 1);
    this->addChild(arrow2, 1);
    this->addChild(fin_and_jake, 1);
    
    
    return true;

}

void LobbyCreation::onNext(cocos2d::Ref* pSender)
{
    this->setVisible(false);
    auto layerMainTable = MainTable::create();
   // layerMainTable->setVisible(false);          //добавили, но не выводим на экран
    layerMainTable->setName("GameLayer");       //для поиска
    layerMainTable->userName = ((cocos2d::ui::TextField*) (this->getChildByName("fieldUserName")))->getString();
    layerMainTable->connectToAppWarp(layerMainTable);
    this->getParent()->addChild(layerMainTable);
}

void LobbyCreation::onBack(cocos2d::Ref* pSender)
{
    auto NewGameScene = MainMenu::createScene();
    Director::getInstance()->replaceScene(NewGameScene);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}