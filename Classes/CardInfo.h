//
//  CardInfo.h
//  Technopoly
//
//  Created by Олег Ермаков on 21.05.15.
//
//

#include "cocos2d.h"

enum Group {Tests, CLang, Web, Alg, Courses, Java, FrontEnd, DataBase, OS, Training};

class CardInfo : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    //параметры
    static std::string CardName;
    static int CardIndex;
    static Group cardGroup;
    
    virtual bool init();
    
    void onBack(cocos2d::Ref* pSender);
    void onNext(cocos2d::Ref* pSender);
    
    CREATE_FUNC(CardInfo);
};

#endif