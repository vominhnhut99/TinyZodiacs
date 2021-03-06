//
//  XMLItemParser.cpp
//  TinyZodiacs
//
//  Created by Nguyễn Hòa Phát on 5/8/14.
//
//

#include "XMLItemParser.h"
#include "ItemSoundData.h"
#include "SoundManager.h"

#define TAG_ITEM "item"
#define ATTRIBUTE_ITEM_ID "id"
#define ATTRIBUTE_ITEM_TYPE "type"
#define ATTRIBUTE_ITEM_IMAGE_NAME "image_name"
#define ATTRIBUTE_ITEM_BODY_NAME "body_name"
#define ATTRIBUTE_ITEM_LIFE_TIME "life_time"
#define TAG_SUB_ITEM_LIST "item_list"
#define TAG_ITEM_AFFECT_LIST "affect_list"
#define TAG_ITEM_AFFECT "affect"
#define ATTRIBUTE_ITEM_CHANCE "chance"
#define ATTRIBUTE_ITEM_ANIMATION "animation"
#define ATTRIBUTE_ITEM_AFFECT_ID "id"
#define TAG_ITEM_GOLD_VALUE "gold_value"
#define TAG_ITEM_TITLE_NOTIFICATION "title_notification"
#define TAG_SFX "sfx"

CCArray* XMLItemParser::getItemDTOListFromXMLElement(XMLElement* xmlElement)
{
    CCArray* listItemDTO = CCArray::create();
    for (XMLElement* element = xmlElement->FirstChildElement(TAG_ITEM); element;
         element = element->NextSiblingElement())
    {
        listItemDTO->addObject(getItemDTOFromXMLElement(element));
    }
    return listItemDTO;
}

ItemDTO* XMLItemParser::getItemDTOFromXMLElement(XMLElement* xmlElement)
{
    ItemDTO* item = ItemDTO::create();
    
    string id = XMLHelper::readAttributeString(xmlElement, ATTRIBUTE_ITEM_ID, "");
    string type = XMLHelper::readAttributeString(xmlElement, ATTRIBUTE_ITEM_TYPE, "");
    string imageName = XMLHelper::readAttributeString(xmlElement, ATTRIBUTE_ITEM_IMAGE_NAME, "");
    string bodyName = XMLHelper::readAttributeString(xmlElement, ATTRIBUTE_ITEM_BODY_NAME, "");
    string animation = XMLHelper::readAttributeString(xmlElement, ATTRIBUTE_ITEM_ANIMATION,"");
    float lifeTime = XMLHelper::readAttributeFloat(xmlElement, ATTRIBUTE_ITEM_LIFE_TIME, 0);
    int goldValue = XMLHelper::readInt(xmlElement->FirstChildElement(TAG_ITEM_GOLD_VALUE), 0);
    string titleNotification = XMLHelper::readString(xmlElement->FirstChildElement(TAG_ITEM_TITLE_NOTIFICATION), "");
    ItemSoundData soundData = SoundManager::loadItemSoundData(XMLHelper::readString(xmlElement->FirstChildElement(TAG_SFX),"").c_str());
    
    item->id = id;
    item->type = type;
    item->imageName = imageName;
    item->bodyName = bodyName;
    item->animation = animation;
    item->lifeTime = lifeTime;
    item->listSubItemStruct = getSubItemStructListFromXMLElement(xmlElement);
    item->listAffectID = getAffectListFromXMLElement(xmlElement);
    item->goldValue = goldValue;
    item->titleNotification = titleNotification;
    item->soundData = soundData;
    
    return item;
}

ItemStruct XMLItemParser::getSubItemStructFromXMLElement(XMLElement* xmlElement)
{
    ItemStruct itemStruct;
    itemStruct.itemID = xmlElement->Attribute(ATTRIBUTE_ITEM_ID);
    itemStruct.chance = atof(xmlElement->Attribute(ATTRIBUTE_ITEM_CHANCE));
    return itemStruct;
}

vector<ItemStruct> XMLItemParser::getSubItemStructListFromXMLElement(XMLElement* xmlElement)
{
    vector<ItemStruct> listItemStruct;
    XMLElement* listSubItemStructXMLElement = xmlElement->FirstChildElement(TAG_SUB_ITEM_LIST);
    if(listSubItemStructXMLElement != NULL)
    {
        for (XMLElement* element = listSubItemStructXMLElement->FirstChildElement(TAG_ITEM); element;
             element = element->NextSiblingElement())
        {
            listItemStruct.push_back(getSubItemStructFromXMLElement(element));
        }
    }
    return listItemStruct;
}

vector<string> XMLItemParser::getAffectListFromXMLElement(XMLElement* xmlElement)
{
    vector<string> listAffectID;
    
    XMLElement* listAffectListXMLElement = xmlElement->FirstChildElement(TAG_ITEM_AFFECT_LIST);
    if(listAffectListXMLElement != NULL)
    {
        for (XMLElement* element = listAffectListXMLElement->FirstChildElement(TAG_ITEM_AFFECT); element;
             element = element->NextSiblingElement())
        {
            listAffectID.push_back(XMLHelper::readAttributeString(element, ATTRIBUTE_ITEM_AFFECT_ID, ""));
        }
    }
    return listAffectID;
}
