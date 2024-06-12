/**
 * Play a sound effect asynchronously using wxWidgets library.
 *
 * @param _sound The sound effect to be played.
 * @return True if the sound was played successfully, false otherwise.
 */

#include "SoundEffects.hpp"

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/sound.h>
#include <wx/wx.h>
#endif

#ifdef __APPLE__
#include <wx/filename.h>
#include "Common/CommonApple.hpp"
#else
#include "Resources/windowsNavigationStart.hpp"
#endif

bool SoundEffects::Play(SoundEffect _sound)
{
    #ifdef __APPLE__
    (void)_sound;

    wxString resourcePath = getResourcesDirectoryPath();

    if (resourcePath.empty()) {
        // Error handling
        wxMessageBox("Failed to get Resources directory path!");
        return false;
    }

    // Construct the full path to the WAV file
    wxString wavFileName = wxT("wns.wav");
    wxString wavFilePath = resourcePath;
    wavFilePath.Append(wxFileName::GetPathSeparator());
    wavFilePath.Append(wavFileName);
    // Load the WAV file
        wxSound sound(wavFilePath);
    #else


    SoundEffects::SoundData waveData = GetWavData(_sound);

    if (waveData.soundData == nullptr)
        return false;
    wxSound sound;

    sound.Create(waveData.soundDataSize, waveData.soundData);
    #endif

    // Add error handling for sound creation
    if (!sound.IsOk()) {
        wxLogError("Failed to create sound.");
        return false;
    }

    // Check if the sound is loaded correctly and play it asynchronously if loaded
    sound.Play(wxSOUND_ASYNC);
    return true;
}
#ifndef __APPLE__

SoundEffects::SoundData SoundEffects::GetWavData(const SoundEffect _sound)
{
    switch (_sound) {
    case NavigationStart:
        return { (void*)arr_wns_wav, sizeof(arr_wns_wav) };
    default:
        wxLogError("Unexpected SoundEffect value.");
        return { nullptr, 0 };
    }
}
#endif