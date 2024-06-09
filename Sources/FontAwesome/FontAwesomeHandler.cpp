#include "FontAwesomeHandler.h "
#include "Fontawesome.hpp"
#include "wx/filename.h"
#include <wx/file.h>
#include <wx/font.h>
#include <wx/stdpaths.h>

#define FONT_FACE_NAME "Font Awesome 6 Pro Regular"
#define TTF_FILE_NAME "fa_regular_400.ttf"
#define TTF_ARRAY arr_fa_regular_400_ttf

FontAwesomeHandler::FontAwesomeHandler()
{
    wxStandardPaths& stdPaths = wxStandardPaths::Get();
    wxFileName fontFileName(stdPaths.GetTempDir(), TTF_FILE_NAME);
    fontFilePath = fontFileName.GetFullPath();
}

FontAwesomeHandler::~FontAwesomeHandler()
{
}

bool FontAwesomeHandler::DumpFontToTempFile()
{
    wxFile file;
    if (!file.Open(fontFilePath, wxFile::write)) {
        return false;
    }
    return (file.Write(TTF_ARRAY, sizeof(TTF_ARRAY)) == sizeof(TTF_ARRAY) && file.Close());
}

wxFont FontAwesomeHandler::LoadFont()
{
    if (!DumpFontToTempFile()) {
        return wxNullFont;
    }
    wxFont font;
    if (wxFileExists(fontFilePath) && wxFont::AddPrivateFont(fontFilePath)) {
        font = wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT(FONT_FACE_NAME));
    }
    return font.IsOk() ? font : wxNullFont;
}