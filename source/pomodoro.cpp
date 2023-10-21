//
// Created by Chris on 14/10/23.
//

#include "pomodoro.h"
#include <iostream>
#include <fstream>
#include <wx/wx.h>
#include <unistd.h>
#include <wx/string.h>
#include <ctime>
#include "myApp.h"



using namespace std;
int seconds;
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
        if (quitRequested) return; //handling window close/end thread
        if(!this->pauseflag){

            session->WorkSeconds++;
            wxGetApp().CallAfter([this, i, text, gauge]() {
                text->SetLabelText(wxString::Format("Focus: %d:%02d", i / 60, i % 60)); //updating the timer
                gauge->SetRange(seconds); //variable gauge range
                gauge->SetValue(secondspassed);
            });
            i--;

        }
        sleep(1);
    }
    secondspassed = 0;
    seconds = breakminutes * 60;
    for (int i = seconds; i >= 0;) {
        if (this->cancelFlag) return;
        if (quitRequested) return;
        if(!this->pauseflag){
            wxGetApp().CallAfter([this, i, text, gauge]() {
                text->SetLabelText(wxString::Format("Break: %d:%02d", i / 60, i % 60)); //updating the timer
                gauge->SetRange(seconds); //variable gauge range
                gauge->SetValue(secondspassed);
            });
            i--;

        }
        sleep(1);
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
void pomodoro::logStatistics() {
    time_t now = time(nullptr);
    char* data_time = ctime(&now);
    ofstream myFile("logs.txt",ios::app);
    myFile << data_time << "    Number of sessions:" << sessionsCompleted << "  Number of minutes worked: " << WorkSeconds/60 << endl;
    myFile.close();
}