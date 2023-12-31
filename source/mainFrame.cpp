//
// Created by Chris on 14/10/23.
//

#include "mainFrame.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "pomodoro.h"
#include <wx/string.h>
#include "myApp.h"
#include <string>
#include <wx/sound.h>

#ifdef _WIN32
string openshell ="";
#else
string openshell ="open";
#endif

DECLARE_APP(myApp)
using namespace std;

enum IDs{
    startButtonID=2,
    pauseButtonID=3,
    statButtonID=4,
    cancelButtonID=5,
    showstatID=6

};
wxBEGIN_EVENT_TABLE(mainFrame,wxFrame)
                EVT_BUTTON(startButtonID,mainFrame::onStartButtonClick)
                EVT_BUTTON(pauseButtonID,mainFrame::onPauseButtonClick)
                EVT_BUTTON(statButtonID,mainFrame::onStatButtonClick)
                EVT_BUTTON(cancelButtonID,mainFrame::onCancelButtonClick)
                EVT_BUTTON(showstatID,mainFrame::onShowStatsClick)

wxEND_EVENT_TABLE();


//constructor implementation
mainFrame::mainFrame(const wxString& title) : wxFrame(nullptr,wxID_ANY,title) { //calling the constructor of the base class

    panel = new wxPanel(this); //panel is needed to contain controls
    headerpanel = new wxPanel(panel);

    headerpanel->SetFont(this->GetFont().Scale(2.0));

    startButton = new wxButton(panel, startButtonID, "Start", wxPoint(35, 255), wxSize(100, 35));

    pauseButton = new wxButton(panel, pauseButtonID, "(un)/Pause", wxPoint(150, 255), wxSize(100, 35));

    gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(400, 10), wxSize(200, -1));

    timeselect = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(265, 262),wxSize(100, 20)); //this will be used to select times for pomodoro and break

    breakselect = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(380, 262), wxSize(100, 20));

    timeselect->SetValue(25); //Setting the default values as per Project instructions.

    breakselect->SetValue(5);

    header = new wxStaticText(headerpanel, wxID_ANY, "Pomodoro GUI", wxPoint(50, 10),wxSize(200, 30)); //creating simple header

    timer = new wxStaticText(headerpanel, wxID_ANY, "Press start to initiate a session", wxPoint(160, 150), wxSize(200,30)); //Creating a text field were the running time will be displayed

    statButton = new wxButton(panel,statButtonID,"Log Statistics", wxPoint(500, 255), wxSize(100, 35));

    cancelButton = new wxButton(panel,cancelButtonID,"Cancel", wxPoint(35, 285), wxSize(100, 35));

    showstat = new wxButton(panel,showstatID,"Open Logs file",wxPoint(500,285),wxSize(100,30));

    this->Bind(wxEVT_CLOSE_WINDOW, &mainFrame::OnClose, this);

}
pomodoro* session = new pomodoro;

void mainFrame::onStartButtonClick(wxCommandEvent &evt) {
    if (breakselect->GetValue()==0 || timeselect->GetValue()==0) return; //if either spincontrol is 0 the timer wont start
    if (!session->processing) { //only run if previous thread has finished work
        wxSound::Play("../resources/sessionstart.mp3");
        if (session->backgroundThread.joinable())//join thread with main thread
       {
            session->backgroundThread.join();
        }

        const auto f = [this]() {
            session->startSession(timeselect->GetValue(), breakselect->GetValue(), timer, gauge);
        };
        session->backgroundThread = std::thread{f};
    }
}


void mainFrame::onPauseButtonClick(wxCommandEvent &evt) {
    session->pauseSession();
}

void mainFrame::onStatButtonClick(wxCommandEvent &evt) {
    wxGetApp().GetDatabase()->storeStats(wxGetApp().getUser(),session); //all database operations are called through the myApp class,
    //because the initial instance of the database is started in the onInit() function and i couldnt  make it be accessible to the rest of the classes in any other way.


}
void mainFrame::onCancelButtonClick(wxCommandEvent &evt) {
    wxSound::Play("../resources/Cancel.wav"); //play sound
    if (session->processing) {
        session->cancelFlag = true; //set flags
    }
    session->resetScreen(this->timer, this->gauge);
}

    void mainFrame::OnClose(wxCloseEvent&e){
    session->quitRequested=true;
    if(session->processing)
    {
            session->backgroundThread.detach();
            delete session;
            delete wxGetApp().GetDatabase();
            this->Destroy(); //destroy window instance


    }
    else{
        if (session->backgroundThread.joinable()){
            session->backgroundThread.join();}
        delete wxGetApp().GetDatabase();
        delete session;
        this->Destroy(); //if the timer isn't running destroy the window instance immediately
    }

}

void mainFrame::onShowStatsClick(wxCommandEvent &evt) {
    string shell=openshell+" ../data/"+wxGetApp().getUser()+".txt";
    system(shell.c_str());
}