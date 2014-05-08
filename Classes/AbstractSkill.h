//
//  AbstractSkill.h
//  TinyZodiacs
//
//  Created by Nhut on 3/19/14.
//
//

#ifndef __TinyZodiacs__AbstractSkill__
#define __TinyZodiacs__AbstractSkill__

#include <iostream>
#include "Box2D/Box2D.h"
#include "cocos2d.h"
#include "PhysicConstants.h"
#include "GameObject.h"
#include "SkillData.h"
#include "GamePlayButton.h"

#define FUCTION_EXCUTE 0
#define FUCTION_STOP 1
#define FUCTION_SET_EXCUTABLE 2

USING_NS_CC;
class AbstractSkill: public CCObject
{
private:
protected:
    CC_SYNTHESIZE_READONLY(bool, isExcutable, IsExcutable);
    
    virtual void checkCollisionDataInBeginContact(PhysicData* data, b2Contact *contact, bool isSideA)=0;
    virtual void checkCollisionDataInEndContact(PhysicData* data, b2Contact *contact, bool isSideA)=0;
    
    virtual void setExcuteAble();
    
    CCAction *excuteAction, *stopAction, *coolDownAction;
public:
    ~AbstractSkill();
    
    virtual void excute();
    virtual void stop() =0;
    virtual void BeginContact(b2Contact *contact);
    virtual void EndContact(b2Contact *contact);
    virtual void update(float dt)=0;
    virtual void excuteImmediately();
    virtual void stopImmediately();
    
    virtual void setPhysicGroup(uint16 group)=0;
    virtual void stopAllAction();
    
    CC_SYNTHESIZE(GameObject* , holder, Holder);
    CC_SYNTHESIZE(GameplayButton* , holderButton, holderButton);
};
#endif /* defined(__TinyZodiacs__AbstractSkill__) */
