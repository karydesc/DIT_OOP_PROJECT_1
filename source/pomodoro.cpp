//
// Created by Chris on 14/10/23.
//

#include "pomodoro.h"
#include <iostream>
#include <wx/wx.h>
#include <unistd.h>
#include <wx/string.h>
#include <wx/string.h>


using namespace std;
int seconds;
int j=0;
int secondspassed;
void pomodoro::startSession(int workminutes,int breakminutes,wxStaticText* text,wxGauge* gauge,pomodoro* session) {
    start:
    cancelFlag=false;
    secondspassed=0;
    seconds=workminutes*60;
    for (int i=seconds;i>=0;i--){
        while(pauseflag){
            if (this->cancelFlag){
                text->SetLabelText("Press start to initiate a session");
                return;}
            wxYield();
        }
        j=0;
        while(j<=100){ //Instead of using sleep(1000) which pauses the main thread for a whole second (which means the UI lags) I decided to divide the time tick into 100*10ms parts, in each of which the ui is updated.
            //this is done to avoid using multithreading because I dont know how to do it and it makes me want to cry
            if (this->cancelFlag){
                text->SetLabelText("Press start to initiate a session");
                return;}
            wxYield();
            usleep(10000);
            j++;

        }
        secondspassed++;
        session->totalWorkTime++;
        wxYield();
        text->SetLabelText(wxString::Format("Focus: %d:%02d",i/60,i%60)); //updating the timer
        gauge->SetRange(seconds); //variable gauge range
        gauge->SetValue(secondspassed);
    }
    secondspassed=0;
    seconds=breakminutes*60;
    for(int k=seconds;k>=0;k--) {

        seconds=breakminutes*60;
        while(pauseflag){
            wxYield();
            if (this->cancelFlag){
                text->SetLabelText("Press start to initiate a session");
                return;}
        }
        j=0;
        while(j<=100){ //Instead of using sleep(1000) which pauses the main thread for a whole second (which means the UI lags) I decided to divide the time tick into 100*10ms parts, in each of which the ui is updated.
            //this is done to avoid using multithreading because I dont know how to do it and it makes me want to cry
            wxYield();
            usleep(10000);
            j++;
            if (this->cancelFlag){
                text->SetLabelText("Press start to initiate a session");
                return;}
        }
        secondspassed++;
        session->totalWorkTime++;
        wxYield();
        text->SetLabelText(wxString::Format("Break: %d:%02d",k/60,k%60)); //updating the timer
        gauge->SetRange(seconds); //variable gauge range
        gauge->SetValue(secondspassed);
    }
    session->sessionsCompleted++;
    goto start;

}
void pomodoro::pauseSession() {
    pauseflag=!pauseflag;
}

void pomodoro::getStatistics() {
    wxLogStatus(wxString::Format("Total Sessions: %d || Total Minutes: %d",this->sessionsCompleted,this->totalWorkTime/60));
}