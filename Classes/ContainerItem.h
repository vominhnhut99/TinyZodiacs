//
//  ContainerItem.h
//  TinyZodiacs
//
//  Created by Nguyễn Hòa Phát on 5/3/14.
//
//

#ifndef __TinyZodiacs__ContainerItem__
#define __TinyZodiacs__ContainerItem__
#include <iostream>
#include "cocos2d.h"
#include "Item.h"
#include "Constants.h"

USING_NS_CC;
using namespace std;
class ContainerItem: public Item
{
private:
    bool isOpened;
    CC_SYNTHESIZE(vector<ItemStruct>, listSubItem, listSubItem);
protected:
public:
    ContainerItem();
    virtual ~ContainerItem();
    
    virtual bool init();
    
    virtual void onCreate();
    virtual void destroy();
    virtual void startSchedule();
    
    virtual void prepareToAppear();
    virtual void appear();
    virtual void prepareToDisappearInTimeOut();
    virtual void prepareToDisappearInContact(GameObject* contactGameObject);
    virtual void prepareToDisappearInOpen();
    virtual void disappear();
    
    virtual void contact(GameObject* contactGameObject);
    virtual void open(GameObject* openGameObject);
    
    CREATE_FUNC(ContainerItem);
    
};


#endif /* defined(__TinyZodiacs__ContainerItem__) */
