#include <SFML/Audio.hpp>
#include <wx/wx.h>
#include <wx/wrapsizer.h>
#include <iostream>
#include <list>
#include "Constants.h"

using namespace std;

class ImgArrange : public wxPanel {
public:
    explicit ImgArrange(wxPanel * parent);
    void OnUp(wxCommandEvent & event);
    void OnDown(wxCommandEvent & event);
    wxListBox * list_box;
    wxButton * up_button;
    wxButton * down_button;
};

class Slideshow : public wxFrame {
    private:
        sf::Music music;

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
        wxButton * play_slideshow;

	public:
		explicit Slideshow(const wxString & title);
        wxListBox * listbox;
        ImgArrange * button_panel;
        wxRadioBox * music_toggle;
        wxRadioBox * delay_choice;
        void PlayMusic();
        void StopMusic();
        void OnPlay(wxCommandEvent & event);
		void OnDelayBox(wxCommandEvent & event);
		void OnMusicBox(wxCommandEvent & event);
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
