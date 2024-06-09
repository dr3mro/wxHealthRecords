#pragma once

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
