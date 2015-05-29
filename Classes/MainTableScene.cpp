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
    //запуск сцены
    auto scene = Scene::create();
    
    auto layerLobby = LobbyCreation::create();
    scene->addChild(layerLobby);
    
    //инициализация данных
    //InitData();
    
    return scene;
}

bool MainTable::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
    
    //добавление в кэш текстур изображения кубиков
    Director::getInstance()->getTextureCache()->addImage("1.png");
    Director::getInstance()->getTextureCache()->addImage("2.png");
    Director::getInstance()->getTextureCache()->addImage("3.jpg");
    Director::getInstance()->getTextureCache()->addImage("4.jpg");
    Director::getInstance()->getTextureCache()->addImage("5.jpg");
    Director::getInstance()->getTextureCache()->addImage("6.jpg");
    
   // connectToAppWarp(this);
    
    //общий размер
    Size fullSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();                  // первоначальная координата
    
    //кнопка закрытия
    auto exit = MenuItemImage::create("menus/m8.png", "menus/m14.png",
                                      [&](Ref* sender){
                                          auto NewGameScene = MainMenu::createScene();
                                          Director::getInstance()->replaceScene(NewGameScene);
                                      });
    
    //размеры окна
    Size visibleSize = Director::getInstance()->getVisibleSize();               // общий размер ...
    visibleSize.height = visibleSize.height - exit->getContentSize().height/2;  //... без верхнего меню
    
    
    //продолжаю пилить кнопку закрытия
    exit->setPosition(Vec2(origin.x,
                           origin.y + fullSize.height));
    exit->setAnchorPoint(Vec2(0,1));
    exit->setScale(0.5);
    auto exitButton = Menu::create(exit, NULL);
    exitButton->setPosition(origin);
    this->addChild(exitButton,3);
    
    
    //для объединения карточек в один 'node'
    table = Node::create();
    table->setContentSize(Size(visibleSize.height, visibleSize.height));
    table->setPosition(Vec2(origin.x + table->getContentSize().width/2, origin.y + table->getContentSize().height/2));
    table->setAnchorPoint(Vec2(0.5,0.5));
    createTable(table);
    
    //закрывающее меню
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MainTable::menuCloseCallback, this));
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    //рандом
    boost::random::mt11213b rng;
    unsigned int seed = 0;
    rng.seed((++seed) + time(NULL));
    boost::random::uniform_int_distribution<> six(1,6);
    int random_num1 = six(rng);

    //изображения кубиков
    cube1 = Sprite::create("1.png");
    switch (random_num1) {
        case (2): cube1 = Sprite::create("2.png"); break;
        case (3): cube1 = Sprite::create("3.jpg"); break;
        case (4): cube1 = Sprite::create("4.jpg"); break;
        case (5): cube1 = Sprite::create("5.jpg"); break;
        case (6): cube1 = Sprite::create("6.jpg"); break;
        default: break;
    }
    int random_num2 = six(rng);
    cube2 = Sprite::create("1.png");
    switch (random_num2) {
        case (2): cube2 = Sprite::create("2.png"); break;
        case (3): cube2 = Sprite::create("3.jpg"); break;
        case (4): cube2 = Sprite::create("4.jpg"); break;
        case (5): cube2 = Sprite::create("5.jpg"); break;
        case (6): cube2 = Sprite::create("6.jpg"); break;
        default: break;
    }
    
    
    //боковое меню (справа)
    float MenuWidth = visibleSize.width - (table->getPosition().x + table->getContentSize().width/2);
    
    //сделать ход пользователем
    auto StepButtonLabel = Label::createWithTTF("Сделать ход", "isotextpro/PFIsotextPro-Regular.ttf", 34);
    StepButtonLabel -> setColor(Color3B::BLACK);
    StepButton = MenuItemLabel::create(StepButtonLabel, CC_CALLBACK_1(MainTable::onStepQlick, this));
    StepButton->setPosition(Vec2(table->getPosition().x + table->getContentSize().width/2 + MenuWidth/2,
                              origin.y + visibleSize.height/2));
    
    //поворот доски
    auto RotateRight = Label::createWithTTF("Направо", "isotextpro/PFIsotextPro-Regular.ttf", 34);
    RotateRight -> setColor(Color3B::BLACK);
    auto RotateRightButton = MenuItemLabel::create(RotateRight, CC_CALLBACK_1(MainTable::onRotateRight, this));
    RotateRightButton->setPosition(Vec2(table->getPosition().x + table->getContentSize().width/2 + MenuWidth/2,
                                 origin.y + visibleSize.height/2 - StepButton->getContentSize().height - 5));
    
    auto RotateLeft = Label::createWithTTF("Налево", "isotextpro/PFIsotextPro-Regular.ttf", 34);
    RotateLeft -> setColor(Color3B::BLACK);
    auto RotateLeftButton = MenuItemLabel::create(RotateLeft, CC_CALLBACK_1(MainTable::onRotateLeft, this));
    RotateLeftButton->setPosition(Vec2(table->getPosition().x + table->getContentSize().width/2 + MenuWidth/2,
                                        origin.y + visibleSize.height/2 - StepButton->getContentSize().height - RotateRightButton->getContentSize().height - 10));
    
    
    //Тест... просто Тест...
    auto Test = Label::createWithTTF("Test", "isotextpro/PFIsotextPro-Regular.ttf", 34);
    Test -> setColor(Color3B::BLACK);
    auto TestButton = MenuItemLabel::create(Test, CC_CALLBACK_1(MainTable::onTest, this));
    TestButton->setPosition(Vec2(table->getPosition().x + table->getContentSize().width/2 + MenuWidth/2,
                                        origin.y + visibleSize.height/2 - StepButton->getContentSize().height - 80));

    //Все в менюшный вектор
    Vector<MenuItem*> MenuItems;
    MenuItems.pushBack(StepButton);
    MenuItems.pushBack(closeItem);
    MenuItems.pushBack(RotateRightButton);
    MenuItems.pushBack(RotateLeftButton);
    MenuItems.pushBack(TestButton);
    
    //Создаем работоспособное меню на основе массива менюшек
    auto menu = Menu::createWithArray(MenuItems);
    menu->setPosition(Vec2::ZERO);
    menu->setName("menu");        // для дальнейшего поиска данного объекта в CardInfo
    menu->setTag(1);              // аналогично, для поиска
    
    //фон
    auto sprite = Sprite::create("paper.jpg");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    //позиция кубиков
    cube1->setPosition(Vec2(table->getPosition().x + table->getContentSize().width/2 + MenuWidth/2 + cube1->getContentSize().width,
                            origin.y + visibleSize.height - cube1->getContentSize().height));
    
    
    cube2->setPosition(Vec2(table->getPosition().x + table->getContentSize().width/2 + MenuWidth/2 - cube2->getContentSize().width,
                            origin.y + visibleSize.height - cube2->getContentSize().height));
    
    
    //все объекты на сцену
    this->addChild(cube2, 1);   //кубики
    this->addChild(cube1, 1);
    this->addChild(sprite, 0);  //фон
    table->addChild(tableMenu); //для дальнейшего поиска в CardInfo
    table->setName("table");
    this->addChild(table,1);    //стол с картами
    this->addChild(menu, 1);
    
    //Фишка 1игрока
    chip1 = Sprite::create("fishka1.png");
    chip1->setAnchorPoint(Vec2(0.9, 0.2));
    auto size_chip1 = chip1->getContentSize();
    float height_sprite1 = size_chip1.width / visibleSize.width;
    chip1->setScale(1 / (height_sprite1 * Height_K * 4));
    table->addChild(chip1,2);
    chip1->setPosition(cards[0]->getPosition());
    current_position1 = 0;
    
    //Фишка 2игрока
    chip2 = Sprite::create("fishka1.png");
    chip2->setAnchorPoint(Vec2(0.9, 1.4));
    auto size_chip2 = chip2->getContentSize();
    float height_sprite2 = size_chip2.width / visibleSize.width;
    chip2->setScale(1 / (height_sprite2 * Height_K * 4));
    table->addChild(chip2,2);
    chip2->setPosition(cards[0]->getPosition());
    current_position2 = 0;

    
    //---------ВЫБОР ЛОББИ--------
    cocos2d::Layer* LobbyChoose = Layer::create();
    LobbyChoose->setName("Lobby");
    this->addChild(LobbyChoose,5);
    LobbyChoose->setPosition(origin);
    LobbyChoose->setContentSize(fullSize);
    auto background = Sprite::create("paper.jpg");
    background->setPosition(Vec2(fullSize.width/2 + origin.x, fullSize.height/2 + origin.y));
    background->setOpacity(400);
    LobbyChoose->addChild(background);
    tableMenu->setEnabled(false);
    ((Menu*) (this->getChildByName("menu")))->setEnabled(false);
    auto exitLobby = MenuItemImage::create("menus/m8.png", "menus/m14.png",
                                      [&](Ref* sender){
                                          tableMenu->setEnabled(true);
                                          ((Menu*) (this->getChildByName("menu")))->setEnabled(true);
                                          this->removeChildByName("Lobby");
                                          //this->autorelease();
                                          //this->retain();
                                      });
    
    exitLobby->setPosition(Vec2(origin.x + exitLobby->getContentSize().width,
                           origin.y + visibleSize.height - exitLobby->getContentSize().height));
    
    auto exitLobbyButton = Menu::create(exitLobby, NULL);
    exitLobbyButton->setPosition(origin);
    LobbyChoose->addChild(exitLobbyButton);
    //---------ВЫБОР ЛОББИ--------
    
    return true;
}

