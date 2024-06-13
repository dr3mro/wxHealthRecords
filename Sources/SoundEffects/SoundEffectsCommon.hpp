
#pragma once

#include <cstddef>

enum SoundEffect {
    NavigationStart
};

typedef struct {
    void* soundData;
    size_t soundDataSize;
} SoundData;