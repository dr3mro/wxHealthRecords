#ifndef FONTAWESOMEHANDLER_H
#define FONTAWESOMEHANDLER_H
#include <wx/font.h>
#include <wx/wx.h>

class FontAwesomeHandler {
public:
    FontAwesomeHandler();
    ~FontAwesomeHandler();

    wxFont LoadFont();

private:
    wxString fontFilePath;
    bool DumpFontToTempFile();
};
#endif // FONTAWESOMEHANDLER_H