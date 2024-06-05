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

  // wxPanel *mainPanel =
  //     new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
  // mainPanel->SetBackgroundColour(wxColor(100, 100, 200));

  wxBoxSizer *panelSizer = new wxBoxSizer(wxHORIZONTAL);

  wxPanel *panel1 =
      new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
  wxPanel *panel2 =
      new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
  wxPanel *panel3 =
      new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));

  panel1->SetBackgroundColour(wxColour(100, 100, 200));
  panel2->SetBackgroundColour(wxColour(100, 200, 100));
  panel3->SetBackgroundColour(wxColour(200, 100, 100));

  panelSizer->Add(panel1, 1, wxEXPAND);
  panelSizer->Add(panel2, 1, wxEXPAND);
  panelSizer->Add(panel3, 1, wxEXPAND);

  this->SetSizerAndFit(panelSizer);
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