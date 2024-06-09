#include "FontHandler.h"
#include "Fontawesome.hpp"
#include "wx/filename.h"
#include <wx/file.h>
#include <wx/font.h>
#include <wx/stdpaths.h>

FontHandler::FontHandler ()
{
  wxStandardPaths &stdPaths = wxStandardPaths::Get ();
#if defined(__WIN32__) | defined(_WIN32) | defined(_WIN64)
  wxFileName fontFileName (stdPaths.GetTempDir (), "fa_solid_900.ttf");
#elif defined(__Linux__)
  wxFileName fontFileName (stdPaths.GetUserConfigDir (), "fa_solid_900.ttf");
#endif

  fontFilePath = fontFileName.GetFullPath ();
}

FontHandler::~FontHandler ()
{
  // Optionally delete the temporary font file
  if (wxFileExists (fontFilePath))
    {
      wxRemoveFile (fontFilePath);
    }
}

bool
FontHandler::DumpFontToTempFile ()
{
  wxFile file;
  if (!file.Open (fontFilePath, wxFile::write))
    {
      wxLogMessage ("Failed to dump awesome font!");
      return false;
    }
  file.Write (arr_fa_solid_900_ttf, sizeof (arr_fa_solid_900_ttf));
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
                     wxFONTWEIGHT_NORMAL, false,
                     wxT ("Font Awesome 6 Free Solid"));

      if (font.IsOk ())
        {
          return font;
        }
    }
  wxLogError ("Could not load font from %s.", fontFilePath);
  return wxNullFont;
}