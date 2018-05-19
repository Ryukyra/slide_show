#include "Slideshow.h"

auto * COPY = new wxArrayString;
auto TIMER_ID = 235;
auto MUSIC_CHOICE = 1;
int DELAY_CHOICE;

// PANNELLO PER RIORDINAMENTO IMMAGINI

ImgArrange::ImgArrange(wxPanel * parent)
        : wxPanel(parent, wxID_ANY) {

    auto * vbox = new wxBoxSizer(wxVERTICAL);
    auto * lb = (Slideshow *) parent->GetParent();

    list_box = lb->listbox;

    up_button = new wxButton(this, wxID_UP, wxT("Move Up"));
    down_button = new wxButton(this, wxID_DOWN, wxT("Move Down"));

    for(int i = 1; i <= IMG_NUMBER; i++) {
        string number = to_string(i);
        list_box->Append("Image " + number);
    }

    list_box->SetSelection(0);

    wxString slot1 = list_box->GetString(0);
    wxString slot2 = list_box->GetString(1);
    wxString slot3 = list_box->GetString(2);
    wxString slot4 = list_box->GetString(3);
    wxString slot5 = list_box->GetString(4);
    wxString slot6 = list_box->GetString(5);
    wxString slot7 = list_box->GetString(6);
    wxString slot8 = list_box->GetString(7);

    slot1.Replace("Image 1", IMG_ONE);
    slot2.Replace("Image 2", IMG_TWO);
    slot3.Replace("Image 3", IMG_THREE);
    slot4.Replace("Image 4", IMG_FOUR);
    slot5.Replace("Image 5", IMG_FIVE);
    slot6.Replace("Image 6", IMG_SIX);
    slot7.Replace("Image 7", IMG_SEVEN);
    slot8.Replace("Image 8", IMG_EIGHT);

    COPY->Add(slot1);
    COPY->Add(slot2);
    COPY->Add(slot3);
    COPY->Add(slot4);
    COPY->Add(slot5);
    COPY->Add(slot6);
    COPY->Add(slot7);
    COPY->Add(slot8);

    Connect(wxID_UP, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ImgArrange::OnUp));
    Connect(wxID_DOWN, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ImgArrange::OnDown));

    vbox->Add(-1, 20);
    vbox->Add(up_button);
    vbox->Add(down_button, 0, wxTOP, 5);

    SetSizer(vbox);
}

// EVENTI PER SPOSTARE ORDINE IMMAGINI

void ImgArrange::OnUp(wxCommandEvent & event) {
    int i = list_box->GetSelection();
    if (i > 0 ) {
        COPY->Insert(COPY->Item(i+1), i-1);
        COPY->RemoveAt(i+1);
        list_box->Insert(list_box->GetString(i),i-1);
        list_box->Delete(i+1);
    }

}

void ImgArrange::OnDown(wxCommandEvent & event) {
    int i = list_box->GetSelection();
    if (i < list_box->GetCount()-1) {
        COPY->Insert(COPY->Item(i), i+2);
        COPY->RemoveAt(i);
        list_box->Insert(list_box->GetString(i),i+2);
        list_box->Delete(i);
    }
}

// CLASSE PRINCIPALE

