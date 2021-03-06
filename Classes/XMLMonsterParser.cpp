//
//  XMLMonsterParser.cpp
//  TinyZodiacs
//
//  Created by Nguyễn Hòa Phát on 5/5/14.
//
//

#include "XMLMonsterParser.h"

#define TAG_SENSOR_BODY "sensor_body"
#define TAG_MONSTER_ITEM_LIST "item_list"
#define TAG_MONSTER_ITEM "item"
#define ATTRIBUTE_MONSTER_ITEM_ID "id"
#define ATTRIBUTE_MONSTER_ITEM_CHANCE "chance"

MonsterDTO* XMLMonsterParser::getMonsterDTOFromXMLElement(XMLElement* monsterXMLElement)
{
    MonsterDTO* monsterDTO = MonsterDTO::create();
    XMLCharacterParser::getCharacterDTOFromXMLElement(monsterDTO, monsterXMLElement);
    
    monsterDTO->sensorBody = XMLHelper::readString(monsterXMLElement->FirstChildElement(TAG_SENSOR_BODY), "");
    
    XMLElement* itemList = monsterXMLElement->FirstChildElement(TAG_MONSTER_ITEM_LIST);
    
    for (XMLElement* element = itemList->FirstChildElement(TAG_MONSTER_ITEM); element;
         element = element->NextSiblingElement())
    {
        ItemStruct itemStruct;
        itemStruct.itemID = element->Attribute(ATTRIBUTE_MONSTER_ITEM_ID);
        itemStruct.chance = atof(element->Attribute(ATTRIBUTE_MONSTER_ITEM_CHANCE));
        monsterDTO->listItem.push_back(itemStruct);
    }
    
    return monsterDTO;
}