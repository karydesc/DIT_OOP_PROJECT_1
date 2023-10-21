//
// Created by Chris on 14/10/23.
//

#ifndef DIT_OOP_PROJECT_1_MAINFRAME_H
#define DIT_OOP_PROJECT_1_MAINFRAME_H
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <thread>


//declare mainframe class, inherit from wxFrame
class mainFrame : public wxFrame {
public:
    mainFrame(const wxString& title); //declare constructor that takes a wxstring by reference for the title of the frame
private:
    wxStaticText *timer;
    wxSpinCtrl* timeselect;
    wxSpinCtrl* breakselect;
    wxGauge* gauge;
    wxButton* pauseButton;
    wxButton* startButton;
    wxPanel* headerpanel;
    wxPanel* panel;
    wxButton* statButton;
    wxButton* showstat;
    wxButton* cancelButton;
    void onStartButtonClick(wxCommandEvent& evt);
    void onPauseButtonClick(wxCommandEvent& evt);
    void onStatButtonClick(wxCommandEvent& evt);
    void onCancelButtonClick(wxCommandEvent& evt);
    void OnClose(wxCloseEvent &e);
    void onShowStatsClick(wxCommandEvent& evt);
    wxDECLARE_EVENT_TABLE();
};


#endif //DIT_OOP_PROJECT_1_MAINFRAME_H
