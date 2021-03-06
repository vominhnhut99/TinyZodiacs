//
//  PhysicBodyManager.h
//  TinyZodiacs
//
//  Created by Nhut on 3/21/14.
//
//

#ifndef __TinyZodiacs__PhysicBodyManager__
#define __TinyZodiacs__PhysicBodyManager__

class GameObjectManager;

#include <iostream>
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GameObject.h"
#include "Monster.h"

USING_NS_CC;
class GameObjectManager: public CCNode
{
private:
    CC_SYNTHESIZE(CCArray*, listObjectRemoved, ListObjectRemoved);
    CC_SYNTHESIZE(CCArray*, listGameObject, ListGameObject);
protected:
    GameObjectManager();
    ~GameObjectManager();
public:
    static GameObjectManager* getInstance();
    
    virtual bool init();
    virtual void update(float dt);
    
    void addObjectRemoved(GameObject* object);
    void addGameObject(GameObject* object);
    void removeGameObject(GameObject* object);
    void removeAllGameObject();
    
    void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
    void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
    void BeginContact(b2Contact *contact);
    void EndContact(b2Contact *contact);
    
    void checkCollisionDataInPreSolve(PhysicData* holderData , PhysicData* collisionData, b2Contact *contact, const b2Manifold* oldManifold);
    void checkCollisionDataInPostSolve(PhysicData* holderData , PhysicData* collisionData, b2Contact *contact, const b2ContactImpulse* impulse);
    
    void checkCollisionDataInBeginContact(PhysicData* holderData , PhysicData* collisionData, b2Contact *contact);
    void checkCollisionDataInEndContact(PhysicData* holderData , PhysicData* collisionData, b2Contact *contact);
    
    

    static void release();
   
    CREATE_FUNC(GameObjectManager);
};
#endif /* defined(__TinyZodiacs__PhysicBodyManager__) */
