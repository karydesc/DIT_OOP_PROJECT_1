//
// Created by Chris on 14/10/23.
//

#include "mainFrame.h"
#include <wx/wx.h>
//constructor implementation
mainFrame::mainFrame(const wxString& title) : wxFrame(nullptr,wxID_ANY,title){ //calling the constructor of the base class
    wxPanel* panel = new wxPanel(this); //panel is needed to contain any controls
    wxButton* button = new wxButton(panel,wxID_ANY,"Start",wxPoint(150,50),wxSize(100,35));
    wxCheckBox* checkbox = new wxCheckBox(panel,wxID_ANY,"CheckBox",wxPoint(100,145),wxSize(100,35));
    wxGauge*gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint (500, 255), wxSize(200, -1));
    gauge -> SetValue(50);
}

//in the future must use spinctr because it will be a perfect slector for the timer (it offers value checking natively