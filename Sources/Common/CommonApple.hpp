#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/sound.h>
#include <wx/wx.h>
#endif

#include <CoreFoundation/CoreFoundation.h>

wxString getResourcesDirectoryPath() {
    wxString resourcesPath;
    CFBundleRef mainBundle = CFBundleGetMainBundle();
    if (mainBundle) {
        CFURLRef resourcesURL = CFBundleCopyResourcesDirectoryURL(mainBundle);
        if (resourcesURL) {
            char resourcePathChars[PATH_MAX];
            if (CFURLGetFileSystemRepresentation(resourcesURL, TRUE, (UInt8 *)resourcePathChars, PATH_MAX)) {
                resourcesPath = wxString::FromUTF8Unchecked(resourcePathChars);
            }
            CFRelease(resourcesURL);
        }
    }
    return resourcesPath;
}