void MainTable::onStepQlick(Ref *pSender)
{
    //рандомизатор
    rng.seed((++seed) + time(NULL));
    boost::random::uniform_int_distribution<> six(1,6);
    
    random_num1 = six(rng);
    random_num2 = six(rng);
    
    std::string string_random_num1= std::to_string(random_num1);
    std::string string_random_num2= std::to_string(random_num2);
    std::string string_sum = std::to_string(random_num1+random_num2);
    
    //пилим текстуру, в зависимости от выпавшего номера
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
    
    //Сделать шаг
    StepButton->setEnabled(false);
    StepButton->setOpacity(0);
    userStep(chip1, random_num1 + random_num2, &current_position1 );
    sendData("M"+string_sum);
    

   }

void MainTable::menuCloseCallback(Ref* pSender)
{
    AppWarp::Client *warpClientRef;
    warpClientRef->getInstance();
    warpClientRef->disconnect();
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void MainTable::onRotateRight(Ref* pSender)
{
    float current_rotation = table->getRotation();
    table->setRotation(current_rotation + 90);
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void MainTable::onRotateLeft(Ref* pSender)
{
    float current_rotation = table->getRotation();
    table->setRotation(current_rotation - 90);
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void MainTable::onTest(cocos2d::Ref *pSender)
{
    AppWarp::Client *warpClientRef;
    warpClientRef = AppWarp::Client::getInstance();
    warpClientRef->getOnlineUsers();
    std::cout<<"\n";
    warpClientRef->getLiveUserInfo(this->userName);
    warpClientRef->getAllRooms();
}

void MainTable::createTable(Node* Table)
{
    auto visibleSize = Table->getContentSize();
    std::string name = "";
    for(int i = 0; i < numbers_of_cards; i++)
    {
        name = std::to_string(i);
        cards[i] = MenuItemImage::create("cards/LowRes/" + name + ".jpg", "cards/LowRes/" + name + ".jpg",
          [&](Ref* sender){
              //int a = i;
              MenuItemImage* senderButton = (MenuItemImage*) sender;
              std::string nameImage = senderButton->getName();
              auto NewGameScene = CardInfo::create(nameImage);
              this->addChild(NewGameScene,5);
              tableMenu->setEnabled(false);
              ((Menu*) (this->getChildByName("menu")))->setEnabled(false);
          });
        cards[i]->setName(name);
    }
    
    //первая карта
    cards[0]->setAnchorPoint(Vec2(0.5,0.5));
    auto size_card = cards[0]->getContentSize();
    float height_k = size_card.width/visibleSize.width;
    cards[0]->setScale(1/(height_k*Height_K));
    cards[0]->setPosition(Vec2(visibleSize.width - cards[0]->getContentSize().width/(2*(height_k*Height_K)),
                           cards[0]->getContentSize().height/(2*(height_k*Height_K))));
    
    //нижний ряд
    addLeft(cards[1], cards[0], visibleSize, true);
    for(int i = 2; i <= 10; i++)
        addLeft(cards[i], cards[i-1], visibleSize, false);
    
    //левый ряд
    addTop(cards[11], cards[10], visibleSize, true);
    for(int i = 12; i <= 20; i++)
        addTop(cards[i], cards[i-1], visibleSize, false);
    
    //верхний ряд
    addRight(cards[21], cards[20], visibleSize, true);
    for(int i = 22; i <= 30; i++)
        addRight(cards[i], cards[i-1], visibleSize, false);
    
    //правый ряд
    addBottom(cards[31], cards[30], visibleSize, true);
    for(int i = 32; i < 40; i++)
        addBottom(cards[i], cards[i-1], visibleSize, false);
    
    auto BaseSprite = Sprite::create("cards/base.jpg");
    BaseSprite->setAnchorPoint(Vec2(0.5,0.5));
    size_card = BaseSprite->getContentSize();
    height_k = size_card.width/visibleSize.width;
    BaseSprite->setScale(1/(height_k));
    BaseSprite->setPosition(Vec2(visibleSize.width/2,
                               visibleSize.height/2));
    
    //создается меню
    tableMenu = Menu::create();
    tableMenu->setName("tableMenu"); //дальнейший поиск
    for(int i = 0; i < 40; i++)
    {
        tableMenu->addChild(cards[i]);
    }
    tableMenu->setPosition(0, 0);
    table->addChild(BaseSprite);
}

void MainTable::addTop(Node* spr, Node* oldspr, Size table, bool isFirst)
{
    auto old_position = oldspr->getPosition();
    
    float old_width = 0;
    float old_k = oldspr->getContentSize().height/table.height;
    
    if(isFirst)
        old_width = oldspr->getContentSize().height/(old_k * Height_K);
    else
        old_width = oldspr->getContentSize().width/(old_k * Height_K);
    
    float k = spr->getContentSize().height/table.height;
    auto new_width = spr->getContentSize().width/(k * Height_K);
    
    spr->setPosition(old_position.x, old_position.y + old_width/2 + new_width/2);
    spr->setRotation(90);
    spr->setAnchorPoint(Vec2(0.5,0.5));
    spr->setScale(1/(k*Height_K));
}

void MainTable::addRight(Node* spr, cocos2d::Node* oldspr, Size table, bool isFirst)
{
    auto old_position = oldspr->getPosition();
    
    float old_width = 0;
    float old_k = oldspr->getContentSize().height/table.height;
    
    if(isFirst)
        old_width = oldspr->getContentSize().height/(old_k * Height_K);
    else
        old_width = oldspr->getContentSize().width/(old_k * Height_K);
    
    float k = spr->getContentSize().height/table.height;
    auto new_width = spr->getContentSize().width/(k * Height_K);
    
    spr->setPosition(old_position.x + old_width/2 + new_width/2, old_position.y);
    spr->setRotation(180);
    spr->setAnchorPoint(Vec2(0.5,0.5));
    spr->setScale(1/(k*Height_K));
}

void MainTable::addLeft(Node* spr, cocos2d::Node* oldspr, Size table, bool isFirst)
{
    auto old_position = oldspr->getPosition();
    
    float old_width = 0;
    float old_k = oldspr->getContentSize().height/table.height;
    
    if(isFirst)
        old_width = oldspr->getContentSize().height/(old_k * Height_K);
    else
        old_width = oldspr->getContentSize().width/(old_k * Height_K);
    
    float k = spr->getContentSize().height/table.height;
    auto new_width = spr->getContentSize().width/(k * Height_K);
    
    spr->setPosition(old_position.x - old_width/2 - new_width/2, old_position.y);
    spr->setRotation(0);
    spr->setAnchorPoint(Vec2(0.5,0.5));
    spr->setScale(1/(k*Height_K));}

void MainTable::addBottom(Node* spr, cocos2d::Node* oldspr, Size table, bool isFirst)
{
    auto old_position = oldspr->getPosition();
    
    float old_width = 0;
    float old_k = oldspr->getContentSize().height/table.height;
    
    if(isFirst)
        old_width = oldspr->getContentSize().height/(old_k * Height_K);
    else
        old_width = oldspr->getContentSize().width/(old_k * Height_K);
    
    float k = spr->getContentSize().height/table.height;
    auto new_width = spr->getContentSize().width/(k * Height_K);
    
    spr->setPosition(old_position.x, old_position.y - old_width/2 - new_width/2);
    spr->setRotation(270);
    spr->setAnchorPoint(Vec2(0.5,0.5));
    spr->setScale(1/(k*Height_K));
}


void MainTable::userStep(Node* spr,int strokes_number, int* curr_pos)
{
    
    int new_pos = (*curr_pos + strokes_number) % numbers_of_cards;
    int new_pos_delta = new_pos / 10;
    int old_pos_delta = *curr_pos / 10;
    
    RotateTo* rotateTo = RotateTo::create(0.0f, old_pos_delta * 90.0f);
    MoveTo* move_to_chip = MoveTo::create(0, spr->getPosition());
    if (new_pos_delta > old_pos_delta || new_pos_delta < old_pos_delta) {
        move_to_chip = MoveTo::create(1, cards[new_pos_delta * 10]->getPosition());
        rotateTo = RotateTo::create(1.0f, new_pos_delta * 90.0f);
    }
    auto move_to_chip2 = MoveTo::create(1, cards[new_pos]->getPosition());
    
    step_sequence = Sequence::create( move_to_chip, rotateTo, move_to_chip2, NULL);
    spr->runAction(step_sequence);
    *curr_pos = new_pos;
}


/// APPWARP
void MainTable::connectToAppWarp(Ref *pSender)
{
    AppWarp::Client *warpClientRef;
    AppWarp::Client::initialize(APPWARP_APP_KEY, APPWARP_SECRET_KEY);
    warpClientRef = AppWarp::Client::getInstance();
    warpClientRef->setRecoveryAllowance(60);
    warpClientRef->setConnectionRequestListener(this);
    warpClientRef->setNotificationListener(this);
    warpClientRef->setRoomRequestListener(this);
    warpClientRef->setZoneRequestListener(this);
    warpClientRef->connect(this->userName);
    //warpClientRef->getLiveRoomInfo(ROOM_ID);
}

void MainTable::startGame()
{
    
}

void MainTable::pauseGame()
{
    
}


void MainTable::onConnectDone(int res, int reasonCode)
{
    if(res == AppWarp::ResultCode::success)
    {
        cocos2d::MessageBox("CONNECTION", "SUCCESS");
        AppWarp::Client *warpClientRef;
        warpClientRef = AppWarp::Client::getInstance();
        warpClientRef->joinRoom(ROOM_ID);
    } else {
        printf("ERROR %d", res);
        connectToAppWarp(this);
    }
}

void MainTable::onJoinRoomDone(AppWarp::room revent)
{
    if (revent.result==0)
    {
        printf("\nonJoinRoomDone .. SUCCESS\n");
        AppWarp::Client *warpClientRef;
        warpClientRef = AppWarp::Client::getInstance();
        warpClientRef->subscribeRoom(ROOM_ID);
    }
    else
        printf("\nonJoinRoomDone .. FAILED\n");
}

void MainTable::onSubscribeRoomDone(AppWarp::room revent)
{
    if (revent.result==0)
    {
        printf("\nonSubscribeRoomDone .. SUCCESS\n");
    }
    else
        printf("\nonSubscribeRoomDone .. FAILED\n");
}

void MainTable::sendData(std::string message = "")
{
    AppWarp::Client *warpClientRef;
    warpClientRef = AppWarp::Client::getInstance();
    warpClientRef->sendChat(message);
}

void MainTable::onChatReceived(AppWarp::chat chatevent)
{
    std::cout<<"SENDER: "<<chatevent.sender <<" onChatReceived: ";
    std::string str2 = chatevent.chat.substr();
    std::cout<<str2;
    if(chatevent.sender != this->userName)
    {
        std::size_t loc = chatevent.chat.find('M');
        std::string str1 = chatevent.chat.substr(loc+1);
        
        int step = std::atof(str1.c_str());
        
        userStep(chip2, step, &current_position2);
        StepButton->setOpacity(255);
        StepButton->setEnabled(true);

    }
    
}

void MainTable::onGetOnlineUsersDone(AppWarp::liveresult event)
{
    std::cout<< "ONLINE: ";
    for(int i = 0; i<event.list.size(); i++)
    {
        std::cout<<event.list[i]<<" ";
    }
}

void MainTable::onGetLiveUserInfoDone( AppWarp::liveuser event )
{
    std::cout<<"DATA OF "<<event.name<<": "<<event.customData<<" ";
}

void MainTable::onGetLiveRoomInfoDone(AppWarp :: liveroom event)
{
   
}

void MainTable::onSetCustomRoomDataDone(AppWarp::liveroom event)
{
    
}


void MainTable::onGetAllRoomsDone(AppWarp::liveresult event)
{
    for(int i = 0; i<event.list.size(); i++)
    {
        std::cout<<event.list[i]<<" ";
    }
}


void MainTable::onUserPaused(std::string user, std::string locId, bool isLobby)
{
    
}


void MainTable::onUserResumed(std::string user, std::string locId, bool isLobby)
{
    
}