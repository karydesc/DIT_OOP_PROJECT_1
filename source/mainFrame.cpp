//
// Created by Chris on 14/10/23.
//

#include "mainFrame.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "pomodoro.h"
#include <wx/string.h>
#include "myApp.h"
#include <mutex>

DECLARE_APP(myApp)
using namespace std;

enum IDs{
    startButtonID=2,
    pauseButtonID=3,
    statButtonID=4,
    cancelButtonID=5
};
wxBEGIN_EVENT_TABLE(mainFrame,wxFrame)
                EVT_BUTTON(startButtonID,mainFrame::onStartButtonClick)
                EVT_BUTTON(pauseButtonID,mainFrame::onPauseButtonClick)
                EVT_BUTTON(statButtonID,mainFrame::onStatButtonClick)
                EVT_BUTTON(cancelButtonID,mainFrame::onCancelButtonClick)

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

    wxStaticText *header = new wxStaticText(headerpanel, wxID_ANY, "Pomodoro GUI", wxPoint(50, 10),wxSize(200, 30)); //creating simple header

    timer = new wxStaticText(headerpanel, wxID_ANY, "Press start to initiate a session", wxPoint(160, 150), wxSize(200,30)); //Creating a text field were the running time will be displayed

    statButton = new wxButton(panel,statButtonID,"Get Statistics", wxPoint(500, 255), wxSize(100, 35));

    cancelButton = new wxButton(panel,cancelButtonID,"Cancel", wxPoint(35, 285), wxSize(100, 35));

    this->Bind(wxEVT_CLOSE_WINDOW, &mainFrame::OnClose, this);






    CreateStatusBar();
}
pomodoro* session = new pomodoro;

void mainFrame::onStartButtonClick(wxCommandEvent &evt) {

    if (!session->processing) {

        if (session->backgroundThread.joinable())//reset thread if it's still running
        {
            session->backgroundThread.join();
        }
        session->processing = true; //setting flags

        const auto f = [this]() {
            session->startSession(timeselect->GetValue(), breakselect->GetValue(), timer, gauge, session);
            wxGetApp().CallAfter([this]() {
                session->processing = false;
            });
        };
        session->backgroundThread = std::thread{f};
    }
}


void mainFrame::onPauseButtonClick(wxCommandEvent &evt) {
    session->pauseSession();
}

void mainFrame::onStatButtonClick(wxCommandEvent &evt) {
    session->getStatistics();
}
void mainFrame::onCancelButtonClick(wxCommandEvent &evt) {
    session->cancelSession(this->timer,this->gauge);
}


void mainFrame::OnClose(wxCloseEvent&e){
    session->quitRequested=true;

    if(session->processing)
    {
        if(session->backgroundThread.joinable()){ //check if thread is running
            session->quitRequested=true; //set quit flag to stop the timer in pomodoro.cpp
            session->backgroundThread.join(); // join with main thread
            this->Destroy(); //destroy window instance
        }
    }
    else
    {
        this->Destroy(); //if the timer isnt running destroy the window instance immediately
    }
}