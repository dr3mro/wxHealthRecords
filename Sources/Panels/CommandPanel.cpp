#include "../Controls/ActionButton.cpp"
#include "../FontAwesome/FontAwesomeHandler.h"
#include <wx/sizer.h>
#include <wx/wx.h>

class ButtonPanel : public wxPanel {

public:
    ButtonPanel(wxWindow* parent)
        : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
    {
        FontAwesomeHandler fontAwesomeHandler;
        // Set the embeded font for icon
        wxFont iconFont = fontAwesomeHandler.LoadFontAwesome();

        // Set the default system font for text
        wxFont textFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);

        // Define the Font Awesome unicode characters for icons
        const wxString icons[] = {
            wxT("\uf055"), // Add icon
            wxT("\uf002"), // Search icon
            wxT("\uf487"), // Patient icon
            wxT("\uf570"), // Reports icon
            wxT("\uf46b"), // Medicine icon
            wxT("\uf073"), // Agenda icon
            wxT("\uf81d"), // Income icon
            wxT("\uf013") // Settings icon
        };

        // Define the corresponding text labels
        const wxString labels[]
            = { wxT("Add"), wxT("Search"), wxT("Patient"), wxT("Reports"),
                  wxT("Drugs"), wxT("Agenda"), wxT("Income"), wxT("Settings") };

        // Number of buttons
        const int numButtons = sizeof(icons) / sizeof(icons[0]);

        // Create a vertical box sizer
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

        // Loop to create and add CustomButtons
        for (int i = 0; i < numButtons; ++i) {
            ActionButton* button
                = new ActionButton(this, wxID_ANY, icons[i], labels[i],
                    wxDefaultPosition, FromDIP(wxSize(64, 64)));
            button->SetIconFont(iconFont);
            button->SetTextFont(textFont);
            sizer->Add(button, 0, wxALIGN_CENTER | wxTOP | wxLEFT | wxRIGHT, 5);
        }

        SetBackgroundColour(wxColour(75, 125, 75, 64));
        SetSizer(sizer);
        Layout();
    }
};