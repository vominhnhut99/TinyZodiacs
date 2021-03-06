//
//  ItemFactory.cpp
//  TinyZodiacs
//
//  Created by Nguyễn Hòa Phát on 5/8/14.
//
//

#include "ItemFactory.h"

static ItemFactory* instance = NULL;

ItemFactory::ItemFactory()
{
    this->listItem = CCArray::create();
    this->listItem->retain();
    
    this->isActive = true;
}

ItemFactory::~ItemFactory()
{
    
}

ItemFactory* ItemFactory::getInstance()
{
    if(instance == NULL)
    {
        instance = new ItemFactory();
    }
    return instance;
}

Item* ItemFactory::createItem(const char* id, CCPoint position)
{
    if(this->isActive == true)
    {
        Item* item = ObjectFactory::createItem(DataCollector::getInstance()->getItemDTOByKey(id), this->holder.worldHolder);
        item->setPositionInPixel(position);
        item->attachSpriteTo(this->holder.nodeHolder);
        
        this->listItem->addObject(item);
        GameObjectManager::getInstance()->addGameObject(item);
        item->attach(this);
        
        item->getBody()->SetLinearVelocity(b2Vec2(CCRANDOM_MINUS1_1()*3,7));
        return item;
    }
    return NULL;
}

void ItemFactory::update(float dt)
{
    if(this->isActive == true)
    {
        for(int i=0; i<this->listItemStructPrepareToCreate.size(); i++)
        {
            createItem(this->listItemStructPrepareToCreate[i].itemID.c_str(),ccp(this->listItemStructPrepareToCreate[i].positionX, this->listItemStructPrepareToCreate[i].positionY));
        }
        this->listItemStructPrepareToCreate.clear();
    }
}

void ItemFactory::addItemPrepareToCreate(ItemStruct itemStruct)
{
    this->listItemStructPrepareToCreate.push_back(itemStruct);
}

void ItemFactory::destroyItem(Item* item)
{
    GameObjectManager::getInstance()->addObjectRemoved(item);
    this->listItem->removeObject(item);
}

void ItemFactory::notifyToDestroy(GameObject* gameObject)
{
    if(this->listItem->indexOfObject(gameObject) != CC_INVALID_INDEX)
    {
        this->listItem->removeObject(gameObject);
    }
}
