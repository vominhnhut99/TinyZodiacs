//
//  GameObject.h
//  SampleCocosProject
//
//  Created by Nguyễn Hòa Phát on 2/13/14.
//
//

#ifndef __SampleCocosProject__GameObject__
#define __SampleCocosProject__GameObject__

#include <iostream>
#include <cocos2d.h>
#include <Box2D/Box2D.h>
#include "PhysicConstants.h"
#include "PhysicData.h"

enum Direction {LEFT, RIGHT};
class GameObject: public cocos2d::CCObject
{
private:
    
protected:
    Direction direction;
    virtual void checkCollisionDataInBeginContact(PhysicData* data, b2Contact *contact);
    virtual void checkCollisionDataInEndContact(PhysicData* data, b2Contact *contact);

public:
    GameObject();
    ~GameObject();

    CC_SYNTHESIZE(cocos2d::CCSprite*, sprite, Sprite);
    CC_SYNTHESIZE(b2Body*, body, Body);
    
    Direction getDirection();
    b2AABB getBodyBoundingBox();
    
    void setAnchorPointForAnimation(const cocos2d::CCPoint &anchorPoint);
    void flipDirection(Direction direction);
    
    virtual void setSkin(b2Body* body,cocos2d::CCSprite* sprite);
    virtual bool init();
    virtual void update(float dt);
    virtual void setPositionInPixel(const cocos2d::CCPoint& pos);
    virtual cocos2d::CCPoint getPositionInPixel();
    virtual void updateSpritePositionWithBodyPosition();
    virtual void BeginContact(b2Contact *contact);
    virtual void EndContact(b2Contact *contact);
    
    virtual void excuteScheduledFunction(CCObject* pSender, void *body);
};

#endif /* defined(__SampleCocosProject__GameObject__) */
