#pragma once

#include <cstddef>
class SoundEffects {
public:
    SoundEffects() = default;
    ~SoundEffects() = default;

    enum SoundEffect {
        NavigationStart
    };

    bool Play(SoundEffect _sound);


#ifndef __APPLE__
    typedef struct {
        void* soundData;
        size_t soundDataSize;
    } SoundData;



private:
    SoundData GetWavData(SoundEffect _sound);
#endif
};