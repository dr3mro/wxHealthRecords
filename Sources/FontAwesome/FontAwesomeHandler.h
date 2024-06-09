#ifndef FONTAWESOMEHANDLER_H
#define FONTAWESOMEHANDLER_H
#include <wx/font.h>
#include <wx/wx.h>

class FontAwesomeHandler {
public:
    FontAwesomeHandler();
    ~FontAwesomeHandler();

    bool DumpFontToTempFile();
    wxFont LoadFont();

private:
    wxString fontFilePath;
};
#endif // FONTAWESOMEHANDLER_H