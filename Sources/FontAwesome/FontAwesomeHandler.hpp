#pragma once

#include <wx/font.h>

class FontAwesomeHandler {
public:
    FontAwesomeHandler();
    ~FontAwesomeHandler() = default;

    wxFont LoadFontAwesome();

private:
    wxString fontFilePath;
    bool DumpFontToTempFile();
};
