//
//  NormalAttack.h
//  TinyZodiacs
//
//  Created by Nhut on 3/17/14.
//
//

#ifndef __TinyZodiacs__NormalAttack__
#define __TinyZodiacs__NormalAttack__

#include <iostream>
#include "AbstractSkill.h"

USING_NS_CC;
class NormalAttack: public AbstractSkill
{
private:
protected:
public:
    NormalAttack();
    NormalAttack(GameObject* holder);
    ~NormalAttack();
    
    virtual void excute();
    virtual void stop();
    virtual void BeginContact(b2Contact *contact);
    virtual void EndContact(b2Contact *contact);
};
#endif /* defined(__TinyZodiacs__NormalAttack__) */
