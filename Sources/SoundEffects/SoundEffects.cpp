/**
 * Play a sound effect asynchronously using wxWidgets library.
 *
 * @param _sound The sound effect to be played.
 * @return True if the sound was played successfully, false otherwise.
 */

#include "SoundEffects.hpp"

bool SoundEffects::Play(SoundEffect _sound)
{
    return soundEffect.Play(_sound);
}
