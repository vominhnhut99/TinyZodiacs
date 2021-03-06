//
//  GameGroup.h
//  TinyZodiacs
//
//  Created by Nguyễn Hòa Phát on 4/28/14.
//
//

#ifndef __TinyZodiacs__GameGroup__
#define __TinyZodiacs__GameGroup__

#include <iostream>
#include "cocos2d.h"
#include "MonsterFactory.h"
#include "Map.h"
#include "TowerDTO.h"
#include "Tower.h"
#include "DataCollector.h"
#include "Observer.h"
#include "Controller.h"

USING_NS_CC;

class GameGroup: public CCObject, public Observer, public Controller
{
private:
protected:
public:
    CC_SYNTHESIZE(Group, group, Group);
    CC_SYNTHESIZE(MonsterFactory*, monsterFactory, MonsterFactory);
//    CC_SYNTHESIZE(Hero*, character, Character);
    CC_SYNTHESIZE(CCArray*, listTower, ListTower);
    
    GameGroup();
    virtual ~GameGroup();
    
    virtual bool init();
    virtual void update(float dt);
    
    void joinGame(Group group, b2World* world, Map* map);
    void setFollowCharacter(Character* character);
    Character* getCharacterOfPlayer();
    Character* getFollowingCharacter();
    void createTowers(CCArray* listTowerStructDTO, b2World* world);
    void attachSpriteToMap(Map* map);
    
    void test();
    
    virtual void notifyToDestroy(GameObject* object);
    
    virtual bool receiveCommand(CommandID commandID, void* data);
    virtual bool removeSubController(Controller* controller);
    
    CREATE_FUNC(GameGroup);
};

#endif /* defined(__TinyZodiacs__GameGroup__) */
