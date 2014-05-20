//
//  MapDTO.cpp
//  TinyZodiacs
//
//  Created by Nguyễn Hòa Phát on 3/17/14.
//
//

#include "MapDTO.h"

MapDTO::MapDTO()
{
    this->listMapObjectDTO = CCArray::create();
    this->listMapObjectDTO->retain();
    this->listBackgroundDTO = CCArray::create();
    this->listBackgroundDTO->retain();
    this->listForegroundDTO = CCArray::create();
    this->listForegroundDTO->retain();
    this->listSensorObjectDTO = CCArray::create();
    this->listSensorObjectDTO->retain();
    this->listTowerStructDTO = CCArray::create();
    this->listTowerStructDTO->retain();
    this->listMonsterFactoryDTO = CCArray::create();
    this->listMonsterFactoryDTO->retain();
    this->listItemCreateDTO = CCArray::create();
    this->listItemCreateDTO->retain();
    
    this->height = 0;
    this->width = 0;
    this->id = "";
}

MapDTO::~MapDTO()
{
    CC_SAFE_RELEASE(this->listMapObjectDTO);
    CC_SAFE_RELEASE(this->listBackgroundDTO);
    CC_SAFE_RELEASE(this->listForegroundDTO);
    CC_SAFE_RELEASE(this->listSensorObjectDTO);
    CC_SAFE_RELEASE(this->listTowerStructDTO);
    CC_SAFE_RELEASE(this->listMonsterFactoryDTO);
    CC_SAFE_RELEASE(this->listMonsterFactoryDTO);
}

bool MapDTO::init()
{
    return true;
}