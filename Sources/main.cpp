// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Panels/CommandPanel.cpp"

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
    MyFrame();

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};

enum {
    ID_Hello = 1
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "Health Records")
{
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
        "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    wxPanel* mainPanel
        = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    mainPanel->SetBackgroundColour(wxColour(100, 100, 200));

    ButtonPanel* buttonPanel = new ButtonPanel(this);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
    mainSizer->Add(buttonPanel, 0, wxEXPAND | wxALL, 5);
    mainSizer->Add(mainPanel, 1, wxEXPAND | wxRIGHT | wxTOP | wxBOTTOM, 5);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);

    this->SetSizerAndFit(mainSizer);
    this->SetSize(FromDIP(wxSize(1366, static_cast<int>(768 * 0.9))));
    this->CenterOnScreen();
}

void MyFrame::OnExit(wxCommandEvent&)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent&)
{
    wxMessageBox("This is a wxWidgets Hello World example", "About Hello World",
        wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent&)
{
    wxLogMessage("Hello world from wxWidgets!");
}
