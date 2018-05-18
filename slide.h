#ifndef __NONAME_H__
#define __NONAME_H__

#include <stdio.h>
#include <chrono>
#include <thread>
#include <functional>
#include <wx/textdlg.h>
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/wrapsizer.h>
#include <wx/radiobox.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/frame.h>
#include <wx/editlbox.h>
#include <wx/listbox.h>
#include <wx/button.h>
#include <wx/timer.h>
#include <audiere.h>

using namespace std;

class MyPanel : public wxPanel {
public:
    explicit MyPanel(wxPanel * parent);

    void OnUp(wxCommandEvent & event);
    void OnDown(wxCommandEvent & event);

    wxListBox * list_box;
    wxButton * up_button;
    wxButton * down_button;

};

class Slideshow : public wxFrame {
	protected:
        wxArrayString * small_images;
		wxStaticBitmap * img1;
		wxStaticBitmap * img2;
		wxStaticBitmap * img3;
		wxStaticBitmap * img4;
		wxStaticBitmap * img5;
		wxStaticBitmap * img6;
		wxStaticBitmap * img7;
		wxStaticBitmap * img8;
		wxStaticBitmap * delay_img;
		wxStaticBitmap * music_img;
		wxRadioBox * music_toggle;
        wxButton * play_slideshow;

	public:
		explicit Slideshow(const wxString & title);
        wxListBox * listbox;
        MyPanel * button_panel;
        wxRadioBox * delay_choice;
        void OnPlay(wxCommandEvent & event);
		void OnRadioBox(wxCommandEvent & event);
		~Slideshow();
	
};

class NowPlaying : public wxFrame {
private:
    int count = 0;
protected:
    wxArrayString * numbered_images;
    wxStaticBitmap * display_img;
    wxButton * button_previous;
    wxButton * button_next;
    wxTimer timer;
public:
    explicit NowPlaying(const wxString & title);
    int GetCount();
    void SetCount(int replacement);
    void OnPrevious(wxCommandEvent & event);
    void OnNext(wxCommandEvent & event);
    void OnNextTimer(wxTimerEvent & event);
    ~NowPlaying();
};

const int ID_LISTBOX = 5;

#endif //__NONAME_H__