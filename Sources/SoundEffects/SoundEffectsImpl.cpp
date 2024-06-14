/**
 * Play a sound effect asynchronously using wxWidgets library.
 *
 * @param _sound The sound effect to be played.
 * @return True if the sound was played successfully, false otherwise.
 */

#include "SoundEffectsImpl.hpp"
#include "Resources/windowsNavigationStart.hpp"
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/sound.h>
#include <wx/wx.h>
#endif

bool SoundEffectsImpl::Play(SoundEffect _sound)
{
    SoundData waveData = GetWavData(_sound);

    if (waveData.soundData == nullptr){
        return false;
    }

    wxSound sound;

    sound.Create(waveData.soundDataSize, waveData.soundData);

    // Add error handling for sound creation
    if (!sound.IsOk()) {
        wxLogError("Failed to create sound.");
        return false;
    }

    // Check if the sound is loaded correctly and play it asynchronously if loaded
    sound.Play(wxSOUND_ASYNC);
    return true;
}

SoundData SoundEffectsImpl::GetWavData(const SoundEffect _sound)
{
    switch (_sound) {
    case NavigationStart:
        return { (void*)arr_wns_wav, sizeof(arr_wns_wav) };
    default:
        wxLogError("Unexpected SoundEffect value.");
        return { nullptr, 0 };
    }
}
