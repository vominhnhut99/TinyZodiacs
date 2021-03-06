//
//  CharacterAttackState.cpp
//  Headball
//
//  Created by Nhut on 3/13/14.
//
//

#include "CharacterAttackState.h"
#include "CharacterIdleState.h"
#include "CharacterJumpState.h"
#include "Util.h"


CharacterAttackState::CharacterAttackState(Character* character, AbstractSkill* skill, AnimationObject* skillAnimation): CharacterState(character)
{
    this->isfinishedAnimation = false;
    this->skillAnimation = skillAnimation;
    this->skill = skill;
}

bool CharacterAttackState::onEnterState()
{
    //  CCLOG("enter attack state");
   
    CCArray* arr = CCArray::create();
    
    CCCallFunc* callBack = CCCallFunc::create(this, callfunc_selector(CharacterAttackState::onFinishAttackAnimation));
    
    if(this->skillAnimation != NULL)
    {
        CCAnimation* animation = Util::getAnimationFromAnimationObject(this->skillAnimation);
        if(animation != NULL)
        {
            arr->addObject(CCAnimate::create(animation));
        }
    }
    
    arr->addObject(callBack);
    
    this->action = CCSequence::create(arr);
    this->action->retain();
    this->character->getSprite()->runAction( this->action);
    
    //Excute attack
    this->skill->excute();
    return true;
}

bool CharacterAttackState::onExitState()
{
      this->skill->stop();
    stopAction();
    return true;
}

void CharacterAttackState::update(float dt)
{
    
}

bool CharacterAttackState::attack()
{
    return false;
}

bool CharacterAttackState::move()
{
    return true;
}

bool CharacterAttackState::jump()
{
    return true;
}

bool CharacterAttackState::useSkill()
{
    return false;
}

void CharacterAttackState::onFinishAttackAnimation()
{
    this->isfinishedAnimation = true;
    this->character->changeState(new CharacterIdleState(this->character));
}