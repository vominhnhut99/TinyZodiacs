//
//  HealthPointEffect.cpp
//  TinyZodiacs
//
//  Created by Nguyễn Hòa Phát on 5/3/14.
//
//

#include "HealthPointEffect.h"
#include "AnimationLoader.h"

HealthPointEffect::HealthPointEffect()
{
    healthPoint = 0;
    label = CCLabelTTF::create("", "Arial",55);
    label->setColor(ccc3(255,0,0));
    this->addChild(label);
    
    //  this->addChild(this->sprite);
}

HealthPointEffect::~HealthPointEffect()
{
    //this->sprite->removeFromParent();
}

bool HealthPointEffect::init()
{
    return true;
}

void HealthPointEffect::run()
{
    CCMoveBy* moveBy  =  CCMoveBy::create(0.5f, ccp(0,200));
    CCJumpBy* jumpBy = CCJumpBy::create(0.5f, ccp(CCRANDOM_MINUS1_1()*30,10), 100, 1);

    CCFadeOut* fadeOut = CCFadeOut::create(0.6f);
    CCScaleBy* scaleBy = CCScaleBy::create(0.5f, 0.75f);
    CCCallFunc* func = CCCallFuncND::create(this, callfuncND_selector(HealthPointEffect::stop),NULL);
    
    
    
    CCArray* arr = CCArray::create();
    arr->addObject(jumpBy);
    arr->addObject(fadeOut);
    arr->addObject(scaleBy);
    
    CCArray* seq = CCArray::create();
    seq->addObject(CCSpawn::create(arr));
    seq->addObject(func);
    //
    //    this->sprite->runAction(animate);
    this->label->runAction(CCSequence::create(seq));
    
    
}

void HealthPointEffect::stop()
{
   // this->label->stopAllActioons();
    this->removeFromParent();
}

void HealthPointEffect::setHealthPoint(float hp)
{
    this->healthPoint = hp;
    this->label->setString(CCString::createWithFormat("%0.0f", this->healthPoint)->getCString());
}

void HealthPointEffect::update(float dt)
{
    if(numberOfRunningActions() == 0)
    {
        // stop();
    }
}