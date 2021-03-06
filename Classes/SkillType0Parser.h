//
//  SkillType0Parser.h
//  TinyZodiacs
//
//  Created by Nhut on 3/28/14.
//
//

#ifndef __TinyZodiacs__SkillType0Parser__
#define __TinyZodiacs__SkillType0Parser__

#include <iostream>
#include "cocos2d.h"
#include "NormalMeleeSkillData.h"
#include "Box2D/Box2D.h"
#include "PhysicConstants.h"
#include "GB2ShapeCache-x.h"
#include "Constants.h"
#include "XMLHelper.h"
#include "Affect.h"
#include "SoundManager.h"


#define TAG_JOINT "joints"
#define TAG_HOLDER "holder"
#define TAG_THIS "this"

#define ATTRIBUTE_X "x"
#define ATTRIBUTE_Y "y"
#define ATTRIBUTE_OFFSET_X "offsetX"
#define ATTRIBUTE_OFFSET_Y "offsetY"

#define TAG_JOINTS "joints"
#define TAG_HOLDER "holder"
#define TAG_THIS "this"

#define TAG_BODY "body"
#define TAG_COOL_DOWN "cool_down"
#define TAG_DELAY "delay"
#define TAG_LIFE_TIME "life_time"
#define TAG_ANIMATION "animation"
#define TAG_ANIMATION_LAYER "animation_layer"
#define TAG_TARGET "target"
#define TAG_LIST_EFFECT "list_effect"
#define TAG_LIST_EFFECT_ENEMY "enemy"
#define TAG_LIST_EFFECT_ALLIES "allies"
#define TAG_LIST_EFFECT_SELF "self"
#define TAG_EFFECT "effect"
#define TAG_TIME_TICK "time_tick"
#define TAG_APPLY_TYPE "apply_type"
#define TAG_SFX "sfx"


using namespace tinyxml2;

USING_NS_CC;
class SkillType0Parser
{
private:
protected:
//    static int readDamage(const XMLElement* root);
    static float readCoolDown(const XMLElement* root);
    static JointDef readJoinDef(const XMLElement* root);
    static void readJointDef(const NormalMeleeSkillData* data);
    static b2Body* readBody(const XMLElement* root, b2World* world);
    static float readDelay(const XMLElement* root);
    static float readLifeTime(const XMLElement* root);
//    static float readCriticalChance(const XMLElement* root);
    static AnimationObject* readAnimation(const XMLElement* root);
    static SkillAnimationData readAnimationData(const XMLElement* root);
    static int readAnimationLayerIndex(const XMLElement* root);
    static SkillTarget readTarget(const XMLElement* root);
    static vector<EffectData> readEffectList(const XMLElement* root);
    static float readTimeTick(const XMLElement* root);
    static ApplyType readApplyType(const XMLElement* root);
    static SkillSoundData readSkillSoundData(const XMLElement* root);
public:
    static NormalMeleeSkillData parse(const XMLElement* root, b2World* world);
};
#endif /* defined(__TinyZodiacs__SkillType0Parser__) */
