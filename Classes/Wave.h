//
//  Wave.h
//  TinyZodiacs
//
//  Created by Nguyễn Hòa Phát on 5/21/14.
//
//

#ifndef __TinyZodiacs__Wave__
#define __TinyZodiacs__Wave__

class Wave;

#include <iostream>
#include "cocos2d.h"
#include "MonsterFactory.h"
#include "Constants.h"
#include "MonsterFactory.h"
#include "ItemCreator.h"

USING_NS_CC;
using namespace std;

class Wave: public CCObject
{
private:
protected:
  
    CC_SYNTHESIZE(CCArray*, listMonsterFactory, ListMonsterFactory);
    CC_SYNTHESIZE(CCArray*, listItemCreator, ListItemCreator);
    CC_SYNTHESIZE(string, musicID, MusicID);
    CC_SYNTHESIZE(string , name, Name);
    int monsterQuantity;

public:
    Wave();
    ~Wave();
    
    void setHolder(GameHolder holder);
    virtual bool init();
    virtual void update(float dt);
    
    void addMonsterFactory(MonsterFactory* monsterFactory);
    void addItemCreator(ItemCreator* itemCreator);
    bool isMonsterFactoryCompletedCreateMonsterAndAllMonsterHaveBeenKilled();
    
    
    void startCreateMonster();
    void startCreateItem();
    void stopCreateMonster();
    void stopCreateItem();
    
    void start();
    void stop();
    
    int getMonsterCount();
    int getMonsterCountMax();
    
    int getMonsterCountKilled();
    
    CREATE_FUNC(Wave);
};

#endif /* defined(__TinyZodiacs__Wave__) */
