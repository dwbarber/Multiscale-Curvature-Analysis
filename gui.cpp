#include "gui.h"

class App : public wxApp {
    public:
        bool OnInit() {
            std::cout<<"GUI Test"<<std::endl;
            wxFrame* window = new wxFrame(NULL, wxID_ANY, "GUI Test", wxDefaultPosition, wxSize(600, 400));
            wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
            wxStaticText* text = new wxStaticText(window, wxID_ANY, "Well Done!\nEverything seems to be working",
                                                  wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
            text->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
            sizer->Add(text, 1, wxALIGN_CENTER);
            window->SetSizer(sizer);
            window->Show();
            return true;
        }
    };
     
    wxIMPLEMENT_APP(App);
int main(){

    //launch the GUI
    wxApp::SetInstance(new App());
    wxEntryStart(0, nullptr);
    wxTheApp->OnInit();
    wxTheApp->OnRun();
    wxEntryCleanup();
    
    return 0;
}