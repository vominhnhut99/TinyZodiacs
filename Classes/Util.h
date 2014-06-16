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
    static b2AABB getGameObjectBoundingBox(GameObject* obj);
    static b2AABB getGameObjectBoundingBoxDynamic(GameObject* obj);
    
    static b2AABB getBodyBoundingBox(b2Body* body);
    static b2AABB getBodyBoundingBoxDynamic(b2Body* body);
    static b2AABB getFixtureBoundingBoxDynamic(b2Fixture* fixture);
    static b2AABB getFixtureBoundingBox(b2Fixture* fixture);


    static b2Fixture* getFixtureById(b2Body* body, FixtureID fixtureId);
    
    static bool bodiesAreTouching( b2Body* body1, b2Body* body2 );
    static bool bodiesArePassingThrough( b2Body* body1, b2Body* body2 );
    static bool fixtureArePassingThroughBody(b2Fixture* fixture, b2Body* body);
    static bool bodiesAreTouchingWith(b2Body* body, int type);
    static bool bodiesAreTouchingFixture( b2Body* body1, b2Fixture* fixture );
    
    static b2Vec2 getb2VecAnchor(b2Body* body, JointDef jointDef);
    static b2Vec2 getb2VecAnchor(b2Fixture* fixture, JointDef jointDef);
    static b2Vec2 getb2VecAnchor(b2AABB aabb, JointDef jointDef);
    static void setFixtureGroup(b2Fixture* fixture, uint16 group);
    static vector<string> getStrTok(const char* string);

    static void applyEffectFromList(vector<EffectData> listEffect, GameObject* object);
    
    static ItemType convertStringToItemType(const char* itemType);

    static vector<ItemStruct> randomItemInList(vector<ItemStruct> listItemStruct, int count);

    static float randomFloatInRange(float lowerBound, float upperBound);
    
    static void loadImage(const char* textureFilename, CCTexture2DPixelFormat texturePixelFormat = kTexture2DPixelFormat_Default);
    static void loadPlist(const char* plistFilename);
};

#endif /* defined(__TinyZodiacs__Util__) */
