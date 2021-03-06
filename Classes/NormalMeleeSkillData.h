//
//  NormalMeleeSkillData.h
//  TinyZodiacs
//
//  Created by Nhut on 3/28/14.
//
//

#ifndef __TinyZodiacs__NormalMeleeSkillData__
#define __TinyZodiacs__NormalMeleeSkillData__

#include <iostream>
#include "SkillData.h"
#include "Box2D/Box2D.h"
#include "AnimationObject.h"

class NormalMeleeSkillData: public SkillData
{
private:
protected:
public:
    NormalMeleeSkillData();
    ~NormalMeleeSkillData();
    
    CC_SYNTHESIZE(b2Body*, skillSensor, SkillSensor);
    CC_SYNTHESIZE(int, animationLayerIndex, AnimationLayerIndex);
    
    virtual void clone();
};

#endif /* defined(__TinyZodiacs__NormalMeleeSkillData__) */
