//
//  SoundManager.h
//  TinyZodiacs
//
//  Created by NhutVM on 6/7/14.
//
//

#ifndef __TinyZodiacs__SoundManager__
#define __TinyZodiacs__SoundManager__

#include <iostream>
#include "CharacterSoundFactory.h"
#include "ProjectileSoundFactory.h"
#include "Constants.h"

class SoundManager
{
private:
protected:
    static void removeAllList();
    static bool isAdded(SoundStruct soundStruct);
public:
    static CharacterSoundData loadCharacterSoundData(const char* soundId);
    static ProjectileSoundData loadProjectileSoundData(const char* soundId);
    
    static std::string loadBackGroundMusic(const char* soundId);
    
    static void addSoundId(const char* soundID, SoundType type);
    static void removeSoundId(const char* soundID);
    static void preLoadAllAddedSound();
    static void unLoadAllAddedSound(bool shouldCleanList);
    static unsigned int playSoundEffect(const char* soundId, bool isLoop);
    static void playMusic(const char* soundId, bool isLoop);
    static void stopSoundEffect(unsigned int soundId);
    static void stopMusic(const char* soundId);
    static void playMenuMusic();
};
#endif /* defined(__TinyZodiacs__SoundManager__) */
