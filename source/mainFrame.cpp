//
// Created by Chris on 14/10/23.
//

#include "mainFrame.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "pomodoro.h"
#include <unistd.h>
//constructor implementation
mainFrame::mainFrame(const wxString& title) : wxFrame(nullptr,wxID_ANY,title){ //calling the constructor of the base class
    wxPanel* headerpanel =new wxPanel(this);
    headerpanel->SetFont(this->GetFont().Scale(2.0));
    wxPanel* panel = new wxPanel(this); //panel is needed to contain controls
    wxButton* startbutton = new wxButton(panel,wxID_ANY,"Start",wxPoint(35,255),wxSize(100,35));
    wxButton* pausebutton = new wxButton(panel,wxID_ANY,"Pause",wxPoint(150,255),wxSize(100,35));
    wxGauge*gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint (550, 263), wxSize(200, -1));
    wxSpinCtrl* timeselect = new wxSpinCtrl(panel,wxID_ANY,"",wxPoint(265,263),wxSize(100,20)); //this will be used to select times for pomodoro and break
    wxSpinCtrl* sessionselect = new wxSpinCtrl(panel,wxID_ANY,"",wxPoint(380,263),wxSize(100,20));
    timeselect->SetValue(25); //Setting the default values as per Project instructions.
    sessionselect->SetValue(5);
    wxStaticText* header = new wxStaticText(headerpanel,wxID_ANY,"Pomodoro GUI",wxPoint(50,10),wxSize(200,30)); //creating simple header
    wxStaticText* Timer = new wxStaticText(headerpanel,wxID_ANY,"Timer text here",wxPoint(160,150),wxSize(200,30)); //Creating a text field were the running time will be displayed
    //pomodoro::startSession(5,Timer);


}

