#pragma once
#include "Controls/StaticText.cpp"
#include <wx/wx.h>

class ActionButton : public wxPanel {
public:
    ActionButton(wxWindow* parent, wxWindowID id = wxID_ANY,
        const wxString& icon = "", const wxString& text = "",
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize);

    void SetIconFont(const wxFont& font);
    void SetTextFont(const wxFont& font);

private:
    void OnMouseDown(wxMouseEvent& event);
    void OnMouseUp(wxMouseEvent& event);
    void OnMouseEnter(wxMouseEvent& event);
    void OnMouseLeave(wxMouseEvent& event);
    void OnPaint(wxPaintEvent& event);

    StaticText* iconText;
    StaticText* labelText;
    bool m_hovered = false;
    bool m_pressed = false;
};