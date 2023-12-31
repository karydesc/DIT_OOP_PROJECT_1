//
// Created by Chris on 14/10/23.
//


#include "pomodoro.h"
#include <iostream>
#include <wx/wx.h>
#include <wx/string.h>
#include <chrono>
#include "myApp.h"
#include <wx/sound.h>

#ifdef _WIN32
#include <windows.h>
    string cls ="cls";
#else
string cls ="clear";
#endif


using namespace std::chrono_literals;
using namespace std;
wxDECLARE_APP(myApp);
void pomodoro::startSession(int workminutes,int breakminutes,wxStaticText* text,wxGauge* gauge) {
    this->processing =true;
    int secs;
    pauseflag=false;
    cancelFlag=false;

//restart pomodoro indefinitely
    while(true){
        secs = workminutes * 60;
        wxGetApp().CallAfter([gauge,secs](){ //set the range of the gauge
            gauge->SetRange(secs);
        });
    for (int i = secs; i >= 0;) {
        if (this->cancelFlag||quitRequested){
            this->processing=false;
            return;
        }       //handling window close/end thread

        if (!this->pauseflag) {
            this->WorkSeconds++;
            wxGetApp().CallAfter([i, text, gauge]() {
                text->SetLabelText(wxString::Format("Focus: %d:%02d", i / 60, i % 60)); //updating the timer
                gauge->SetValue(i);
            });
            i--;
        }
        std::this_thread::sleep_for(1s); //timer tick
    }
    wxSound::Play("../resources/breaktime.mp3");

    secs = breakminutes * 60; //repeat for break session
    wxGetApp().CallAfter([gauge,secs](){ //set the range of the gauge
            gauge->SetRange(secs);
    });
    for (int i = secs; i >= 0;) {
        if (this->cancelFlag||quitRequested){
            this->processing=false;
            return;
        }

        if(!this->pauseflag){
            wxGetApp().CallAfter([i, text, gauge]() {
                text->SetLabelText(wxString::Format("Break: %d:%02d", i / 60, i % 60));
                gauge->SetValue(i);
            });
            i--;

        }
        std::this_thread::sleep_for(1s);
    }
    this->sessionsCompleted++;
    wxSound::Play("../resources/sessioncomplete.mp3");
    system(cls.c_str());
    cout<<"Starting over in 5s...";
    this_thread::sleep_for(5s);
    system(cls.c_str());
    wxSound::Play("../resources/sessionstart.mp3");

}
}

void pomodoro::pauseSession() {
    this->pauseflag= !pauseflag;
}
void pomodoro::resetScreen(wxStaticText* text, wxGauge* gauge){
    wxGetApp().CallAfter([text,gauge]() {
        text->SetLabelText("Press start to initiate a session");
        gauge->SetValue(0);
    });
}

