//
// Created by Chris on 14/10/23.
//

#include "myApp.h"
#include "mainFrame.h"
#include <wx/wx.h>
#include "database.h"
#include <iostream>
//defining onInit method, it is the entry point of my application
using namespace std;
bool myApp::OnInit(){
    myDB = new database();
    char choice;
    string pass;
    cout<<"1: Add User"<<endl<<"2: Login"<<endl<<"Input: ";
    cin>>choice;
    if (choice=='1'){
        system("clear");
        cout<<"Input username and then a password: ";
        cin>>user;
        cin>>pass;
        myDB->addUser(user,pass);
    } else if (choice=='2'){
        cout<<"Input username and then a password: ";
        cin>>user;
        cin>>pass;
        if (!myDB->authUser(user,pass)){
            return false;
       }
   }else return false;
    mainFrame* MainFrame = new mainFrame("DIT-OOP-PROJECT_1-2708");//New instance of mainframe with title argument
    MainFrame->Show(true);//calling show method of the object as it is hidden by default
    MainFrame->SetClientSize(650,350);

    return true; //returning true tells wxwidgets that the program can resume
}
//have to tell wxwidgets which class represents my application, so I call this following method
wxIMPLEMENT_APP(myApp);