Slideshow::Slideshow(const wxString& title)
		: wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(655, 680),
                  wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL, wxT("slideshow")) {

    this->SetSizeHints(wxSize(655, 680), wxSize(655, 680));
	this->SetBackgroundColour(wxColour(255, 255, 255));

	wxStaticBoxSizer * MainSizer;
	MainSizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Application created by Arrigo Lupori")), wxVERTICAL);
	
	wxWrapSizer * ImgSizer;
	ImgSizer = new wxWrapSizer(wxHORIZONTAL);

    small_images = new wxArrayString();

    for(int i = 1; i<=IMG_NUMBER; i++) {
        string number = to_string(i);
        small_images->Add("/Users/macbookair/CLionProjects/slide_show/slide_img/img_" + number + ".jpg", 1);
    }

	
	img1 = new wxStaticBitmap(MainSizer->GetStaticBox(), wxID_ANY,
	        wxBitmap(small_images->Item(0), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, 0);
	img2 = new wxStaticBitmap(MainSizer->GetStaticBox(), wxID_ANY,
	        wxBitmap(small_images->Item(1), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, 0);
	img3 = new wxStaticBitmap(MainSizer->GetStaticBox(), wxID_ANY,
	        wxBitmap(small_images->Item(2), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, 0);
	img4 = new wxStaticBitmap(MainSizer->GetStaticBox(), wxID_ANY,
	        wxBitmap(small_images->Item(3), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, 0);
	img5 = new wxStaticBitmap(MainSizer->GetStaticBox(), wxID_ANY,
	        wxBitmap(small_images->Item(4), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, 0);
	img6 = new wxStaticBitmap(MainSizer->GetStaticBox(), wxID_ANY,
	        wxBitmap(small_images->Item(5), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, 0);
	img7 = new wxStaticBitmap(MainSizer->GetStaticBox(), wxID_ANY,
	        wxBitmap(small_images->Item(6), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, 0);
	img8 = new wxStaticBitmap(MainSizer->GetStaticBox(), wxID_ANY,
	        wxBitmap(small_images->Item(7), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, 0);

    ImgSizer->Add(img1, 0, wxALL, 5);
    ImgSizer->Add(img2, 0, wxALL, 5);
    ImgSizer->Add(img3, 0, wxALL, 5);
    ImgSizer->Add(img4, 0, wxALL, 5);
    ImgSizer->Add(img5, 0, wxALL, 5);
    ImgSizer->Add(img6, 0, wxALL, 5);
    ImgSizer->Add(img7, 0, wxALL, 5);
    ImgSizer->Add(img8, 0, wxALL, 5);

    MainSizer->Add(ImgSizer, 1, wxEXPAND, 5);

	wxStaticBoxSizer * SecondarySizer;
	SecondarySizer = new wxStaticBoxSizer(new wxStaticBox(MainSizer->GetStaticBox(), wxID_ANY,
	                                      wxT("Start your slideshow:")), wxHORIZONTAL);

	wxWrapSizer* ControlSizer;
	ControlSizer = new wxWrapSizer(wxHORIZONTAL);
	
	delay_img = new wxStaticBitmap(SecondarySizer->GetStaticBox(), wxID_ANY, wxBitmap(wxT(DELAY_IMG), wxBITMAP_TYPE_ANY),
	                               wxDefaultPosition, wxDefaultSize, 0);

	wxString delay_choices[] = {wxT("1 Sec"), wxT("2 Sec"), wxT("3 Sec")};
	int d_choices = sizeof(delay_choices)/sizeof(wxString);

	delay_choice = new wxRadioBox(SecondarySizer->GetStaticBox(), wxID_FIND, wxT("Choose delay:"),
	                              wxDefaultPosition, wxDefaultSize, d_choices, delay_choices, 1, wxRA_SPECIFY_COLS);

	music_img = new wxStaticBitmap(SecondarySizer->GetStaticBox(), wxID_ANY, wxBitmap(wxT(MUSIC_IMG), wxBITMAP_TYPE_ANY),
	                               wxDefaultPosition, wxDefaultSize, 0);

	wxString toggle_choices[] = {wxT("On"), wxT("Off")};
	int m_choices = sizeof(toggle_choices)/sizeof(wxString);

	music_toggle = new wxRadioBox(SecondarySizer->GetStaticBox(), wxID_CONVERT, wxT("Toggle music:"),
	                              wxDefaultPosition, wxDefaultSize, m_choices, toggle_choices, 1, wxRA_SPECIFY_COLS);

	play_slideshow = new wxButton( SecondarySizer->GetStaticBox(), wxID_EXECUTE, wxT("  START  "));
    play_slideshow->SetBitmap(wxBitmap((PLAY_IMG), wxBITMAP_TYPE_ANY));

    ControlSizer->Add(delay_img, 0, wxALL, 5);
    ControlSizer->Add(delay_choice, 0, wxTOP, 5);
    ControlSizer->Add(music_img, 0, wxALL, 5);
    ControlSizer->Add(music_toggle, 0, wxTOP, 5);
    ControlSizer->Add(play_slideshow, 0, wxALL, 5);

    music_toggle->SetSelection(1);

    auto * panel = new wxPanel(this, -1);
    auto * hbox = new wxBoxSizer(wxVERTICAL);

    listbox = new wxListBox(panel, ID_LISTBOX, wxPoint(-1, -1), wxSize(-1, -1));

    button_panel = new ImgArrange(panel);

    hbox->Add(listbox, 3, wxEXPAND | wxALL, 20);
    hbox->Add(button_panel, 2, wxLEFT, 10);

    Connect(wxID_EXECUTE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Slideshow::OnPlay));
    Connect(wxID_FIND, wxEVT_RADIOBOX, wxCommandEventHandler(Slideshow::OnDelayBox));
    Connect(wxID_CONVERT, wxEVT_RADIOBOX, wxCommandEventHandler(Slideshow::OnMusicBox));

    panel->SetSizer(hbox);
    ImgSizer->Add(panel);

	SecondarySizer->Add(ControlSizer, 1, wxEXPAND, 5);
	MainSizer->Add(SecondarySizer, 1, wxEXPAND, 5);
	
	this->SetSizer(MainSizer);
	this->Layout();
	
	this->Centre(wxBOTH);
}

// METODI PER AVVIARE E STOPPARE LA MUSICA

void Slideshow::PlayMusic() {
    if (!music.openFromFile(MUSIC_FILE)){
        std::cout << "Error..." << std::endl;
    }
    else {
        music.setLoop(true);
        music.setVolume(50);
        music.play();
    }
}

void Slideshow::StopMusic() {
    music.stop();
}

// EVENTI PER SCELTA OPZIONI

void Slideshow::OnDelayBox(wxCommandEvent &event) {
    DELAY_CHOICE = this->delay_choice->GetSelection();
}

void Slideshow::OnMusicBox(wxCommandEvent &event) {
    MUSIC_CHOICE = this->music_toggle->GetSelection();
    if(MUSIC_CHOICE==1)
        StopMusic();
}

// EVENTO PER APERTURA NUOVA FINESTRA

void Slideshow::OnPlay(wxCommandEvent & event) {
    NowPlaying * newWindow = new NowPlaying(wxT("Now Playing"));
    newWindow->Show(true);
    if(MUSIC_CHOICE==0)
        PlayMusic();
}

Slideshow::~Slideshow() = default;

// CLASSE PER NUOVA FINESTRA

NowPlaying::NowPlaying(const wxString &title)
        : wxFrame(nullptr, wxID_ANY, wxT("Now Playing"), wxDefaultPosition, wxSize(670, 580),
                  wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL, wxT("Now Playing")), timer(this, TIMER_ID) {

    if(DELAY_CHOICE==0)
        timer.Start(FIRST_DELAY);
    if(DELAY_CHOICE==1)
        timer.Start(SECOND_DELAY);
    if(DELAY_CHOICE==2)
        timer.Start(THIRD_DELAY);

    this->SetSizeHints(wxSize(670,580), wxSize(670,580));
    this->SetBackgroundColour(wxColour(255, 255, 255));

    wxStaticBoxSizer * separate_sizer;
    separate_sizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Application created by Arrigo Lupori")),
                                          wxVERTICAL);
    wxBoxSizer * display_sizer;
    display_sizer = new wxBoxSizer(wxVERTICAL);

    numbered_images = new wxArrayString();

    for(int i =0; i<IMG_NUMBER; i++) {
        numbered_images->Add(COPY->Item(i), 1);
    }

    display_img = new wxStaticBitmap(separate_sizer->GetStaticBox(), wxID_ANY,
                                     wxBitmap(numbered_images->Item(0), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, 0);

    wxWrapSizer * button_sizer;
    button_sizer = new wxWrapSizer(wxHORIZONTAL);

    button_previous = new wxButton(separate_sizer->GetStaticBox(), wxID_JUSTIFY_LEFT, wxT("Previous"), wxDefaultPosition,
                                   wxDefaultSize, 0);
    button_next = new wxButton(separate_sizer->GetStaticBox(), wxID_JUSTIFY_CENTER, wxT("Next"), wxDefaultPosition,
                               wxDefaultSize, 0);

    button_sizer->SetMinSize(wxSize(100, 100));

    display_sizer->Add(display_img, 0, wxALL, 5);
    button_sizer->Add(button_previous, 0, wxALL, 5);
    button_sizer->Add(button_next, 0, wxALL, 5 );
    display_sizer->Add(button_sizer, 1, wxEXPAND, 5);
    separate_sizer->Add(display_sizer, 1, wxEXPAND, 5);

    Connect(wxID_JUSTIFY_LEFT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(NowPlaying::OnPrevious));
    Connect(wxID_JUSTIFY_CENTER, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(NowPlaying::OnNext));
    Connect(timer.GetId(), wxEVT_TIMER, wxTimerEventHandler(NowPlaying::OnNextTimer));

    this->SetSizer(separate_sizer);
    this->Layout();
    this->Centre(wxBOTH);
}

// ITERATORE

int NowPlaying::GetCount() {
    return count;
}

void NowPlaying::SetCount(int replacement) {
    count = replacement;
}

// EVENTI PER SPOSTARE LE SLIDE AVANTI O INDIETRO

void NowPlaying::OnPrevious(wxCommandEvent & event) {
    if(NowPlaying::GetCount()!=0) {
        int i = numbered_images->Index(numbered_images->Item(NowPlaying::GetCount()), true, false);
        display_img->SetBitmap(wxBitmap(numbered_images->Item(i - 1), wxBITMAP_TYPE_JPEG));
        NowPlaying::SetCount(i - 1);
    }
}

void NowPlaying::OnNext(wxCommandEvent & event) {
    if(NowPlaying::GetCount()!=COPY->GetCount()-1) {
        int i = numbered_images->Index(numbered_images->Item(NowPlaying::GetCount()), true, false);
        display_img->SetBitmap(wxBitmap(numbered_images->Item(i + 1), wxBITMAP_TYPE_JPEG));
        NowPlaying::SetCount(i + 1);
    }
}

// EVENTO TIMER

void NowPlaying::OnNextTimer(wxTimerEvent &event) {
    if(NowPlaying::GetCount()!=COPY->GetCount()-1) {
        int i = numbered_images->Index(numbered_images->Item(NowPlaying::GetCount()), true, false);
        display_img->SetBitmap(wxBitmap(numbered_images->Item(i + 1), wxBITMAP_TYPE_JPEG));
        NowPlaying::SetCount(i + 1);
    }
}

NowPlaying::~NowPlaying() = default;