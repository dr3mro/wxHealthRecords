#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "StaticText.hpp"

StaticText::StaticText(wxWindow* parent, wxWindowID id, const wxString& label,
    const wxPoint& pos,
    const wxSize& size, long style,
    const wxString& name)
    : wxStaticText(parent, id, label, pos, size, style, name)
{
    // Ensure that all mouse events are propagated to parent and not blocked here.
    BindEvents();
}

void StaticText::DoParentMouseEvent(wxMouseEvent& event)
{
    // Propagate the mouse event to the parent window
    wxWindow* parent = GetParent();
    if (parent) {
        parent->ProcessWindowEvent(event);
    }
}

void StaticText::OnMouseEnter(wxMouseEvent& event)
{
    event.Skip();
    DoParentMouseEvent(event);
}

void StaticText::OnMouseLeave(wxMouseEvent& event)
{
    event.Skip();
    DoParentMouseEvent(event);
}

void StaticText::OnLeftDown(wxMouseEvent& event)
{
    event.Skip();
    DoParentMouseEvent(event);
}

void StaticText::OnLeftUp(wxMouseEvent& event)
{
    event.Skip();
    DoParentMouseEvent(event);
}

void StaticText::OnRightDown(wxMouseEvent& event)
{
    event.Skip();
    DoParentMouseEvent(event);
}

void StaticText::OnRightUp(wxMouseEvent& event)
{
    event.Skip();
    DoParentMouseEvent(event);
}

void StaticText::OnMiddleDown(wxMouseEvent& event)
{
    event.Skip();
    DoParentMouseEvent(event);
}

void StaticText::OnMiddleUp(wxMouseEvent& event)
{
    event.Skip();
    DoParentMouseEvent(event);
}
inline void
StaticText::BindEvents()
{
    // Bind mouse enter and leave events to the button
    Bind(wxEVT_ENTER_WINDOW, &StaticText::OnMouseEnter, this);
    Bind(wxEVT_LEAVE_WINDOW, &StaticText::OnMouseLeave, this);
    Bind(wxEVT_LEFT_DOWN, &StaticText::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &StaticText::OnLeftUp, this);
    Bind(wxEVT_RIGHT_DOWN, &StaticText::OnRightDown, this);
    Bind(wxEVT_RIGHT_UP, &StaticText::OnRightUp, this);
    Bind(wxEVT_MIDDLE_DOWN, &StaticText::OnMiddleDown, this);
    Bind(wxEVT_MIDDLE_UP, &StaticText::OnMiddleUp, this);
}
