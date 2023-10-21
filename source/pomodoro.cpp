//
// Created by Chris on 14/10/23.
//


#include "pomodoro.h"
#include <iostream>
#include <fstream>
#include <wx/wx.h>
#include <wx/string.h>
#include <ctime>
#include <chrono>
#include "myApp.h"
#include <wx/sound.h>


using namespace std::chrono_literals;
using namespace std;
int secs;
int secondspassed;
wxDECLARE_APP(myApp);
void pomodoro::startSession(int workminutes,int breakminutes,wxStaticText* text,wxGauge* gauge,pomodoro* session) {
    session->processing =true;
    pauseflag=false;
    cancelFlag=false;

//restart pomodoro indefinitely
    while(true){
    secondspassed = 0;
        secs = workminutes * 60;
    for (int i = secs; i >= 0;) {
        if (this->cancelFlag) return;
        if (quitRequested) return; //handling window close/end thread
        if (!this->pauseflag) {

            session->WorkSeconds++;
            wxGetApp().CallAfter([this, i, text, gauge]() {
                text->SetLabelText(wxString::Format("Focus: %d:%02d", i / 60, i % 60)); //updating the timer
                gauge->SetRange(secs); //variable gauge range
                gauge->SetValue(secondspassed);
            });
            i--;

        }
        std::this_thread::sleep_for(1s); //timer tick
    }
    secondspassed = 0;
        secs = breakminutes * 60;
    for (int i = secs; i >= 0;) {
        if (this->cancelFlag) return;
        if (quitRequested) return;
        if(!this->pauseflag){
            wxGetApp().CallAfter([this, i, text, gauge]() {
                text->SetLabelText(wxString::Format("Break: %d:%02d", i / 60, i % 60));
                gauge->SetRange(secs);
                gauge->SetValue(secondspassed);
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
    wxGetApp().CallAfter([text,gauge,this]() {
        text->SetLabelText("Press start to initiate a session");
        gauge->SetValue(0);
    });
}
void pomodoro::logStatistics() {
    time_t now = time(nullptr); //getting current time and printing it on a txt file along with statistics
    char* data_time = ctime(&now);
    ofstream myFile("logs.txt",ios::app);
    myFile << data_time << "    Number of sessions:" << sessionsCompleted << "  Number of minutes worked: " << WorkSeconds/60 << endl;
    myFile.close();
}