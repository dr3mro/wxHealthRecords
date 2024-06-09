#ifndef FONTAWESOMEHANDLER_H
#define FONTAWESOMEHANDLER_H
#include <wx/font.h>

class FontAwesomeHandler {
public:
    FontAwesomeHandler();
    ~FontAwesomeHandler();

    wxFont LoadFontAwesome();

private:
    wxString fontFilePath;
    bool DumpFontToTempFile();
};
#endif // FONTAWESOMEHANDLER_H