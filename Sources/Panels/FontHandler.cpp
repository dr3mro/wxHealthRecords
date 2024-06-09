#include "FontHandler.h"
#include "Fontawesome.hpp"
#include "wx/filename.h"
#include <wx/file.h>
#include <wx/font.h>
#include <wx/stdpaths.h>

#define FONT_FACE_NAME "Font Awesome 6 Pro Regular"
#define TTF_FILE_NAME "fa_regular_400.ttf"
#define TTF_ARRAY arr_fa_regular_400_ttf

FontHandler::FontHandler ()
{
  wxStandardPaths &stdPaths = wxStandardPaths::Get ();
  wxFileName fontFileName (stdPaths.GetTempDir (), TTF_FILE_NAME);
  fontFilePath = fontFileName.GetFullPath ();
}

FontHandler::~FontHandler () {}

bool
FontHandler::DumpFontToTempFile ()
{
  wxFile file;
  if (!file.Open (fontFilePath, wxFile::write))
    {
      return false;
    }
  file.Write (TTF_ARRAY, sizeof (TTF_ARRAY));
  file.Close ();
  return true;
}

wxFont
FontHandler::LoadFont ()
{
  if (!DumpFontToTempFile ())
    {
      return wxNullFont;
    }
  wxFont font;
  if (wxFileExists (fontFilePath) && wxFont::AddPrivateFont (fontFilePath))
    {
      font = wxFont (14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                     wxFONTWEIGHT_NORMAL, false, wxT (FONT_FACE_NAME));

      if (font.IsOk ())
        {
          return font;
        }
    }
  return wxNullFont;
}