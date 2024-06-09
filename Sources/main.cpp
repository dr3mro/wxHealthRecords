#include "Frames/MainFrame.hpp"

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class HealthRecords : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(HealthRecords);

bool HealthRecords::OnInit()
{
    MainFrame* mainFrame = new MainFrame();
    mainFrame->Show(true);
    return true;
}
