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
//#include <catch2/catch.hpp>


using namespace std::chrono_literals;
using namespace std;
wxDECLARE_APP(myApp);
void pomodoro::startSession(int workminutes,int breakminutes,wxStaticText* text,wxGauge* gauge,pomodoro* session) {
    session->processing =true;
    int secs;
    pauseflag=false;
    cancelFlag=false;

//restart pomodoro indefinitely
    while(true){
        secs = workminutes * 60;
        wxGetApp().CallAfter([gauge,secs](){
            gauge->SetRange(secs);
            cout<<gauge->GetValue()<<endl;
            cout<<gauge->GetRange()<<endl;
        });
    for (int i = secs; i >= 0;) {
        if (this->cancelFlag) return;
        if (quitRequested) return; //handling window close/end thread
        if (!this->pauseflag) {
            session->WorkSeconds++;
            wxGetApp().CallAfter([i, text, gauge]() {
                text->SetLabelText(wxString::Format("Focus: %d:%02d", i / 60, i % 60)); //updating the timer
                gauge->SetValue(i);
            });
            i--;
        }
        std::this_thread::sleep_for(1s); //timer tick
    }
    secs = breakminutes * 60;
    wxGetApp().CallAfter([gauge,secs](){
            gauge->SetRange(secs);
    });
    for (int i = secs; i >= 0;) {
        if (this->cancelFlag) return;
        if (quitRequested) return;
        if(!this->pauseflag){
            wxGetApp().CallAfter([i, text, gauge]() {
                text->SetLabelText(wxString::Format("Break: %d:%02d", i / 60, i % 60));
                gauge->SetValue(i);
            });
            i--;

        }
        std::this_thread::sleep_for(1s);
    }
    session->sessionsCompleted++;
    wxSound::Play("./resources/SessionComplete.mp3");
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
