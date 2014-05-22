//
//  Util.h
//  TinyZodiacs
//
//  Created by Nhut on 3/28/14.
//
//

#ifndef __TinyZodiacs__Util__
#define __TinyZodiacs__Util__

#include <iostream>
#include "Box2D/Box2D.h"
#include "PhysicConstants.h"
#include "GameObject.h"
#include "EffectData.h"
#include "Constants.h"
#include <vector>

using namespace std;
class Util
{
private:
protected:
public:
    static b2AABB getBodyBoundingBox(b2Body* body);
    static b2AABB getBodyBoundingBoxDynamic(b2Body* body);
    static b2AABB getFixtureBoundingBoxDynamic(b2Fixture* fixture);

    
    static bool bodiesAreTouching( b2Body* body1, b2Body* body2 );
    static bool bodiesArePassingThrough( b2Body* body1, b2Body* body2 );
    static bool bodiesAreTouchingWith(b2Body* body, int type);
    static bool bodiesAreTouchingFixture( b2Body* body1, b2Fixture* fixture );
    
    static b2Vec2 getb2VecAnchor(b2Body* body, JointDef jointDef);
    static void setFixtureGroup(b2Fixture* fixture, uint16 group);
    static vector<string> getStrTok(const char* string);

    static void applyEffectFromList(vector<EffectData> listEffect, GameObject* object);
    
    static ItemType convertStringToItemType(const char* itemType);
    static vector<ItemStruct> randomItemInList(vector<ItemStruct> listItemStruct, int count);
};

#endif /* defined(__TinyZodiacs__Util__) */
