#pragma once

#include "SoundEffectsCommon.hpp"

class SoundEffectsImplApple {
public:
    SoundEffectsImplApple() = default;
    ~SoundEffectsImplApple() = default;

    bool Play(SoundEffect _sound);
};