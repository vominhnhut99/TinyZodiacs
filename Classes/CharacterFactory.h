//
//  CharacterFactory.h
//  TinyZodiacs
//
//  Created by Nhut on 3/24/14.
//
//

#ifndef __TinyZodiacs__CharacterFactory__
#define __TinyZodiacs__CharacterFactory__

#include <iostream>
#include "cocos2d.h"
#include "Box2d/Box2D.h"
#include "CharacterDTO.h"
#include "Hero.h"
#include "GB2ShapeCache-x.h"
#include "AnimationFactory.h"
#include "SkillFactory.h"

USING_NS_CC;

#define TAG_BODY "body"
#define TAG_ANIMATION "animation"
#define TAG_HP "hp"
#define TAG_ATTACK "atk"
#define TAG_DEFENSE "def"
#define TAG_SPEED "speed"
#define TAG_ATTACK_SPEED "atk_speed"
#define TAG_MAX_JUMP "max_jump"
#define TAG_JUMP_HEIGHT "jump_height"
#define TAG_SKILL_0 "skill_0"
#define TAG_SKILL_1 "skill_1"
#define TAG_SKILL_2 "skill_2"


#define RUN "-run"
#define ATTACK "-attack"
#define JUMP "-jump"
#define IDLE "-idle"
#define FALL "-fall"
#define FLY "-fly"
#define SKILL "-skill"

#define CHARACTER_MONKEY_ID "monkey"

#define CHARACTER_MONKEY_XML_FILE "character_monkey.xml"
#define CHARACTER_CAT_XML_FILE "character_cat.xml"


class CharacterFactory
{
private:
protected:
    
    static string readBodyData(tinyxml2::XMLElement* root);
    static int readHealthData(tinyxml2::XMLElement* root);
    static int readAttackData(tinyxml2::XMLElement* root);
    static int readDefenseData(tinyxml2::XMLElement* root);
    static int readSpeedData(tinyxml2::XMLElement* root);
    static float readAttackSpeedData(tinyxml2::XMLElement* root);
    static int readMaxJumpData(tinyxml2::XMLElement* root);
    static int readJumpHeightData(tinyxml2::XMLElement* root);
    static string readAnimationData(tinyxml2::XMLElement* root);
    static string readSkill(tinyxml2::XMLElement* root);

    static void loadBody(CharacterDTO heroDTOData, Character* character, b2World* world);
    
    static Hero* createHero(CharacterDTO heroDTOData, b2World* world, bool isLocal);
    

public:
    static CharacterDTO loadXMLFile(const char* xmlFileName);
     static CharacterDTO* loadXMLFile1(const char* xmlFileName);
    
    static Hero* createMonkeyHero(b2World* world, bool isLocal);
    static Hero* createHero(string ID,b2World* world, bool isLocal);

};
#endif /* defined(__TinyZodiacs__CharacterFactory__) */
