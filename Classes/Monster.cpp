//
//  Monster.cpp
//  Headball
//
//  Created by Nhut on 3/13/14.
//
//

#include "Monster.h"
#include "SensorObject.h"
#include "Util.h"
#include "MonsterFactory.h"
#include "GameObjectManager.h"
#include "HealthPointEffect.h"
#include "EffectManager.h"

Monster::Monster()
{
    isStopMove = false;
    isAttack = false;
    this->landing = 0;
    
    this->listTarget = CCArray::create();
    this->listTarget->retain();
}

Monster::~Monster()
{
    this->sensor->SetUserData(NULL);
    this->sensor->GetWorld()->DestroyBody(this->sensor);
    
    this->listTarget->removeAllObjects();
    this->listTarget->release();
}

bool Monster::init()
{
    if (!Character::init()) {
        return false;
    }
    this->sprite = CCSprite::createWithSpriteFrameName("cat_idle_1.png");
    return true;
}

void Monster::update(float dt)
{
    this->aimTarget();
    //
    if(!isAttack)
    {
        if(!isStopMove)
        {
            this->move(this->direction);
        }
    }
    //
    Character::update(dt);
    //remove target
    CCArray* listTargetRemoved = CCArray::create();
    CCObject* object;
    CCARRAY_FOREACH(this->listTarget, object)
    {
        Character* character = (Character*)object;
        
        if(character->isDead())
        {
            listTargetRemoved->addObject(character);
        }
    }
    object = NULL;
    CCARRAY_FOREACH(listTargetRemoved, object)
    {
        this->listTarget->removeObject(object);
    }
    listTargetRemoved->removeAllObjects();
    //
}


void Monster::checkCollisionDataInBeginContact(PhysicData* data, b2Contact *contact, bool isSideA)
{
    Character::checkCollisionDataInBeginContact(data, contact, isSideA);
    
    if(data->Data == this)
    {
        PhysicData* physicData = NULL;
        if(isSideA)
        {
            physicData = (PhysicData*)contact->GetFixtureB()->GetBody()->GetUserData();
        }
        else
        {
            physicData = (PhysicData*)contact->GetFixtureA()->GetBody()->GetUserData();
        }
        
        if(physicData != NULL)
        {
            //Contact sensor
            if(data->Id == MONSTER_SENSOR && physicData->Id == CHARACTER_BODY && physicData->Data != this)
            {
                if(listTarget->indexOfObject((GameObject*)physicData->Data) == CC_INVALID_INDEX)
                {
                    this->stopMove();
                    listTarget->addObject((GameObject*)physicData->Data);
//                    this->aimTarget();
                }
                return;
            }
            //
            
            switch (physicData->Id) {
                case MAP_SENSOR:
                {
                    if(data->Id == CHARACTER_FOOT_SENSOR)
                    {
                        SensorObject* sensorObject = static_cast<SensorObject*>(physicData->Data);
                        if(sensorObject->checkValidLaneID(this->laneID))
                        {
                            // cung huong
                            if(this->direction == sensorObject->getDirection())
                            {
                                doAction(sensorObject);
                            }
                            else if(sensorObject->getIsBack())
                            {
                                doAction(sensorObject);
                            }
                        }
                        //                        this->isStopMove =true;
                    }
                }
                    break;
                    
                case MAP_BASE:
                {
                    if(data->Id == CHARACTER_FOOT_SENSOR)
                    {
                        MapObject* mapObject = static_cast<MapObject*>(physicData->Data);
                        if(!Util::bodiesArePassingThrough(this->body, mapObject->getBody()))
                        {
                            this->isStopMove = false;
                        }
                    }
                }
                    break;
                    
                default:
                    break;
            }
        }
    }
}

