#pragma once

#include "../Controls/ActionButton.cpp"
#include <wx/sizer.h>
#include <wx/wx.h>

#include <wx/font.h>
#include <wx/fs_mem.h>
#include <wx/mstream.h>
#include <wx/stdpaths.h>

#include "fontawesome.h"

class ButtonPanel : public wxPanel
{

public:
  ButtonPanel (wxWindow *parent)
      : wxPanel (parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
  {
    // Define the Font Awesome unicode characters for icons
    const wxString icons[] = {
      wxT ("\uf055"), // Add icon
      wxT ("\uf002"), // Search icon
      wxT ("\uf487"), // Patient icon
      wxT ("\uf570"), // Reports icon
      wxT ("\uf46b"), // Medicine icon
      wxT ("\uf073"), // Agenda icon
      wxT ("\uf81d"), // Income icon
      wxT ("\uf013")  // Settings icon
    };

    // Define the corresponding text labels
    const wxString labels[]
        = { wxT ("Add"),   wxT ("Search"), wxT ("Patient"), wxT ("Reports"),
            wxT ("Drugs"), wxT ("Agenda"), wxT ("Income"),  wxT ("Settings") };

    // Number of buttons
    const int numButtons = sizeof (icons) / sizeof (icons[0]);

    // Set the embeded font for icon
    wxFont iconFont = LoadFontAwesome ();

    // Set the default system font for text
    wxFont textFont = wxSystemSettings::GetFont (wxSYS_DEFAULT_GUI_FONT);

    // Create a vertical box sizer
    wxBoxSizer *sizer = new wxBoxSizer (wxVERTICAL);

    // Loop to create and add CustomButtons
    for (int i = 0; i < numButtons; ++i)
      {
        ActionButton *button
            = new ActionButton (this, wxID_ANY, icons[i], labels[i]);
        button->SetIconFont (iconFont);
        button->SetTextFont (textFont);
        sizer->Add (button, 0, wxALIGN_CENTER | wxTOP | wxLEFT | wxRIGHT, 5);
      }

    SetBackgroundColour (wxColour (75, 125, 75, 64));
    SetSizer (sizer);
    Layout ();
  }

private:
  wxFont
  LoadFontAwesome ()
  {
    // Register the memory file system handler
    wxMemoryFSHandler::AddFile ("memory:FontAwesome.otf", FontAwesome_otf,
                                FontAwesome_otf_len);

    // Load the font from memory
    wxFont font (14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                 wxFONTWEIGHT_NORMAL, false, "Font Awesome 6 Free Solid");
    if (font.IsOk ())
      {
        // Clean up: remove the font from memory file system
        wxMemoryFSHandler::RemoveFile ("memory:FontAwesome.otf");
        return font;
      }
    else
      {
        // Clean up: remove the font from memory file system
        wxMemoryFSHandler::RemoveFile ("memory:FontAwesome.otf");
        wxLogError ("Failed to load embedded font!");
      }
    return wxFont ();
  }
};