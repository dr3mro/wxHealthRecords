/**
 * Play a sound effect asynchronously using wxWidgets library.
 *
 * @param _sound The sound effect to be played.
 * @return True if the sound was played successfully, false otherwise.
 */

#include "SoundEffectsImplApple.hpp"

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/filename.h>
#include <wx/sound.h>
#include <wx/wx.h>

#endif

#ifdef __APPLE__
#include "Common/CommonApple.hpp"
#endif

bool SoundEffectsImplApple::Play(SoundEffect _sound)
{
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

    // Add error handling for sound creation
    if (!sound.IsOk()) {
        wxLogError("Failed to create sound.");
        return false;
    }

    // Check if the sound is loaded correctly and play it asynchronously if loaded
    sound.Play(wxSOUND_ASYNC);
    return true;
}
