//
// Created by Chris on 14/10/23.
//

#include "myApp.h"
#include "mainFrame.h"
#include <wx/wx.h>
#include "database.h"
#include <iostream>
#include <string>
#ifdef _WIN32
    string clear ="cls";
#else
    string clear ="clear";
#endif

//defining onInit method, it is the entry point of my application
using namespace std;
bool myApp::OnInit(){
    myDB = new database(); //create a new database object
    char choice; //var to store choice
    string pass; //very insecure way of storing passwords but no security is truly needed for this program
    cout<<"1: Add User"<<endl<<"2: Login"<<endl<<"Input: ";
    cin>>choice;
    switch (choice){
        case '1':
            system(clear.c_str()); //account for different shell commands, defined in line 11
            cout<<"Input username and then a password: ";
            cin>>user;
            cin>>pass;
            if(!myDB->addUser(user,pass)) return false;
            
            break;
        case '2':
            system(clear.c_str());
            cout<<"Input username and then a password: ";
            cin>>user;
            cin>>pass;
             if (!myDB->authUser(user,pass)){
                cout<<endl<<"Aborting...";
                return false;
              }  else cout<<endl<<"Started GUI...";
             break;
        default:
            cout<< "Invalid input";
            return false;
    }
    mainFrame* MainFrame = new mainFrame("DIT-OOP-PROJECT_1-2708");//New instance of mainframe with title argument
    MainFrame->Show(true);//calling show method of the object as it is hidden by default
    MainFrame->SetClientSize(650,350);

    return true; //returning true tells wxwidgets that the program can resume
}
//have to tell wxwidgets which class represents my application, so I call this following macro/method
wxIMPLEMENT_APP(myApp);