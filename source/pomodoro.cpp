//
// Created by Chris on 14/10/23.
//

#include "pomodoro.h"
#include <iostream>
#include <wx/wx.h>
#include <unistd.h>
#include <wx/string.h>
#include <thread>
#include "myApp.h"
#include <mutex>
#include <condition_variable>


using namespace std;
int seconds;
int j=0;
int secondspassed;
wxDECLARE_APP(myApp);
void pomodoro::startSession(int workminutes,int breakminutes,wxStaticText* text,wxGauge* gauge,pomodoro* session) {
    session->processing =true;
    pauseflag=false;
    cancelFlag=false;

    while(true){
    secondspassed = 0;
    seconds = workminutes * 60;
    for (int i = seconds; i >= 0;) {
        if (this->cancelFlag) return;

        if(!this->pauseflag){
            if (quitRequested) return; //handling window close/end thread

            wxGetApp().CallAfter([this, i, text, gauge]() {
                text->SetLabelText(wxString::Format("Focus: %d:%02d", i / 60, i % 60)); //updating the timer
                gauge->SetRange(seconds); //variable gauge range
                gauge->SetValue(secondspassed);
            });
            i--;
            sleep(1);
        }

    }
    secondspassed = 0;
    seconds = breakminutes * 60;
    for (int i = seconds; i >= 0;) {
        if (this->cancelFlag) return;
        if(!this->pauseflag){
            if (quitRequested) return;
            // Wait until the flag changes (unpaused)



            session->totalWorkTime++;



            wxGetApp().CallAfter([this, i, text, gauge]() {
                text->SetLabelText(wxString::Format("Break: %d:%02d", i / 60, i % 60)); //updating the timer
                gauge->SetRange(seconds); //variable gauge range
                gauge->SetValue(secondspassed);
            });
            i--;
            sleep(1);
        }
    }
    session->sessionsCompleted++;
}
//restart pomodoro infinitely
}

void pomodoro::pauseSession() {
    this->pauseflag= !pauseflag;
}
void pomodoro::resetScreen(wxStaticText* text, wxGauge* gauge){
    wxGetApp().CallAfter([text,gauge,this]() {
        text->SetLabelText("Press start to initiate a session");
        gauge->SetValue(0);
    });
}
void pomodoro::getStatistics() {
    return;
}