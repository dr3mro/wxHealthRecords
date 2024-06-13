#include "Controls/NavigationButton.hpp"
#include "SoundEffects/SoundEffects.hpp"

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/sizer.h>
#include <wx/wx.h>
#endif

NavigationButton::NavigationButton(wxWindow* parent, wxWindowID id,
    const wxString& icon, const wxString& text,
    const wxPoint& pos,
    const wxSize& size)
    : wxPanel(parent, id, pos, size)
{
    /**
     *  Create a vertical box sizer to stack an icon and text within a button.
     *  Set the fonts for the icon and text.
     *  Center the icon and text horizontally within the button.
     *  Bind paint, mouse events, and window enter/leave events to corresponding methods.
     */
    // Create a vertical box sizer to stack the icon and text
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    // Create a static text for the icon
    iconText = new StaticText(this, wxID_ANY, icon, wxDefaultPosition,
        wxDefaultSize, wxALIGN_CENTER);
    iconText->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
        wxFONTWEIGHT_NORMAL));

    // Create a static text for the text string
    labelText = new StaticText(this, wxID_ANY, text, wxDefaultPosition,
        wxDefaultSize, wxALIGN_CENTER);
    labelText->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
        wxFONTWEIGHT_NORMAL));

    // Center the icon and text within the button
    sizer->AddStretchSpacer(1); // Add space above the icon
    sizer->Add(iconText, 0, wxALIGN_CENTER_HORIZONTAL);
    sizer->AddStretchSpacer(1); // Add space between the icon and text
    sizer->Add(labelText, 0, wxALIGN_CENTER_HORIZONTAL);
    sizer->AddStretchSpacer(1); // Add space below the text

    SetSizer(sizer);
    Layout();
    this->Bind(wxEVT_PAINT, &NavigationButton::OnPaint, this);
    this->Bind(wxEVT_LEFT_DOWN, &NavigationButton::OnMouseDown, this);
    this->Bind(wxEVT_LEFT_UP, &NavigationButton::OnMouseUp, this);
    this->Bind(wxEVT_ENTER_WINDOW, &NavigationButton::OnMouseEnter, this);
    this->Bind(wxEVT_LEAVE_WINDOW, &NavigationButton::OnMouseLeave, this);
}

// Public method to set the font for the icon
void NavigationButton::SetIconFont(const wxFont& font)
{
    iconText->SetFont(font);
    Layout();
}

// Public method to set the font for the text string
void NavigationButton::SetTextFont(const wxFont& font)
{
    labelText->SetFont(font);
    Layout();
}

void NavigationButton::OnMouseDown(wxMouseEvent& event)
{
    m_pressed = true;
    soundEffect.Play(SoundEffect::NavigationStart);
    Refresh();
    event.Skip();
}

void NavigationButton::OnMouseUp(wxMouseEvent& event)
{
    if (m_pressed) {
        wxCommandEvent evt(wxEVT_BUTTON, GetId());
        evt.SetInt(GetId());
        evt.SetEventObject(this);
        GetEventHandler()->ProcessEvent(evt);
    }
    m_pressed = false;
    Refresh();
    event.Skip();
}

void NavigationButton::OnMouseEnter(wxMouseEvent& event)
{
    m_hovered = true;
    Refresh();
    event.Skip();
}

void NavigationButton::OnMouseLeave(wxMouseEvent& event)
{
    // Get the global mouse position
    wxPoint globalMousePos = wxGetMousePosition();
    // Convert global position to client position relative to this panel
    wxPoint clientMousePos = ScreenToClient(globalMousePos);

    // Check if the mouse is still within the button's client area
    if (clientMousePos.x >= 0 && clientMousePos.y >= 0
        && clientMousePos.x < GetSize().x && clientMousePos.y < GetSize().y) {
        event.Skip();
        return; // Mouse is still within the button's client area
    }

    m_hovered = false;
    m_pressed = false; // Reset pressed state
    Refresh();
    event.Skip();
}

void NavigationButton::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);

    wxColour penColor;
    wxColour brushColor;
    if (m_pressed) {
        penColor = wxColour(255, 100, 100);
        brushColor = wxColour(150, 100, 100, 64);
    } else if (m_hovered) {
        penColor = wxColour(100, 255, 100);
        brushColor = wxColour(100, 200, 100, 100);
    } else {
        penColor = wxColour(100, 255, 100);
        brushColor = wxColour(100, 150, 100, 64);
    }
    wxPen pen(penColor, FromDIP(2));

    labelText->SetBackgroundColour(brushColor);
    iconText->SetBackgroundColour(brushColor);

    dc.SetBrush(brushColor);
    dc.SetPen(pen);

    dc.DrawRoundedRectangle(
        GetClientRect().GetX(), GetClientRect().GetY(),
        GetClientRect().GetWidth(), GetClientRect().GetHeight(), 10);
    event.Skip();
}