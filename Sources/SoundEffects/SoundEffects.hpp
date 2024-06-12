#pragma once

#include <cstddef>
class SoundEffects {
public:
    SoundEffects() = default;
    ~SoundEffects() = default;

    enum SoundEffect {
        NavigationStart
    };

    typedef struct {
        void* soundData;
        size_t soundDataSize;
    } SoundData;

    bool Play(SoundEffect _sound);

private:
    SoundData GetWavData(SoundEffect _sound);
};