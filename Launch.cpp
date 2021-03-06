#include "Launch.h"

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    wxImage::AddHandler(new wxJPEGHandler);
    wxImage::AddHandler(new wxPNGHandler);
    wxSetAssertHandler(nullptr);
    Slideshow * slideshow = new Slideshow(wxT("Slideshow"));
    slideshow->Show(true);
    return true;
}

