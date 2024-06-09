#include "FontHandler.h"
#include "Fontawesome.hpp"
#include "wx/filename.h"
#include <wx/file.h>
#include <wx/font.h>
#include <wx/stdpaths.h>

FontHandler::FontHandler ()
{
  wxStandardPaths &stdPaths = wxStandardPaths::Get ();
#if defined(_WIN32)
  wxFileName fontFileName (stdPaths.GetTempDir (), "fa_solid_900.ttf");
#else
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
  file.Write (arr_fa_regular_400_ttf, sizeof (arr_fa_regular_400_ttf));
  file.Close ();
  return true;
}

wxFont
FontHandler::LoadFont ()
{
  if (!DumpFontToTempFile ())
    {
      wxLogError ("Could not dump font to %s.", fontFilePath);
      return wxNullFont;
    }
  wxFont font;
  if (wxFileExists (fontFilePath) && wxFont::AddPrivateFont (fontFilePath))
    {
      font = wxFont (14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                     wxFONTWEIGHT_NORMAL, false,
                     wxT ("Font Awesome 6 Pro Regular"));

      if (font.IsOk ())
        {
          return font;
        }
    }
  wxLogError ("Could not load font from %s.", fontFilePath);
  return wxNullFont;
}