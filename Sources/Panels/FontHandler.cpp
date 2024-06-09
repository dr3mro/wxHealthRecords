#include "FontHandler.h"
#include "Fontawesome.hpp"
#include "wx/filename.h"
#include <wx/file.h>
#include <wx/font.h>
#include <wx/stdpaths.h>

FontHandler::FontHandler ()
{
  // Generate the temporary file path
  wxStandardPaths &stdPaths = wxStandardPaths::Get ();
  wxFileName tempFileName (stdPaths.GetTempDir (), "fa_solid_900.ttf");
  tempFilePath = tempFileName.GetFullPath ();
}

FontHandler::~FontHandler ()
{
  // Optionally delete the temporary font file
  if (wxFileExists (tempFilePath))
    {
      wxRemoveFile (tempFilePath);
    }
}

bool
FontHandler::DumpFontToTempFile ()
{
  wxFile file;
  if (!file.Open (tempFilePath, wxFile::write))
    {
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
<<<<<<< HEAD
  wxFont font;
  // Check if the font file can be loaded
  if (wxFileExists (tempFilePath) && wxFont::AddPrivateFont (tempFilePath))
    {
      font = wxFont (14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                     wxFONTWEIGHT_NORMAL, false,
                     wxT ("Font Awesome 6 Free Solid"));
    }
  else
    {
      wxLogError ("Could not load font from %s.", tempFilePath);
    }

=======

  wxFont::AddPrivateFont (tempFilePath);
  wxFont font
      = wxFont (14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL, false, wxT ("Font Awesome 6 Free Solid"));
>>>>>>> 6c1ef3966354dd408b2c1e942ecc5ac487db6792
  if (font.IsOk ())
    {
      return font;
    }
  return wxNullFont;
}