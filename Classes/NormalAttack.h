//
//  NormalAttack.h
//  TinyZodiacs
//
//  Created by Nhut on 3/17/14.
//
//

#ifndef __TinyZodiacs__NormalAttack__
#define __TinyZodiacs__NormalAttack__

#include <iostream>
#include "AbstractSkill.h"
#include "NormalMeleeSkillData.h"
#include "Observer.h"

USING_NS_CC;
class NormalAttack: public AbstractSkill, public Observer
{
private:
    int holder_join_type;
    int this_join_type;
    
    b2Joint* skillJoint;
    CCAction* timeTickAction;
    CCArray* listTarget;
protected:
    //CCArray* listTarget;
    
    virtual void checkCollisionDataInBeginContact(PhysicData* data, b2Contact *contact, bool isSideA);
    virtual void checkCollisionDataInEndContact(PhysicData* data, b2Contact *contact, bool isSideA);
    
    virtual void destroyJoint();
    virtual void createJoint();
    
    virtual void initJointType();
    
    virtual void setExcuteAble();
    
    virtual void applyEffectOnTimeTick();
public:
    NormalAttack(GameObject* holder, NormalMeleeSkillData data);
    ~NormalAttack();
    
    CC_SYNTHESIZE(NormalMeleeSkillData, data, Data);
    CC_SYNTHESIZE(CCSprite*, skillSprite, SkillSprite);
    
    virtual void excute();
    virtual void stop();
    virtual void update(float dt);
    virtual void BeginContact(b2Contact *contact);
    virtual void EndContact(b2Contact *contact);
    
    virtual void excuteImmediately();
    virtual void stopImmediately();

    virtual void setPhysicGroup(uint16 group);
    virtual void stopAllAction();
    
    
    virtual void notifyToDestroy(GameObject* object);
};
#endif /* defined(__TinyZodiacs__NormalAttack__) */
