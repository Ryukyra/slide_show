#include "slide.h"

const int FIRST_DELAY = 1000;
const int SECOND_DELAY = 2000;
const int THIRD_DELAY = 3000;
auto * COPY = new wxArrayString;
int DELAY_CHOICE;
int MUSIC_CHOICE;
int TIMER_ID = 235;

//Pannello per il controllo della lista di immagini da poter riordinare

MyPanel::MyPanel(wxPanel * parent)
        : wxPanel(parent, wxID_ANY) {

    auto * vbox = new wxBoxSizer(wxVERTICAL);
    auto * lb = (Slideshow *) parent->GetParent();
    list_box = lb->listbox;

    up_button = new wxButton(this, wxID_UP, wxT("Move Up"));
    down_button = new wxButton(this, wxID_DOWN, wxT("Move Down"));

    list_box->Append("Image 1");
    list_box->Append("Image 2");
    list_box->Append("Image 3");
    list_box->Append("Image 4");
    list_box->Append("Image 5");
    list_box->Append("Image 6");
    list_box->Append("Image 7");
    list_box->Append("Image 8");

    list_box->SetSelection(0);

    wxString one = list_box->GetString(0);
    one.Replace("Image 1", "/Users/macbookair/CLionProjects/slide_show/numbered/img_1.jpg");
    wxString two = list_box->GetString(1);
    two.Replace("Image 2", "/Users/macbookair/CLionProjects/slide_show/numbered/img_2.jpg");
    wxString three = list_box->GetString(2);
    three.Replace("Image 3", "/Users/macbookair/CLionProjects/slide_show/numbered/img_3.jpg");
    wxString four = list_box->GetString(3);
    four.Replace("Image 4", "/Users/macbookair/CLionProjects/slide_show/numbered/img_4.jpg");
    wxString five = list_box->GetString(4);
    five.Replace("Image 5", "/Users/macbookair/CLionProjects/slide_show/numbered/img_5.jpg");
    wxString six = list_box->GetString(5);
    six.Replace("Image 6", "/Users/macbookair/CLionProjects/slide_show/numbered/img_6.jpg");
    wxString seven = list_box->GetString(6);
    seven.Replace("Image 7", "/Users/macbookair/CLionProjects/slide_show/numbered/img_7.jpg");
    wxString eight = list_box->GetString(7);
    eight.Replace("Image 8", "/Users/macbookair/CLionProjects/slide_show/numbered/img_8.jpg");

    COPY->Add(one);
    COPY->Add(two);
    COPY->Add(three);
    COPY->Add(four);
    COPY->Add(five);
    COPY->Add(six);
    COPY->Add(seven);
    COPY->Add(eight);

    Connect(wxID_UP, wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(MyPanel::OnUp));
    Connect(wxID_DOWN, wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(MyPanel::OnDown));

    vbox->Add(-1, 20);
    vbox->Add(up_button);
    vbox->Add(down_button, 0, wxTOP, 5);

    SetSizer(vbox);
}

//Eventi su bottoni per spostare gli elementi su o giu

void MyPanel::OnUp(wxCommandEvent & event) {
    int i = list_box->GetSelection();
    if (i > 0 ) {
        COPY->Insert(COPY->Item(i+1), i-1);
        COPY->RemoveAt(i+1);
        list_box->Insert(list_box->GetString(i),i-1);
        list_box->Delete(i+1);
    }

    cout << COPY->GetCount() << endl;
    cout << COPY->Item(0) << endl;
    cout << COPY->Item(1) << endl;
    cout << COPY->Item(2) << endl;
    cout << COPY->Item(3) << endl;
    cout << COPY->Item(4) << endl;
    cout << COPY->Item(5) << endl;
    cout << COPY->Item(6) << endl;
    cout << COPY->Item(7) << endl;
    cout << endl;

}

void MyPanel::OnDown(wxCommandEvent & event) {
    int i = list_box->GetSelection();
    if (i < list_box->GetCount()-1) {
        COPY->Insert(COPY->Item(i), i+2);
        COPY->RemoveAt(i);
        list_box->Insert(list_box->GetString(i),i+2);
        list_box->Delete(i);
    }
}

//Classe principale

