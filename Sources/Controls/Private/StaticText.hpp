#pragma once

#include <wx/wx.h>

class StaticText : public wxStaticText {
public:
    StaticText(wxWindow* parent, wxWindowID id, const wxString& label,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize, long style = 0,
        const wxString& name = wxStaticTextNameStr);
    ~StaticText() = default;

private:
    void
    PropagateMouseEventsToParent(wxMouseEvent& event);
};