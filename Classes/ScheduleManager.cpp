//
//  ScheduleManager.cpp
//  TinyZodiacs
//
//  Created by Nhut on 3/26/14.
//
//

#include "ScheduleManager.h"
static ScheduleManager* instance;

ScheduleManager::ScheduleManager()
{
    
}
ScheduleManager::~ScheduleManager()
{
    
}


ScheduleManager* ScheduleManager::getInstance()
{
    if(instance == NULL)
    {
        instance = new ScheduleManager();
    }
    return instance;
}

void ScheduleManager::release()
{
    delete  instance;
}


void ScheduleManager::stopScheduledObjectAction(CCAction* target)
{
    if(target!=NULL)
    {
        this->stopAction(target);
    }

}

CCAction* ScheduleManager::scheduleFunction(CCCallFunc* callFunction, CCCallFunc* endFunction, float duration, int repeatTime)
{
    CCArray* arr1 = CCArray::create();
    arr1->addObject(CCDelayTime::create(duration));
    arr1->addObject(callFunction);
    
    CCArray* arr2 = CCArray::create();
    arr2->addObject(CCRepeat::create(CCSequence::create(arr1), repeatTime));
    if(endFunction != NULL)
    {
        arr2->addObject(endFunction);
    }
    CCSequence* action = CCSequence::create(arr2);
    this->runAction(action);
    return action;
}

void ScheduleManager::finishScheduleFunction(CCNode* sender, void* data)
{
    CCArray* prms = static_cast<CCArray*>(data);
    prms->release();
}

CCSequence* ScheduleManager::scheduleFuction(CCCallFunc* funcion, float duration)
{
    CCDelayTime *delayAction = CCDelayTime::create(duration);
    CCArray* array = CCArray::create();
    array->addObject(delayAction);
    array->addObject(funcion);
    
    CCSequence* sequence = CCSequence::create(array);
    this->runAction(sequence);
    
    return sequence;
}

CCRepeat* ScheduleManager::scheduleFuctionRepeatly(CCCallFunc* funcion, float duration, int times)
{
    CCDelayTime *delayAction = CCDelayTime::create(duration);
    CCArray* array = CCArray::create();
    array->addObject(delayAction);
    array->addObject(funcion);
    
    CCSequence* sequence = CCSequence::create(array);
    CCRepeat* repeat = CCRepeat::create(sequence, times);
    
    this->runAction(repeat);
    
    return repeat;
}


CCAction* ScheduleManager::scheduleFunctionForever(CCCallFunc* callFunction, CCCallFunc* endFunction, float duration)
{
    CCArray* arr1 = CCArray::create();
    arr1->addObject(CCDelayTime::create(duration));
    arr1->addObject(callFunction);
    
    CCArray* arr2 = CCArray::create();
    arr2->addObject(CCSequence::create(arr1));
    if(endFunction != NULL)
        arr2->addObject(endFunction);
    
    CCRepeatForever* repeatForever = CCRepeatForever::create(CCSequence::create(arr2));
    this->runAction(repeatForever);
    return repeatForever;
}

