#pragma once

#include "SoundEffectsCommon.hpp"

class SoundEffectsImpl {
public:
    SoundEffectsImpl() = default;
    ~SoundEffectsImpl() = default;

    bool Play(SoundEffect _sound);

private:
    SoundData GetWavData(SoundEffect _sound);
};