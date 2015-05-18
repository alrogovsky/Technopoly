//
//  MainTableScene.cpp
//  Technopoly
//
//  Created by Олег Ермаков on 11.05.15.
//
//

#include "MainTableScene.h"
USING_NS_CC;
Scene* MainTable::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainTable::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    Director::getInstance()->getTextureCache()->addImage("1.png");
    Director::getInstance()->getTextureCache()->addImage("2.png");
    Director::getInstance()->getTextureCache()->addImage("3.jpg");
    Director::getInstance()->getTextureCache()->addImage("4.jpg");
    Director::getInstance()->getTextureCache()->addImage("5.jpg");
    Director::getInstance()->getTextureCache()->addImage("6.jpg");
    // return the scene
    return scene;
}
bool MainTable::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MainTable::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
   // auto menu = Menu::create(closeItem, NULL);
   // menu->setPosition(Vec2::ZERO);
   // this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    
    
    // Рандома
    boost::random::mt11213b rng;
    unsigned int seed = 0;
    rng.seed((++seed) + time(NULL));
    boost::random::uniform_int_distribution<> six(1,6);
    int random_num1 = six(rng);
    
    
    std::string string_random_num1= std::to_string(random_num1);
    auto cube1_img = Label::createWithTTF(string_random_num1, "fonts/Marker Felt.ttf", 24);
    
    cube1_img->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - cube1_img->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(cube1_img, 1);
    
    cube1 = Sprite::create("1.png");
    switch (random_num1) {
        case (2): cube1 = Sprite::create("2.png"); break;
        case (3): cube1 = Sprite::create("3.jpg"); break;
        case (4): cube1 = Sprite::create("4.jpg"); break;
        case (5): cube1 = Sprite::create("5.jpg"); break;
        case (6): cube1 = Sprite::create("6.jpg"); break;
        default: break;
    }
    
    // position the sprite on the center of the screen
    cube1->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height/2));
    
    // add the sprite as a child to this layer
    this->addChild(cube1, 1);
    
    int random_num2 = six(rng);
    std::string string_random_num2= std::to_string(random_num2);
    auto cube2_img = Label::createWithTTF(string_random_num2, "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    cube2_img->setPosition(Vec2(origin.x + 100 +  visibleSize.width/2,
                                origin.y + visibleSize.height - cube2_img->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(cube2_img, 1);
    
    cube2 = Sprite::create("1.png");
    switch (random_num2) {
        case (2): cube2 = Sprite::create("2.png"); break;
        case (3): cube2 = Sprite::create("3.jpg"); break;
        case (4): cube2 = Sprite::create("4.jpg"); break;
        case (5): cube2 = Sprite::create("5.jpg"); break;
        case (6): cube2 = Sprite::create("6.jpg"); break;
        default: break;
    }
    
    // position the sprite on the center of the screen
    cube2->setPosition(Vec2(origin.x + 100 + visibleSize.width/2 ,
                            origin.y + visibleSize.height/2));
    
    // add the sprite as a child to this layer
    this->addChild(cube2, 1);
    
    auto StepButtonLabel = Label::createWithTTF("Сделать ход", "isotextpro/PFIsotextPro-Regular.ttf", 34);
    StepButtonLabel -> setColor(Color3B::BLACK);
    auto StepButton = MenuItemLabel::create(StepButtonLabel, CC_CALLBACK_1(MainTable::onStepQlick, this));
    StepButton->setPosition(Vec2(origin.x + visibleSize.width/2,
                              origin.y + StepButton->getContentSize().height));
    Vector<MenuItem*> MenuItems;
    MenuItems.pushBack(StepButton);
    MenuItems.pushBack(closeItem);
  //  menu->setPosition(Vec2::ZERO);
    
    auto sprite = Sprite::create("paper.jpg");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    auto card = Sprite::create("cards/1.JPG");
    card->setPosition(Vec2(origin.x, origin.y));
    card->setAnchorPoint(Vec2(0,0));
    auto size_card = card->getContentSize();
    float height_k = size_card.height/visibleSize.height;
    card->setScale(1/(height_k*Height_K));
    
    auto card1 = Sprite::create("cards/Card.png");
    card1->setPosition(Vec2(origin.x + card->getContentSize().width * 1/(height_k*Height_K), origin.y));
    card1->setAnchorPoint(Vec2(0,0));
    size_card = card1->getContentSize();
    height_k = size_card.height/visibleSize.height;
    card1->setScale(1/(height_k*Height_K));
    
    auto card2 = Sprite::create("cards/Card11_converted.png");
    card2->setPosition(Vec2(origin.x + card1->getPosition().x + card1->getContentSize().width * 1/(height_k*Height_K), origin.y));
    card2->setAnchorPoint(Vec2(0,0));
    size_card = card2->getContentSize();
    height_k = size_card.height/visibleSize.height;
    card2->setScale(1/(height_k*Height_K));

    
    auto menu = Menu::createWithArray(MenuItems);
    menu->setPosition(Vec2::ZERO);

    this->addChild(sprite, 0);
    this->addChild(card,1);
    this->addChild(card1,1);
    this->addChild(card2,1);
    this->addChild(menu, 1);
    return true;
}

void MainTable::onStepQlick(Ref *pSender)
{
    rng.seed((++seed) + time(NULL));
    boost::random::uniform_int_distribution<> six(1,6);
    
    random_num1 = six(rng);
    random_num2 = six(rng);
    
    std::string string_random_num1= std::to_string(random_num1);
    std::string string_random_num2= std::to_string(random_num2);

    
    cube1 -> setTexture(Director::getInstance()->getTextureCache()->getTextureForKey("1.png"));
    switch (random_num1) {
        case (2): cube1 -> setTexture(Director::getInstance()->getTextureCache()->getTextureForKey("2.png")); break;
        case (3): cube1 -> setTexture(Director::getInstance()->getTextureCache()->getTextureForKey("3.jpg")); break;
        case (4): cube1 -> setTexture(Director::getInstance()->getTextureCache()->getTextureForKey("4.jpg")); break;
        case (5): cube1 -> setTexture(Director::getInstance()->getTextureCache()->getTextureForKey("5.jpg")); break;
        case (6): cube1 -> setTexture(Director::getInstance()->getTextureCache()->getTextureForKey("6.jpg")); break;
        default: break;
    }
    
    cube2 -> setTexture(Director::getInstance()->getTextureCache()->getTextureForKey("1.png"));
    switch (random_num2) {
        case (2): cube2 -> setTexture(Director::getInstance()->getTextureCache()->getTextureForKey("2.png")); break;
        case (3): cube2 -> setTexture(Director::getInstance()->getTextureCache()->getTextureForKey("3.jpg")); break;
        case (4): cube2 -> setTexture(Director::getInstance()->getTextureCache()->getTextureForKey("4.jpg")); break;
        case (5): cube2 -> setTexture(Director::getInstance()->getTextureCache()->getTextureForKey("5.jpg")); break;
        case (6): cube2 -> setTexture(Director::getInstance()->getTextureCache()->getTextureForKey("6.jpg")); break;
        default: break;
    }
}

void MainTable::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