void Monster::checkCollisionDataInEndContact(PhysicData* data, b2Contact *contact, bool isSideA)
{
    Character::checkCollisionDataInEndContact(data, contact, isSideA);
    if(data->Data == this)
    {
        PhysicData* physicData = NULL;
        if(isSideA)
        {
            physicData = (PhysicData*)contact->GetFixtureB()->GetBody()->GetUserData();
        }
        else
        {
            physicData = (PhysicData*)contact->GetFixtureA()->GetBody()->GetUserData();
        }
        
        if(physicData != NULL)
        {
            //Contact sensor
            if(data->Id == MONSTER_SENSOR && physicData->Id == CHARACTER_BODY && physicData->Data != this)
            {
                listTarget->removeObject((GameObject*)physicData->Data);
//                this->aimTarget();
                if(listTarget->count()==0)
                {
                    flipDirection(this->defaultDirection);
                }
                return;
            }
            //
            switch (physicData->Id) {
                case MAP_SENSOR:
                {
                    //this->isStopMove = false;
                }
                    break;
                default:
                    break;
            }
        }
    }
    
}


void Monster::doAction(SensorObject* sensorObject)
{
    if(sensorObject->getMustStop())
    {
        isStopMove = true;
        this->stopMove();
    }
    if(sensorObject->getMoveSpeed() > 0)
    {
        this->move(sensorObject->getDirection(), sensorObject->getMoveSpeed());
    }
    if(sensorObject->getJumpHeight() > 0)
    {
        this->jump(sensorObject->getJumpHeight());
    }
}

void Monster::notifyByEffect(CCObject* effect)
{
    
    
    Character::notifyByEffect(effect);
    if(this->getcharacterData().getHealth() <= 0)
    {
        GameObjectManager::getInstance()->addObjectRemoved(this);
        //        MonsterFactory::removeMonster(this);
    }
}

void Monster::setPhysicGroup(uint16 group)
{
    Character::setPhysicGroup(group);
    this->setSensorGroup(group);
}

void Monster::setSensorGroup(uint16 group)
{
    for (b2Fixture* f = this->sensor->GetFixtureList(); f; f = f->GetNext())
    {
        if(f != NULL)
        {
            b2Filter filter = f->GetFilterData();
            filter.categoryBits = GROUP_MONSTER_SENSOR;
            switch (group) {
                case GROUP_A:
                case GROUP_HERO_A:
                case GROUP_TOWER_A:
                    filter.maskBits = GROUP_HERO_B|GROUP_TOWER_B|GROUP_B|GROUP_NEUTRUAL;
                    break;
                    
                case GROUP_B:
                case GROUP_HERO_B:
                case GROUP_TOWER_B:
                    filter.maskBits = GROUP_HERO_A|GROUP_TOWER_A|GROUP_A|GROUP_NEUTRUAL;
                    break;
                    
                case GROUP_NEUTRUAL:
                    filter.maskBits = GROUP_A|GROUP_B|GROUP_HERO_A|GROUP_HERO_B;
                    break;
                    
                default:
                    break;
            }
            //            filter.maskBits = 0xFFFFFF;
            f->SetFilterData(filter);
        }
    }
}

void Monster::setSensor(b2Body* sensor)
{
    this->sensor=sensor;
    
    PhysicData* data =  new PhysicData();
    data->Id = MONSTER_SENSOR;
    data->Data = this;
    this->sensor->SetUserData(data);
    
    b2RevoluteJointDef revoluteJointDef;
    revoluteJointDef.bodyA = this->getBody();
    revoluteJointDef.bodyB = this->sensor;
    
    this->getBody()->GetWorld()->CreateJoint(&revoluteJointDef);
}

uint16  Monster::getCorrectGroup(Group group)
{
    switch (group)
    {
        case A:
            return GROUP_A;
        case B:
            return GROUP_B;
        default:
            return GROUP_NEUTRUAL;
    }
}

void Monster::aimTarget()
{
    if(listTarget->count()>0)
    {
        this->isAttack = true;
        
        CCPoint targetPosition = ((GameObject*)listTarget->objectAtIndex(0))->getPositionInPixel();
        if(this->getPositionInPixel().x > targetPosition.x)
        {
            flipDirection(LEFT);
        }
        else
        {
            flipDirection(RIGHT);
        }
        this->attack();
    }
    else
    {
        this->isAttack = false;
    }
}

void Monster::setGroup(Group group)
{
    Character::setGroup(group);
    switch (group)
    {
        case A:
            defaultDirection = RIGHT;
            break;
        case B:
            defaultDirection = LEFT;
            break;
        default:
            defaultDirection = LEFT;
            break;
    }
    flipDirection(defaultDirection);
}