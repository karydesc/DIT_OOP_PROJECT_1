//
// Created by Chris on 14/10/23.
//

#include "pomodoro.h"
#include <iostream>
#include <unistd.h>
#include <wx/wx.h>

using namespace std;
int i=0;
void pomodoro::startSession(int mins,wxStaticText* text) {
    //mins=mins*60;
    while (i<=mins){
        sleep(1);
        text->SetLabelText(to_string(i++));

    }
    sleep(1);
}
