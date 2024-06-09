
#include "Frames/MainFrame.hpp"
#include "Panels/CommandPanel.hpp"

MainFrame::MainFrame()
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

    CommandPanel* commandPanel = new CommandPanel(this);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
    mainSizer->Add(commandPanel, 0, wxEXPAND | wxALL, 5);
    mainSizer->Add(mainPanel, 1, wxEXPAND | wxRIGHT | wxTOP | wxBOTTOM, 5);

    CreateStatusBar();
    SetStatusText("Welcome to Health Records.");

    Bind(wxEVT_MENU, &MainFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);

    this->SetSizerAndFit(mainSizer);
    this->SetSize(FromDIP(wxSize(1366, static_cast<int>(768 * 0.9))));
    this->CenterOnScreen();
}

MainFrame::~MainFrame()
{
}

void MainFrame::OnExit(wxCommandEvent&)
{
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent&)
{
    wxMessageBox("This is a Health Records prototype.", "About Health Records",
        wxOK | wxICON_INFORMATION);
}

void MainFrame::OnHello(wxCommandEvent&)
{
    wxLogMessage("Hello world from Health Records!");
}
