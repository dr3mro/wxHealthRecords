#ifndef FONTHANDLER_H
#define FONTHANDLER_H

#include <wx/filefn.h> // For wxFileName
#include <wx/font.h>
#include <wx/wx.h>

class FontHandler
{
public:
  FontHandler ();
  ~FontHandler ();

  bool DumpFontToTempFile ();
  wxFont LoadFont ();

private:
  wxString tempFilePath;
};

#endif // FONTHANDLER_H