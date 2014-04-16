//
//  SkillType1Parser.h
//  TinyZodiacs
//
//  Created by Nhut on 4/4/14.
//
//

#ifndef __TinyZodiacs__SkillType1Parser__
#define __TinyZodiacs__SkillType1Parser__

#include <iostream>
#include "SkillType0Parser.h"
#include "NormalShootingSkillData.h"

#define TAG_SPEED "speed"
#define TAG_GRAVITY_SCALE "gravity_scale"
#define TAG_COLLIDE_TERRAIN "collide_terrain"
#define TAG_PIERCING "piercing"



class SkillType1Parser: public SkillType0Parser
{
private:
protected:
    static string readProjectileBodyId(const XMLElement* root);
    static float readProjectileSpeed(const XMLElement* root);
    static float readProjectileGravityScale(const XMLElement* root);
    static bool readTerrainCollide(const XMLElement* root);
    static bool readPiercing(const XMLElement* root);

public:
    static NormalShootingSkillData parse(const XMLElement* root, b2World* world);
};
#endif /* defined(__TinyZodiacs__SkillType1Parser__) */
