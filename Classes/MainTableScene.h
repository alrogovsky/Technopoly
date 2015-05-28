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
#include "boost/algorithm/string/split.hpp"
#include "boost/algorithm/string/classification.hpp"
#include "Gameplay.h"
#include "appwarp.h"
#include <vector>

#define Height_K 7.35

#define APPWARP_APP_KEY     "e9e179212bf8ab524908f4f2449a5399469a41b7a10c73d653bbc30af77141b2"
#define APPWARP_SECRET_KEY  "6c8de95986e7916ac1faf63972e953e87f50dacd4075a2eec2b24c91f0c92339"
#define ROOM_ID "1799451657"

class MainTable : public cocos2d::Layer, public AppWarp::ConnectionRequestListener,public AppWarp::RoomRequestListener,public AppWarp::NotificationListener, public AppWarp::ZoneRequestListener
{
public:
    static const int numbers_of_cards = 40;
    cocos2d::Sprite* cards [numbers_of_cards];
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    int current_position1 = 0;
    int current_position2 = 0;
    
    //
    void createTable(cocos2d::Node* Table);
    void addRight(cocos2d::Node*, float, cocos2d::Vec2, cocos2d::Size k);
    void addLeft(cocos2d::Node*, float, cocos2d::Vec2, cocos2d::Size k);
    void addTop(cocos2d::Node*, float, cocos2d::Vec2, cocos2d::Size k);
    void addBottom(cocos2d::Node*, float, cocos2d::Vec2, cocos2d::Size k);
    
    void userStep(cocos2d::Node* spr,int strokes_number, int* curr_pos);
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    cocos2d::Sprite* cube1;
    cocos2d::Sprite* cube2;
    cocos2d::Sprite* chip1;
    cocos2d::Sprite* chip2;
    
    cocos2d::MenuItemLabel* StepButton;
    
    cocos2d::Sequence* step_sequence;
    cocos2d::Node* table;
    
    boost::random::mt11213b rng;
    unsigned int seed = 0;
    
    int random_num1;
    int random_num2;
    
    std::string userName = "BROTISHKA";
    std::string chipSkin = "fishka2.png";

    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void onStepQlick(cocos2d::Ref* pSender);
    
    void onRotateRight(cocos2d::Ref* pSender);
    void onRotateLeft(cocos2d::Ref* pSender);
    
    void onTest(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    
    static bool isRejoined;
    
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
