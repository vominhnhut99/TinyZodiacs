//
//  GameManager.cpp
//  SampleCocosProject
//
//  Created by Nguy���n H��a Ph��t on 1/8/14.
//
//

#include "GameManager.h"
#include "ItemLoader.h"

USING_NS_CC;
static GameManager* instance = NULL;

GameManager::GameManager()
{
    
}

GameManager::~GameManager()
{
}

GameManager* GameManager::getInstance()
{
    if (instance == NULL)
    {
        instance = new GameManager();
    }
    return instance;
}

bool GameManager::loadResource()
{
  
    loadSpritesheet("ui_spritesheet_3.png","ui_spritesheet_3.plist");
    loadSpritesheet("ui_spritesheet_2.png","ui_spritesheet_2.plist");
    loadSpritesheet("ui_spritesheet_1.png","ui_spritesheet_1.plist");
    loadSpritesheet("tower_spritesheet.png","tower_spritesheet.plist");
    loadSpritesheet("pig_animation.png","pig_animation.plist");
    loadSpritesheet("other_effect_spritesheet.png","other_effect_spritesheet.plist");
    loadSpritesheet("onion_spritesheet.png","onion_spritesheet.plist");
    loadSpritesheet("monkey_spritesheet.png","monkey_spritesheet.plist");
    
    loadSpritesheet("map1_spritesheet_4.png","map1_spritesheet_4.plist",kTexture2DPixelFormat_RGBA8888);
    loadSpritesheet("map1_spritesheet_3.png","map1_spritesheet_3.plist",kTexture2DPixelFormat_RGBA8888);
    loadSpritesheet("map1_spritesheet_2.png","map1_spritesheet_2.plist",kTexture2DPixelFormat_RGBA8888);
    loadSpritesheet("map1_spritesheet_1.png","map1_spritesheet_1.plist",kTexture2DPixelFormat_RGBA8888);
    
    loadSpritesheet("map1_background_spritesheet_3.png","map1_background_spritesheet_3.plist");
    loadSpritesheet("map1_background_spritesheet_2.png","map1_background_spritesheet_2.plist");
    loadSpritesheet("map1_background_spritesheet_1.png","map1_background_spritesheet_1.plist");
    loadSpritesheet("mainmenu_spritesheet.png","mainmenu_spritesheet.plist");
    
    loadSpritesheet("magic_mass_bomb_spritesheet_2.png","magic_mass_bomb_spritesheet_2.plist",kTexture2DPixelFormat_RGBA4444);
    loadSpritesheet("magic_mass_bomb_spritesheet_1.png","magic_mass_bomb_spritesheet_1.plist",kTexture2DPixelFormat_RGBA4444);
    loadSpritesheet("magic_lightning_arrow_spritesheet.png","magic_lightning_arrow_spritesheet.plist",kTexture2DPixelFormat_RGBA4444);
    loadSpritesheet("magic_fire_pillar_spritesheet_2.png","magic_fire_pillar_spritesheet_2.plist",kTexture2DPixelFormat_RGBA4444);
    loadSpritesheet("magic_fire_pillar_spritesheet_1.png","magic_fire_pillar_spritesheet_1.plist",kTexture2DPixelFormat_RGBA4444);
    loadSpritesheet("magic_fire_ball_spritesheet.png","magic_fire_ball_spritesheet.plist",kTexture2DPixelFormat_RGBA4444);
    loadSpritesheet("magic_energy_ball_spritesheet.png","magic_energy_ball_spritesheet.plist",kTexture2DPixelFormat_RGBA4444);
    loadSpritesheet("magic_bomb_start_spritesheet.png","magic_bomb_start_spritesheet.plist",kTexture2DPixelFormat_RGBA4444);
    loadSpritesheet("item_spritesheet.png","item_spritesheet.plist");
    loadSpritesheet("cat_spritesheet.png","cat_spritesheet.plist");
    loadSpritesheet("bull_spritesheet.png","bull_spritesheet.plist");
    loadSpritesheet("test_sheet.png","test_sheet.plist");

    CCTextureCache::sharedTextureCache()->dumpCachedTextureInfo();
    
//    loadSpritesheet("cat_spritesheet.png","cat_spritesheet.plist");
//    loadSpritesheet("onion_creep_default.png","onion_creep_default.plist");
////    loadSpritesheet("map1_spritesheet_1.png","map1_spritesheet_1.plist");
////    loadSpritesheet("map1_spritesheet_2.png","map1_spritesheet_2.plist");
////    loadSpritesheet("map1_spritesheet_3.png","map1_spritesheet_3.plist");
////    loadSpritesheet("map1_spritesheet_4.png","map1_spritesheet_4.plist");
//    loadSpritesheet("test_sheet.png","test_sheet.plist");
//    loadSpritesheet("tower_orb_default.png","tower_orb_default.plist");
//    loadSpritesheet("tower_spritesheet.png","tower_spritesheet.plist");
//    loadSpritesheet("smoke_spritesheet.png","smoke_spritesheet.plist");
//    loadSpritesheet("item_spritesheet.png","item_spritesheet.plist");
//    loadSpritesheet("healthbar_spritesheet.png","healthbar_spritesheet.plist");
//    loadSpritesheet("Slash_default.png","Slash_default.plist");
//    loadSpritesheet("bull_spritesheet.png","bull_spritesheet.plist");
//    loadSpritesheet("pig_default.png","pig_default.plist");
//    
//    loadSpritesheet("maincrystal_spritesheet.png","maincrystal_spritesheet.plist");
//    loadSpritesheet("magic_mass_bomb_start.png","magic_mass_bomb_start.plist");
//    loadSpritesheet("magic_energy_ball_middle.png","magic_energy_ball_middle.plist");
//    loadSpritesheet("magic_lightning_arrow_middle.png","magic_lightning_arrow_middle.plist");
//    loadSpritesheet("magic_bomb_middle.png","magic_bomb_middle.plist");
//
////    loadSpritesheet("map1_background_1.png","map1_background_1.plist");
////    loadSpritesheet("map1_background_2.png","map1_background_2.plist");
////    loadSpritesheet("map1_background_3.png","map1_background_3.plist");
//    
//    loadSpritesheet("map1_background_3_small.png","map1_background_3_small.plist");
//    loadSpritesheet("magic_energy_ball2_end.png","magic_energy_ball2_end.plist");
//    loadSpritesheet("magic_mass_bomb_end.png","magic_mass_bomb_end.plist");
//    loadSpritesheet("magic_lightning_arrow_end.png","magic_lightning_arrow_end.plist");
//    loadSpritesheet("magic_energy_ball1_end.png","magic_energy_ball1_end.plist");
    
    gbox2d::GB2ShapeCache *sc = gbox2d::GB2ShapeCache::sharedGB2ShapeCache();
    sc->addShapesWithFile("character_body.plist");
    sc->addShapesWithFile("skill_body.plist");
    sc->addShapesWithFile("map1_body.plist");
    sc->addShapesWithFile("monster_sensor.plist");
    sc->addShapesWithFile("item_body.plist");
    sc->addShapesWithFile("tower_sensor.plist");
    
    return false;
}


bool GameManager::loadSpritesheet(const char* imageFileName, const char* plistFilename, CCTexture2DPixelFormat texturePixelFormat)
{
    CCTexture2D::setDefaultAlphaPixelFormat(texturePixelFormat);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(plistFilename, imageFileName);
    CCTexture2D::setDefaultAlphaPixelFormat(kTexture2DPixelFormat_Default);
    return true;
}


bool GameManager::loadData()
{
    AnimationLoader::loadData();
    TowerLoader::loadData();
    MapLoader::loadData();
    HeroLoader::loadData();
    MonsterLoader::loadData();
    ItemLoader::loadData();
    
    return true;
}

void GameManager::initManager()
{
    instance->addChild(ScheduleManager::getInstance());
    instance->addChild(GameObjectManager::getInstance());
    instance->addChild(EffectManager::getInstance());
}


