//
//  AbstractSkill.h
//  TinyZodiacs
//
//  Created by Nhut on 3/19/14.
//
//

#ifndef __TinyZodiacs__AbstractSkill__
#define __TinyZodiacs__AbstractSkill__

class AbstractSkill;

#include <iostream>
#include "Box2D/Box2D.h"
#include "cocos2d.h"
#include "PhysicConstants.h"
#include "GameObject.h"
#include "SkillData.h"
#include "HoldableUIButton.h"
#include "ControllerManager.h"
#include "CharacterData.h"

#define FUCTION_EXCUTE 0
#define FUCTION_STOP 1
#define FUCTION_SET_EXCUTABLE 2

USING_NS_CC;

class AbstractSkill: public CCObject
{
private:
protected:
    CC_SYNTHESIZE(bool, isDisable, IsDisable);
    CC_SYNTHESIZE_READONLY(bool, isExcutable, IsExcutable);
    
    virtual void checkCollisionDataInBeginContact(PhysicData* holderData, PhysicData* collisionData, b2Contact *contact) = 0;
    virtual void checkCollisionDataInEndContact(PhysicData* holderData, PhysicData* collisionData, b2Contact *contact) = 0;
    
    virtual void setExcuteAble() = 0;
    
    CCAction *excuteAction, *stopAction, *coolDownAction;
    
    virtual void calculateSkillData(SkillData* data, CharacterData characterData);
    
public:
    AbstractSkill(GameObject* holder, SkillData data);

    ~AbstractSkill();
    
    virtual void excute() = 0;
    virtual void stop() = 0;
    virtual void update(float dt) = 0;
    virtual void excuteImmediately() = 0;
    virtual void stopImmediately() = 0;
    virtual void onCreate() = 0;
    virtual void destroy() = 0;
    
    virtual void setPhysicGroup(uint16 group) = 0;
    virtual void stopAllAction();
    
    CC_SYNTHESIZE(GameObject* , holder, Holder);
//    CC_SYNTHESIZE(HoldableUIButton*, holderButton, holderButton);
    CC_SYNTHESIZE(ButtonID, skillButtonID, SkillButtonID);
    CC_SYNTHESIZE(TextureSelector, skillTextureSelector, SkillTextureSelector);
};
#endif /* defined(__TinyZodiacs__AbstractSkill__) */
