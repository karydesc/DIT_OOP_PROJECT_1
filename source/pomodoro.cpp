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
    std::mutex mtx;
    std::condition_variable pauseCondition;  // Condition variable for signaling
    std::unique_lock<std::mutex> lock(mtx);
    while(true){
    secondspassed = 0;
    seconds = workminutes * 60;
    for (int i = seconds; i >= 0; i--) {
        if (quitRequested) return; //handling window close

        pauseCondition.wait(lock, [&]() { return !session->pauseflag; });

        if (this->cancelFlag) {
            cancelSession(text, gauge);
            return;

        }
        sleep(1);
        secondspassed++;
        session->totalWorkTime++;
        wxGetApp().CallAfter([this, i, text, gauge]() {
            text->SetLabelText(wxString::Format("Focus: %d:%02d", i / 60, i % 60)); //updating the timer
            gauge->SetRange(seconds); //variable gauge range
            gauge->SetValue(secondspassed);
        });


    }
    secondspassed = 0;
    seconds = breakminutes * 60;
    for (int i = seconds; i >= 0; i--) {

        if (quitRequested) return;
            // Wait until the flag changes (unpaused)
            pauseCondition.wait(lock, [&]() { return !this->pauseflag; });

        sleep(1);
        secondspassed++;
        session->totalWorkTime++;
        if (this->cancelFlag) {
            return;

        }

        wxGetApp().CallAfter([this, i, text, gauge]() {
            text->SetLabelText(wxString::Format("Break: %d:%02d", i / 60, i % 60)); //updating the timer
            gauge->SetRange(seconds); //variable gauge range
            gauge->SetValue(secondspassed);
        });
    }
    session->sessionsCompleted++;
}

}

void pomodoro::pauseSession() {
    this->pauseflag= !pauseflag;
}
void pomodoro::cancelSession(wxStaticText* text,wxGauge* gauge){
    wxGetApp().CallAfter([text,gauge,this]() {
        text->SetLabelText("Press start to initiate a session");
        gauge->SetValue(0);
        this->cancelFlag=true;
        this->processing=false;
    });
}
void pomodoro::getStatistics() {
    return;
}