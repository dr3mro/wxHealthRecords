#ifndef FONTHANDLER_H
#define FONTHANDLER_H
#include <wx/font.h>
#include <wx/wx.h>

class FontHandler {
public:
    FontHandler();
    ~FontHandler();

    bool DumpFontToTempFile();
    wxFont LoadFont();

private:
    wxString fontFilePath;
};
#endif // FONTHANDLER_H