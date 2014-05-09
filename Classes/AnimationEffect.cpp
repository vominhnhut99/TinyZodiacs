//
//  AnimationEffect.cpp
//  TinyZodiacs
//
//  Created by Nguyễn Hòa Phát on 5/8/14.
//
//

#include "AnimationEffect.h"
#include "AnimationLoader.h"

AnimationEffect::AnimationEffect()
{
    this->sprite = CCSprite::create();
    this->addChild(sprite);
    this->animationObject = NULL;
}

AnimationEffect::~AnimationEffect()
{
    
}

bool AnimationEffect::init()
{
    return true;
}

void AnimationEffect::run()
{
    CCCallFunc* stopFunction = CCCallFunc::create(this, callfunc_selector(AnimationEffect::stop));
    CCAnimate* animateAction = CCAnimate::create(this->animationObject->getAnimation());
    
    CCArray* arrSeq = CCArray::create();
    arrSeq->addObject(animateAction);
    arrSeq->addObject(stopFunction);
    
    this->sprite->runAction(CCSequence::create(arrSeq));
}

void AnimationEffect::stop()
{
    this->sprite->stopAllActions();
    this->removeFromParent();
}

void AnimationEffect::update(float dt)
{
    
}

void AnimationEffect::setAnimation(const char *id)
{
    this->animationObject = DataCollector::getInstance()->getAnimationObjectByKey(id);
}
