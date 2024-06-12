// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include "wx/filename.h"
#include <wx/file.h>
#include <wx/stdpaths.h>
#include <wx/wx.h>
#endif

#include "FontAwesomeHandler.hpp"
#include "Resources/FontAwesome.hpp"

#define FONT_FACE_NAME "Font Awesome 6 Pro Regular"
#define TTF_FILE_NAME "fa-regular-400.ttf"
#define TTF_ARRAY arr_fa_regular_400_ttf

#ifdef __APPLE__
#include "Common/CommonApple.hpp"
#endif

FontAwesomeHandler::FontAwesomeHandler()
{
#ifdef __APPLE__
    wxFileName fontFileName(getResourcesDirectoryPath().Append("/Fonts/"), TTF_FILE_NAME);
    fontFilePath = fontFileName.GetFullPath();
#else
    wxStandardPaths& stdPaths = wxStandardPaths::Get();
    wxFileName fontFileName(stdPaths.GetTempDir(), TTF_FILE_NAME);
    fontFilePath = fontFileName.GetFullPath();
#endif
}

wxFont FontAwesomeHandler::LoadFontAwesome()
{
#ifndef __APPLE__
    if (!DumpFontToTempFile()) {
        return wxNullFont;
    }
#endif
    wxFont font;
    if (wxFileExists(fontFilePath) && wxFont::AddPrivateFont(fontFilePath)) {
        font = wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT(FONT_FACE_NAME));
    }
    return font.IsOk() ? font : wxNullFont;
}

bool FontAwesomeHandler::DumpFontToTempFile()
{
    wxFile file;
    if (!file.Open(fontFilePath, wxFile::write)) {
        return false;
    }
    return (file.Write(TTF_ARRAY, sizeof(TTF_ARRAY)) == sizeof(TTF_ARRAY) && file.Close());
}