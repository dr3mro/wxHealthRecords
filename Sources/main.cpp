// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyApp : public wxApp {
public:
  virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
  MyFrame();

private:
  void OnHello(wxCommandEvent &event);
  void OnExit(wxCommandEvent &event);
  void OnAbout(wxCommandEvent &event);
};

enum { ID_Hello = 1 };

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
  MyFrame *frame = new MyFrame();
  frame->Show(true);
  return true;
}

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "Health Records") {
  wxMenu *menuFile = new wxMenu;
  menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                   "Help string shown in status bar for this menu item");
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);

  wxMenu *menuHelp = new wxMenu;
  menuHelp->Append(wxID_ABOUT);

  wxMenuBar *menuBar = new wxMenuBar;
  menuBar->Append(menuFile, "&File");
  menuBar->Append(menuHelp, "&Help");

  SetMenuBar(menuBar);

  wxPanel *mainPanel =
      new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
  mainPanel->SetBackgroundColour(wxColor(100, 100, 200));
  wxFont font(42, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL,
              false, "JetBrainsMono Nerd Font");

  wxInitAllImageHandlers();
  wxImage icon("icon.png", wxBITMAP_TYPE_PNG);
  icon.Rescale(80, 80);
  wxBitmap bitmap(icon);

  wxButton *quitButton =
      new wxButton(mainPanel, wxID_ANY, "Bye!", wxDefaultPosition,
                   wxSize(FromDIP(80), FromDIP(80)), wxBU_AUTODRAW);

  quitButton->SetBitmap(bitmap);
  quitButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent &event) {
    wxLogMessage("This will exit the application, Bye.");
    this->Close();
  });

  wxBoxSizer *centerSizer = new wxBoxSizer(wxVERTICAL);
  centerSizer->AddStretchSpacer();
  centerSizer->Add(quitButton, wxSizerFlags().CenterHorizontal());
  centerSizer->AddStretchSpacer();

  mainPanel->SetSizerAndFit(centerSizer);
  CreateStatusBar();
  SetStatusText("Welcome to wxWidgets!");

  Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
  Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
  Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);

  this->SetSize(wxSize(1920, 1080));
  this->CenterOnScreen();
}

void MyFrame::OnExit(wxCommandEvent &event) { Close(true); }

void MyFrame::OnAbout(wxCommandEvent &event) {
  wxMessageBox("This is a wxWidgets Hello World example", "About Hello World",
               wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent &event) {
  wxLogMessage("Hello world from wxWidgets!");
}
