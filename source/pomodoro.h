//
// Created by Chris on 14/10/23.
//

#ifndef DIT_OOP_PROJECT_1_POMODORO_H
#define DIT_OOP_PROJECT_1_POMODORO_H
#include <wx/wx.h>
#include <thread>

class pomodoro {
private:
    bool pauseflag=false;
    int lastCurrentSessionMinutes=0;
    int lastCurrentSessionCount=0;
    int WorkSeconds;
    int sessionsCompleted=0;
public:
    bool processing=false;
    bool quitRequested=false;
    std::thread backgroundThread;
    bool cancelFlag=false;


    void startSession(int workmins,int breakmins,wxStaticText*,wxGauge*);
    void pauseSession();
    void resetScreen(wxStaticText *text, wxGauge *gauge);

    friend class database;
};


#endif //DIT_OOP_PROJECT_1_POMODORO_H
