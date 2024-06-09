#include <wx/wx.h>

class StaticText : public wxStaticText {
public:
    StaticText(wxWindow* parent, wxWindowID id, const wxString& label,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize, long style = 0,
        const wxString& name = wxStaticTextNameStr)
        : wxStaticText(parent, id, label, pos, size, style, name)
    {
        // Ensure that all mouse events are propagated to parent and not blocked here.
        BindEvents();
    }

private:
    void
    DoParentMouseEvent(wxMouseEvent& event)
    {
        // Propagate the mouse event to the parent window
        wxWindow* parent = GetParent();
        if (parent) {
            parent->ProcessWindowEvent(event);
        }
    }

    void
    OnMouseEnter(wxMouseEvent& event)
    {
        event.Skip();
        DoParentMouseEvent(event);
    }

    void
    OnMouseLeave(wxMouseEvent& event)
    {
        event.Skip();
        DoParentMouseEvent(event);
    }

    void
    OnLeftDown(wxMouseEvent& event)
    {
        event.Skip();
        DoParentMouseEvent(event);
    }

    void
    OnLeftUp(wxMouseEvent& event)
    {
        event.Skip();
        DoParentMouseEvent(event);
    }

    void
    OnRightDown(wxMouseEvent& event)
    {
        event.Skip();
        DoParentMouseEvent(event);
    }

    void
    OnRightUp(wxMouseEvent& event)
    {
        event.Skip();
        DoParentMouseEvent(event);
    }

    void
    OnMiddleDown(wxMouseEvent& event)
    {
        event.Skip();
        DoParentMouseEvent(event);
    }

    void
    OnMiddleUp(wxMouseEvent& event)
    {
        event.Skip();
        DoParentMouseEvent(event);
    }
    inline void
    BindEvents()
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
};