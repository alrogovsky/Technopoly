//
//  CardInfo.cpp
//  Technopoly
//
//  Created by Олег Ермаков on 21.05.15.
//
//
#include "CardInfo.h"
USING_NS_CC;
using namespace ui;

#define Margin 20
#define HeaderFont_K 24
#define Font_K 30
#define AlsoCard_K 9
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
    
    int cardIndex = std::stoi(intname);
    
    //видимый размер (разрешение экрана)
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

   // std::string name = std::to_string(intname);
    
    auto background = Sprite::create("paper.jpg");
    
    background->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    background->setScale(visibleSize.width / background->getContentSize().width, visibleSize.height / background->getContentSize().height);
    background->setOpacity(400);
    
    auto sprite = Sprite::create("cards/HighRes/" + intname + ".jpg");
    sprite->setPosition(Vec2(visibleSize.width + origin.x, visibleSize.height/2 + origin.y));
    sprite->setAnchorPoint(Vec2(1,0.5));
    float height_k = sprite->getContentSize().height/visibleSize.height;
    float scaling = 1/height_k;
    sprite->setScale(scaling);
    
    auto exit = MenuItemImage::create("menus/m8.png", "menus/m14.png",
                          [&](Ref* sender){
                              auto MainScene = this->getParent();
                              
                              auto menu1 = (Menu*) MainScene->getChildByName("menu");
                              menu1->setEnabled(true);
                              
                              auto menu2 = (Menu*) MainScene->getChildByName("table")->getChildByName("tableMenu");
                              menu2->setEnabled(true);
                              this->removeAllChildrenWithCleanup(true);
                              this->removeFromParentAndCleanup(true);
                              Director::getInstance()->getTextureCache()->removeAllTextures();
                              Director::getInstance()->getTextureCache()->addImage("1.png");
                              Director::getInstance()->getTextureCache()->addImage("2.png");
                              Director::getInstance()->getTextureCache()->addImage("3.jpg");
                              Director::getInstance()->getTextureCache()->addImage("4.jpg");
                              Director::getInstance()->getTextureCache()->addImage("5.jpg");
                              Director::getInstance()->getTextureCache()->addImage("6.jpg");
                              //this->autorelease();
                              //this->retain();
                            });
    
    exit->setPosition(Vec2(origin.x,
                      origin.y + visibleSize.height));
    exit->setAnchorPoint(Vec2(0,1));
    
    auto exitButton = Menu::create(exit, NULL);
    exitButton->setPosition(origin);
    
    auto leftPart = Node::create();
    
    Size leftPanel;
    leftPanel.width = visibleSize.width - sprite->getContentSize().width/height_k;
    leftPanel.height = visibleSize.height - exit->getContentSize().height;
    
    leftPart->setContentSize(leftPanel);
    
    auto textBackground = Sprite::create("background.png");
    float textBG_k_height = textBackground->getContentSize().height / visibleSize.height;
    float textBG_k_width = textBackground->getContentSize().width / leftPanel.width;
    textBackground->cocos2d::Node::setScale(1/textBG_k_width, 1/textBG_k_height);
    textBackground->setPosition(Vec2(origin.x, origin.y + visibleSize.height));
    textBackground->setAnchorPoint(Vec2(0,1));
    textBackground->setOpacity(700);
    
    Text* text;
    Text* textDesc;
    
    if(MainTable::dataCards[cardIndex]->type == TypeCard::Subject)
    {
        Group* myGroup = MainTable::dataCards[cardIndex]->getGroup();
        MenuItemImage* cards[myGroup->cards.size()];
        cocos2d::Vector<MenuItem*> MenuItems;
        for(int i = 0; i < myGroup->cards.size(); i++)
        {
            int index = myGroup->cards[i]->getIndex();
            std::string name = std::to_string(index);
            cards[i] = MenuItemImage::create("cards/HighRes/" + name + ".jpg", "cards/HighRes/" + name + ".jpg",
                                         [&](Ref* sender){
                                             //int a = i;
                                             MenuItemImage* senderButton = (MenuItemImage*) sender;
                                             std::string nameImage = senderButton->getName();
                                             auto NewGameScene = CardInfo::create(nameImage);
                                             auto ParentScene = this->getParent();
                                             this->removeAllChildrenWithCleanup(true);
                                             this->removeFromParentAndCleanup(true);
                                             ParentScene->addChild(NewGameScene,5);
                                         });
            cards[i]->setName(name);
            MenuItems.pushBack(cards[i]);
            cards[i]->setAnchorPoint(Vec2(0,1));
            auto size_card = cards[i]->getContentSize();
            float cardHeightK = size_card.width/visibleSize.width;
            float space_between_cards = (leftPanel.width - myGroup->cards.size() * size_card.width / (cardHeightK * AlsoCard_K)) / (myGroup->cards.size() + 1);
            cards[i]->setScale(1/(cardHeightK*AlsoCard_K));
            cards[i]->setPosition(Vec2(origin.x + (i+1) * space_between_cards + i * size_card.width / (cardHeightK * AlsoCard_K), origin.y + leftPanel.height/10 + size_card.height/(cardHeightK * AlsoCard_K)));
        }
        auto AlsoCardsMenu = Menu::createWithArray(MenuItems);
        AlsoCardsMenu->setPosition(origin);
        this->addChild(AlsoCardsMenu,2);
        
        auto AlsoCardsText = Text::create("Другие карты данной категории:","isotextpro/PFIsotextPro-Bold.ttf",visibleSize.height/HeaderFont_K);
        AlsoCardsText->ignoreContentAdaptWithSize(false);
        AlsoCardsText->setContentSize(Size(leftPanel.width - 2*Margin, leftPanel.height/10 - Margin));
        AlsoCardsText->setTextHorizontalAlignment(TextHAlignment::CENTER);
        AlsoCardsText->setPosition(Vec2(origin.x + Margin, cards[0]->getPositionY() + Margin));
        AlsoCardsText->setAnchorPoint(Vec2(0,0));
        AlsoCardsText->setColor(Color3B::WHITE);
        
        text = Text::create(myGroup->getName(),"isotextpro/PFIsotextPro-Bold.ttf",visibleSize.height/HeaderFont_K);
        text->ignoreContentAdaptWithSize(false);
        text->setContentSize(Size(leftPanel.width - 2*Margin, leftPanel.height/12 - Margin));
        text->setTextHorizontalAlignment(TextHAlignment::CENTER);
        text->setPosition(Vec2(origin.x + Margin, origin.y + leftPanel.height - Margin));
        text->setAnchorPoint(Vec2(0,1));
        text->setColor(Color3B::WHITE);
        
        /*
        textDesc = Text::create(myGroup->getDescription(),"isotextpro/PFIsotextPro-Light.ttf",visibleSize.height/Font_K);
        textDesc->ignoreContentAdaptWithSize(false);
        textDesc->setContentSize(Size(leftPanel.width - 2*Margin, leftPanel.height/6 - Margin));
        textDesc->setTextHorizontalAlignment(TextHAlignment::LEFT);
        textDesc->setPosition(Vec2(origin.x + Margin, text->getPositionY() - text->getContentSize().height - Margin));
        textDesc->setAnchorPoint(Vec2(0,1));
        textDesc->setColor(Color3B::WHITE);
         */
        textDesc = Text::create(myGroup->getDescription(),"isotextpro/PFIsotextPro-Light.ttf",visibleSize.height/Font_K);
        textDesc->ignoreContentAdaptWithSize(false);
        textDesc->setContentSize(Size(leftPanel.width - 2*Margin, leftPanel.height/3 - Margin));
        textDesc->setTextHorizontalAlignment(TextHAlignment::LEFT);
        textDesc->setPosition(Vec2(origin.x + Margin, text->getPositionY() - text->getContentSize().height - Margin));
        textDesc->setAnchorPoint(Vec2(0,1));
        textDesc->setColor(Color3B::WHITE);
        
        std::string Owner = "Приобретено:" + ((SubjectCard*)MainTable::dataCards[cardIndex])->getOwnerName();
        auto OwnerText = Text::create(Owner,"isotextpro/PFIsotextPro-Light.ttf",visibleSize.height/Font_K);
        OwnerText->ignoreContentAdaptWithSize(false);
        OwnerText->setContentSize(Size(leftPanel.width - 2*Margin, leftPanel.height/3 - Margin));
        OwnerText->setTextHorizontalAlignment(TextHAlignment::LEFT);
        OwnerText->setPosition(Vec2(origin.x + Margin, textDesc->getPositionY() - textDesc->getContentSize().height - Margin));
        OwnerText->setAnchorPoint(Vec2(0,1));
        OwnerText->setColor(Color3B::WHITE);
        
        /*
        auto cardHeader = Text::create(MainTable::dataCards[cardIndex]->getName(),"isotextpro/PFIsotextPro-Bold.ttf",visibleSize.height/HeaderFont_K);
        cardHeader->ignoreContentAdaptWithSize(false);
        cardHeader->setContentSize(Size(leftPanel.width - 2*Margin, leftPanel.height/12 - Margin));
        cardHeader->setTextHorizontalAlignment(TextHAlignment::CENTER);
        cardHeader->setPosition(Vec2(origin.x + Margin, textDesc->getPositionY() - textDesc->getContentSize().height - Margin));
        cardHeader->setAnchorPoint(Vec2(0,1));
        cardHeader->setColor(Color3B::WHITE);
        */
       /* auto cardHeader = Text::create(MainTable::dataCards[cardIndex]->getName(),"isotextpro/PFIsotextPro-Bold.ttf",visibleSize.height/HeaderFont_K);
        cardHeader->ignoreContentAdaptWithSize(false);
        cardHeader->setContentSize(Size(leftPanel.width - 2*Margin, leftPanel.height/12 - Margin));
        cardHeader->setTextHorizontalAlignment(TextHAlignment::CENTER);
        cardHeader->setPosition(Vec2(origin.x + Margin, textDesc->getPositionY() - textDesc->getContentSize().height - Margin));
        cardHeader->setAnchorPoint(Vec2(0,1));
        cardHeader->setColor(Color3B::WHITE);
        
        auto cardDesc = Text::create(MainTable::dataCards[cardIndex]->getDescription(),"isotextpro/PFIsotextPro-Light.ttf",visibleSize.height/Font_K);
        cardDesc->ignoreContentAdaptWithSize(false);
        cardDesc->setContentSize(Size(leftPanel.width - 2*Margin, leftPanel.height/6 - Margin));
        cardDesc->setTextHorizontalAlignment(TextHAlignment::LEFT);
        cardDesc->setPosition(Vec2(origin.x + Margin, cardHeader->getPositionY() - cardHeader->getContentSize().height - Margin));
        cardDesc->setAnchorPoint(Vec2(0,1));
        cardDesc->setColor(Color3B::WHITE);
        
        leftPart->addChild(cardHeader,3);
        leftPart->addChild(cardDesc,3);*/
        leftPart->addChild(AlsoCardsText,3);
        leftPart->addChild(OwnerText);
    }
    else
    {
        /*
        text = Text::create(MainTable::dataCards[cardIndex]->getName(),"isotextpro/PFIsotextPro-Bold.ttf",visibleSize.height/HeaderFont_K);
        text->ignoreContentAdaptWithSize(false);
        text->setContentSize(Size(leftPanel.width - 2*Margin, leftPanel.height/10 - Margin));
        text->setTextHorizontalAlignment(TextHAlignment::CENTER);
        text->setPosition(Vec2(origin.x + Margin, origin.y + leftPanel.height - Margin));
        text->setAnchorPoint(Vec2(0,1));
        text->setColor(Color3B::WHITE);
        
        
        textDesc = Text::create(MainTable::dataCards[cardIndex]->getDescription(),"isotextpro/PFIsotextPro-Light.ttf",visibleSize.height/Font_K);
        textDesc->ignoreContentAdaptWithSize(false);
        textDesc->setContentSize(Size(leftPanel.width - 2*Margin, leftPanel.height*4/5 - text->getContentSize().height));
        textDesc->setTextHorizontalAlignment(TextHAlignment::CENTER);
        textDesc->setPosition(Vec2(origin.x + Margin, text->getPositionY() - text->getContentSize().height - Margin));
        textDesc->setAnchorPoint(Vec2(0,1));
        textDesc->setColor(Color3B::WHITE);
         */
        text = Text::create(MainTable::dataCards[cardIndex]->getName(),"isotextpro/PFIsotextPro-Bold.ttf",visibleSize.height/HeaderFont_K);
        text->ignoreContentAdaptWithSize(false);
        text->setContentSize(Size(leftPanel.width - 2*Margin, leftPanel.height/10 - Margin));
        text->setTextHorizontalAlignment(TextHAlignment::CENTER);
        text->setPosition(Vec2(origin.x + Margin, origin.y + leftPanel.height - Margin));
        text->setAnchorPoint(Vec2(0,1));
        text->setColor(Color3B::WHITE);
        
        
        textDesc = Text::create(MainTable::dataCards[cardIndex]->getDescription(),"isotextpro/PFIsotextPro-Light.ttf",visibleSize.height/Font_K);
        textDesc->ignoreContentAdaptWithSize(false);
        textDesc->setContentSize(Size(leftPanel.width - 2*Margin, leftPanel.height*4/5 - text->getContentSize().height));
        textDesc->setTextHorizontalAlignment(TextHAlignment::CENTER);
        textDesc->setPosition(Vec2(origin.x + Margin, text->getPositionY() - text->getContentSize().height - Margin));
        textDesc->setAnchorPoint(Vec2(0,1));
        textDesc->setColor(Color3B::WHITE);
    }
    
    leftPart->addChild(text,2);
    leftPart->addChild(textDesc,2);
    leftPart->setPosition(Vec2::ZERO);
    this->addChild(leftPart,2);
    this->addChild(sprite,2);
    this->addChild(textBackground,1);
    this->addChild(background,0);
    this->addChild(exitButton, 2);
    return true;
}

