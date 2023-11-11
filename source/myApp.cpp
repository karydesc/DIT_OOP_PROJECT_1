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
    #include <windows.h>
    string clear ="cls";
#else
    #include<unistd.h>
    #include <termios.h>
    string cls ="clear";
#endif



string getch();

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
            system(cls.c_str()); //account for different shell commands, defined in line 11
            cout<<"Input username and then a password: ";
            cin>>user;
            pass=getch();

            if(!myDB->addUser(user,pass)) return false;
            
            break;
        case '2':
            system(cls.c_str());
            cout<<"Input username and then a password: ";
            cin>>user;
            pass=getch();
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

string getch() { // I copied this code from: https://dev.to/namantam1/how-to-take-hidden-password-from-terminal-in-cc-3ddd
    string ch;//but I understand how it works perfectly
    // struct to hold the terminal settings
    struct termios old_settings, new_settings;
    // take default setting in old_settings
    tcgetattr(STDIN_FILENO, &old_settings);
    // make of copy of it (Read my previous blog to know
    // more about how to copy struct)
    new_settings = old_settings;
    // change the settings for by disabling ECHO mode
    // read man page of termios.h for more settings info
    new_settings.c_lflag &= ~(ICANON | ECHO);
    // apply these new settings
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
    // now take the input in this mode
    cin>>ch;
    // reset back to default settings
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
    return ch;
}