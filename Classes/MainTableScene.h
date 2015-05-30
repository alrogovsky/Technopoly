//
//  MainTableScene.h
//  Technopoly
//
//  Created by Олег Ермаков on 11.05.15.
//
//

#ifndef __Technopoly__MainTableScene__
#define __Technopoly__MainTableScene__

#include "cocos2d.h"
#include "boost/random.hpp"

#include "appwarp.h"
#include "MainMenu.h"
#include "CardInfo.h"

#include "Gameplay.h"

#define Height_K 7.35

#define APPWARP_APP_KEY     "e9e179212bf8ab524908f4f2449a5399469a41b7a10c73d653bbc30af77141b2"
#define APPWARP_SECRET_KEY  "6c8de95986e7916ac1faf63972e953e87f50dacd4075a2eec2b24c91f0c92339"
#define ROOM_ID "1799451657"

void InitData();

class MainTable :   public cocos2d::Layer,
                    public AppWarp::ConnectionRequestListener,
                    public AppWarp::RoomRequestListener,
                    public AppWarp::NotificationListener,
                    public AppWarp::ZoneRequestListener
{
public:
    // создание кнопок для карт
    static const int numbers_of_cards = 40;
    static const int numbers_of_groups = 8;
    cocos2d::MenuItemImage* cards [numbers_of_cards];
    cocos2d::Vector<cocos2d::MenuItem*> tableButtons;
    cocos2d::Menu* tableMenu;
    
    // функция создания сцены
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    //данные
    static Card** dataCards;    //данные о картах
    static Group* Groups;       //данные о группах
    
    // исходное положение фишек
    int current_position1 = 0;
    int current_position2 = 0;
    
    // создание стола с картами
    cocos2d::Node* table;                                                       // для работы с поворотом
    void createTable(cocos2d::Node* Table);                                     // создание стола
    void addRight   (cocos2d::Node*, cocos2d::Node*, cocos2d::Size, bool);      // добавление карты справа
    void addLeft    (cocos2d::Node*, cocos2d::Node*, cocos2d::Size, bool);      // добавление карты слева
    void addTop     (cocos2d::Node*, cocos2d::Node*, cocos2d::Size, bool);      // добавление карты сверху
    void addBottom  (cocos2d::Node*, cocos2d::Node*, cocos2d::Size, bool);      // добавление карты снизу
    
    // шаг пользователя
    cocos2d::MenuItemLabel* StepButton;
    void userStep(cocos2d::Node* spr,int strokes_number, int* curr_pos);
    
    // кубики + фишки
    cocos2d::Sprite* cube1;
    cocos2d::Sprite* cube2;
    cocos2d::Sprite* chip1;
    cocos2d::Sprite* chip2;
    
    cocos2d::Label* Attention;
    
    cocos2d::Sequence* step_sequence;
    
    //рандомизатор              --библиотека Boost
    boost::random::mt11213b rng;
    unsigned int seed = 0;
    int random_num1;
    int random_num2;
    int normal_time = 5;
    

    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);      //закрытие
    void onStepQlick(cocos2d::Ref* pSender);            //сделать ход
    void onRotateRight(cocos2d::Ref* pSender);          //вращать поле направо
    void onRotateLeft(cocos2d::Ref* pSender);           //вращать налево
    void onTest(cocos2d::Ref* pSender);                 //кнопка тест
    
    //Никнейм пользователя
    std::string userName = "default";
    
    ////////////
    //APPWARP///
    ////////////
    void connectToAppWarp(cocos2d::Ref* pSender);
    
    void startGame();
    void pauseGame();
    
    void sendData(std::string message);
    
    void onConnectDone(int res, int reasonCode);
    void onJoinRoomDone(AppWarp::room revent);
    void onSubscribeRoomDone(AppWarp::room revent);
    void onChatReceived(AppWarp::chat chatevent);
    void onUserPaused(std::string user,std::string locId,bool isLobby);
    void onUserResumed(std::string user,std::string locId,bool isLobby);
    void onGetOnlineUsersDone(AppWarp::liveresult event);
    void onGetLiveUserInfoDone(AppWarp::liveuser event);
    void onGetLiveRoomInfoDone(AppWarp :: liveroom event);
    void onSetCustomRoomDataDone(AppWarp :: liveroom event);
    void onGetAllRoomsDone(AppWarp::liveresult event);
    
    CREATE_FUNC(MainTable);
    
};


#endif /* defined(__Technopoly__MainTableScene__) */
