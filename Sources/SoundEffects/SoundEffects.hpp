#pragma once

#include "SoundEffectsCommon.hpp"

class SoundEffects {
public:
    SoundEffects() = default;
    ~SoundEffects() = default;

    bool Play(SoundEffect _sound);
};