#pragma once

#include "SoundEffectsCommon.hpp"

#ifdef __APPLE__
#include "SoundEffectsImplApple.hpp"
#else
#include "SoundEffectsImpl.hpp"
#endif

class SoundEffects {
public:
    SoundEffects() = default;
    ~SoundEffects() = default;

    bool Play(SoundEffect _sound);
};