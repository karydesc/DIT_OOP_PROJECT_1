//
// Created by Chris on 14/10/23.
//

#include "myApp.h"
#include "mainFrame.h"
#include <wx/wx.h>
#include "pomodoro.h"

//defining onInit method, it is the entry point of my application

bool myApp::OnInit(){
    mainFrame* MainFrame = new mainFrame("DIT-OOP-PROJECT_1-2708");//New instance of mainframe with title argument
    MainFrame->Show(true);//calling show method of the object as it is hidden by default
    MainFrame->Center(true);
    MainFrame->SetClientSize(800,600);


    return true; //returning true tells wxwidgets that the program can resume
}
//have to tell wxwidgets which class represents my application, so I call this following method
wxIMPLEMENT_APP(myApp);