Slideshow::Slideshow(const wxString& title )
		: wxFrame( nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(655, 680), wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL, wxT("slideshow") )
{
	this->SetSizeHints( wxSize( 655,680 ), wxSize( 655,680 ) );
	this->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	wxStaticBoxSizer * MainSizer;
	MainSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Application created by Arrigo Lupori") ), wxVERTICAL );
	
	wxWrapSizer * ImgSizer;
	ImgSizer = new wxWrapSizer( wxHORIZONTAL );

    small_images = new wxArrayString();
    small_images->Add("/Users/macbookair/CLionProjects/slide_show/slide_img/img_1.jpg", 1);
    small_images->Add("/Users/macbookair/CLionProjects/slide_show/slide_img/img_2.jpg", 1);
    small_images->Add("/Users/macbookair/CLionProjects/slide_show/slide_img/img_3.jpg", 1);
    small_images->Add("/Users/macbookair/CLionProjects/slide_show/slide_img/img_4.jpg", 1);
    small_images->Add("/Users/macbookair/CLionProjects/slide_show/slide_img/img_5.jpg", 1);
    small_images->Add("/Users/macbookair/CLionProjects/slide_show/slide_img/img_6.jpg", 1);
    small_images->Add("/Users/macbookair/CLionProjects/slide_show/slide_img/img_7.jpg", 1);
    small_images->Add("/Users/macbookair/CLionProjects/slide_show/slide_img/img_8.jpg", 1);
	
	img1 = new wxStaticBitmap( MainSizer->GetStaticBox(), wxID_ANY, wxBitmap( small_images->Item(0), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	ImgSizer->Add( img1, 0, wxALL, 5 );
	
	img2 = new wxStaticBitmap( MainSizer->GetStaticBox(), wxID_ANY, wxBitmap( small_images->Item(1), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	ImgSizer->Add( img2, 0, wxALL, 5 );
	
	img3 = new wxStaticBitmap( MainSizer->GetStaticBox(), wxID_ANY, wxBitmap( small_images->Item(2), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	ImgSizer->Add( img3, 0, wxALL, 5 );
	
	img4 = new wxStaticBitmap( MainSizer->GetStaticBox(), wxID_ANY, wxBitmap( small_images->Item(3), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	ImgSizer->Add( img4, 0, wxALL, 5 );
	
	img5 = new wxStaticBitmap( MainSizer->GetStaticBox(), wxID_ANY, wxBitmap( small_images->Item(4), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	ImgSizer->Add( img5, 0, wxALL, 5 );
	
	img6 = new wxStaticBitmap( MainSizer->GetStaticBox(), wxID_ANY, wxBitmap( small_images->Item(5), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	ImgSizer->Add( img6, 0, wxALL, 5 );
	
	img7 = new wxStaticBitmap( MainSizer->GetStaticBox(), wxID_ANY, wxBitmap( small_images->Item(6), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	ImgSizer->Add( img7, 0, wxALL, 5 );
	
	img8 = new wxStaticBitmap( MainSizer->GetStaticBox(), wxID_ANY, wxBitmap( small_images->Item(7), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	ImgSizer->Add( img8, 0, wxALL, 5 );

	MainSizer->Add( ImgSizer, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer * SecondarySizer;
	SecondarySizer = new wxStaticBoxSizer( new wxStaticBox( MainSizer->GetStaticBox(), wxID_ANY, wxT("Start your slideshow:") ), wxHORIZONTAL );
	
	wxWrapSizer* ControlSizer;
	ControlSizer = new wxWrapSizer( wxHORIZONTAL );
	
	delay_img = new wxStaticBitmap( SecondarySizer->GetStaticBox(), wxID_ANY, wxBitmap( wxT("/Users/macbookair/CLionProjects/slide_show/slide_img/button_1.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	ControlSizer->Add( delay_img, 0, wxALL, 5 );

	wxString delay_choiceChoices[] = { wxT("1 Sec"), wxT("2 Sec"), wxT("3 Sec") };
	int delay_choiceNChoices = sizeof( delay_choiceChoices ) / sizeof( wxString );
	delay_choice = new wxRadioBox( SecondarySizer->GetStaticBox(), wxID_FIND, wxT("Choose delay:"), wxDefaultPosition, wxDefaultSize, delay_choiceNChoices, delay_choiceChoices, 1, wxRA_SPECIFY_COLS );
	ControlSizer->Add( delay_choice, 0, wxTOP, 5 );
	
	music_img = new wxStaticBitmap( SecondarySizer->GetStaticBox(), wxID_ANY, wxBitmap( wxT("/Users/macbookair/CLionProjects/slide_show/slide_img/button_3.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	ControlSizer->Add( music_img, 0, wxALL, 5 );

	wxString music_toggleChoices[] = { wxT("On"), wxT("Off") };
	int music_toggleNChoices = sizeof( music_toggleChoices ) / sizeof( wxString );
	music_toggle = new wxRadioBox( SecondarySizer->GetStaticBox(), wxID_CONVERT, wxT("Toggle music:"), wxDefaultPosition, wxDefaultSize, music_toggleNChoices, music_toggleChoices, 1, wxRA_SPECIFY_COLS );
	music_toggle->SetSelection( 1 );
	ControlSizer->Add( music_toggle, 0, wxTOP, 5 );

    play_slideshow = new wxButton( SecondarySizer->GetStaticBox(), wxID_EXECUTE, wxT("  START  "));
    play_slideshow->SetBitmap(wxBitmap(("/Users/macbookair/CLionProjects/slide_show/slide_img/button_2.png"), wxBITMAP_TYPE_ANY));
    ControlSizer->Add( play_slideshow, 0, wxALL, 5);

    wxPanel * panel = new wxPanel(this, -1);
    auto * hbox = new wxBoxSizer(wxVERTICAL);

    listbox = new wxListBox(panel, ID_LISTBOX,
                            wxPoint(-1, -1), wxSize(-1, -1));

    hbox->Add(listbox, 3, wxEXPAND | wxALL, 20);
    button_panel = new MyPanel(panel);
    hbox->Add(button_panel, 2, wxLEFT, 10);

    Connect(wxID_EXECUTE, wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(Slideshow::OnPlay));
    Connect(wxID_FIND, wxEVT_RADIOBOX,
            wxCommandEventHandler(Slideshow::OnDelayBox));
    Connect(wxID_CONVERT, wxEVT_RADIOBOX,
            wxCommandEventHandler(Slideshow::OnMusicBox));

    panel->SetSizer(hbox);
    ImgSizer->Add(panel);

	SecondarySizer->Add( ControlSizer, 1, wxEXPAND, 5 );
	MainSizer->Add( SecondarySizer, 1, wxEXPAND, 5 );
	
	this->SetSizer( MainSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
}

//Evento bottone per far partire lo slideshow su nuova finestra

void Slideshow::OnPlay(wxCommandEvent & event) {
    NowPlaying * newWindow = new NowPlaying(wxT("Now Playing"));
    newWindow->Show(true);
}

void Slideshow::OnDelayBox(wxCommandEvent &event) {
    DELAY_CHOICE = this->delay_choice->GetSelection();
}

void Slideshow::OnMusicBox(wxCommandEvent &event) {
    MUSIC_CHOICE = this->music_toggle->GetSelection();
    cout << MUSIC_CHOICE << endl;
}

Slideshow::~Slideshow() = default;

//Classe per la nuova finestra

NowPlaying::NowPlaying(const wxString &title)
        : wxFrame(nullptr, wxID_ANY, wxT("Now Playing"), wxDefaultPosition, wxSize(670, 580), wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL, wxT("Now Playing")), timer(this, TIMER_ID) {

    if(DELAY_CHOICE==0)
        timer.Start(FIRST_DELAY);
    if(DELAY_CHOICE==1)
        timer.Start(SECOND_DELAY);
    if(DELAY_CHOICE==2)
        timer.Start(THIRD_DELAY);

    this->SetSizeHints( wxSize( 670,580 ), wxSize( 670,580 ) );
    this->SetBackgroundColour( wxColour( 255, 255, 255 ) );

    wxStaticBoxSizer * separate_sizer;
    separate_sizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Application created by Arrigo Lupori") ), wxVERTICAL );

    wxBoxSizer* display_sizer;
    display_sizer = new wxBoxSizer( wxVERTICAL );

    numbered_images = new wxArrayString();
    numbered_images->Add(COPY->Item(0), 1);
    numbered_images->Add(COPY->Item(1), 1);
    numbered_images->Add(COPY->Item(2), 1);
    numbered_images->Add(COPY->Item(3), 1);
    numbered_images->Add(COPY->Item(4), 1);
    numbered_images->Add(COPY->Item(5), 1);
    numbered_images->Add(COPY->Item(6), 1);
    numbered_images->Add(COPY->Item(7), 1);

    display_img = new wxStaticBitmap( separate_sizer->GetStaticBox(), wxID_ANY, wxBitmap( numbered_images->Item(0), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
    display_sizer->Add( display_img, 0, wxALL, 5 );

    wxWrapSizer* button_sizer;
    button_sizer = new wxWrapSizer( wxHORIZONTAL );

    button_sizer->SetMinSize( wxSize( 100,100 ) );
    button_previous = new wxButton( separate_sizer->GetStaticBox(), wxID_JUSTIFY_LEFT, wxT("Previous"), wxDefaultPosition, wxDefaultSize, 0 );
    button_sizer->Add( button_previous, 0, wxALL, 5 );

    button_next = new wxButton( separate_sizer->GetStaticBox(), wxID_JUSTIFY_CENTER, wxT("Next"), wxDefaultPosition, wxDefaultSize, 0 );
    button_sizer->Add( button_next, 0, wxALL, 5 );

    display_sizer->Add( button_sizer, 1, wxEXPAND, 5 );
    separate_sizer->Add( display_sizer, 1, wxEXPAND, 5 );

    Connect(wxID_JUSTIFY_LEFT, wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(NowPlaying::OnPrevious));
    Connect(wxID_JUSTIFY_CENTER, wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(NowPlaying::OnNext));
    Connect(timer.GetId(), wxEVT_TIMER,
            wxTimerEventHandler(NowPlaying::OnNextTimer));

    this->SetSizer( separate_sizer );
    this->Layout();

    this->Centre( wxBOTH );
}

//Getter e Setter per iteratore

int NowPlaying::GetCount() {
    return count;
}

void NowPlaying::SetCount(int replacement) {
    count = replacement;
}

//Bottoni per andare avanti e indietro nello slideshow

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

void NowPlaying::OnNextTimer(wxTimerEvent &event) {
    if(NowPlaying::GetCount()!=COPY->GetCount()-1) {
        int i = numbered_images->Index(numbered_images->Item(NowPlaying::GetCount()), true, false);
        display_img->SetBitmap(wxBitmap(numbered_images->Item(i + 1), wxBITMAP_TYPE_JPEG));
        NowPlaying::SetCount(i + 1);
    }
}


NowPlaying::~NowPlaying() = default;
