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
    Bind(wxEVT_MOTION, &StaticText::PropagateMouseEventsToParent, this);
    Bind(wxEVT_LEFT_DOWN, &StaticText::PropagateMouseEventsToParent, this);
    Bind(wxEVT_LEFT_UP, &StaticText::PropagateMouseEventsToParent, this);
}

void StaticText::PropagateMouseEventsToParent(wxMouseEvent& event)
{
    event.ResumePropagation(wxEVENT_PROPAGATE_MAX);
    event.Skip();
}
