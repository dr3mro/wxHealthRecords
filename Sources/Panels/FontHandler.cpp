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
#if defined(__WIN32__) | defined(_WIN32) | defined(_WIN64)
  if (!file.Open (tempFilePath, wxFile::write))
    {
      return false;
    }
  else
    {
      file.Close ();
      return true;
    }
#else
  wxStandardPaths &stdPaths = wxStandardPaths::Get ();
  wxString homeDir = stdPaths.GetUserConfigDir ();
  if (!file.Open (homeDir, wxFile::write))
    {
      return false;
      wxLogMessage ("Failed to dump awesome font!");
    }
  else
    {
      file.Close ();
      wxLogMessage ("Done dumping awesome font!");
      return true;
    }
#elif defined(__Apple__)

#endif

  return false;
}

wxFont
FontHandler::LoadFont ()
{
  if (!DumpFontToTempFile ())
    {
      return wxNullFont;
    }
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
      std::cout << "Could not load font from" << tempFilePath << std::endl;
    }

  std::cout << "Could not load font from" << tempFilePath << std::endl;
  if (font.IsOk ())
    {
      std::cout << "Font is OK" << std::endl;
      return font;
    }
  return wxNullFont;
}