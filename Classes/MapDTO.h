//
//  MapDTO.h
//  TinyZodiacs
//
//  Created by Nguyễn Hòa Phát on 3/17/14.
//
//

#ifndef __TinyZodiacs__MapDTO__
#define __TinyZodiacs__MapDTO__

#include <iostream>
#include "cocos2d.h"
#include "ResourcePack.h"

USING_NS_CC;
using namespace std;

class MapDTO: public CCObject
{
public:
    MapDTO();
    virtual ~MapDTO();
    virtual bool init();
    
    string id;
    float width;
    float height;
    int time;
    
    float revivePositionX;
    float revivePositionY;
    
    ResourcePack* resourcePack;
    
    CCArray* listMapObjectDTO;
    CCArray* listBackgroundDTO;
    CCArray* listForegroundDTO;
    CCArray* listSensorObjectDTO;
    CCArray* listTowerStructDTO;
    CCArray* listMonsterFactoryDTO;
    CCArray* listItemCreatorDTO;
    CCArray* listWaveDTO;
    CCArray* listWallDTO;

    CREATE_FUNC(MapDTO);
};

#endif /* defined(__TinyZodiacs__MapDTO__) */
