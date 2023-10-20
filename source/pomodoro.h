//
// Created by Chris on 14/10/23.
//

#ifndef DIT_OOP_PROJECT_1_POMODORO_H
#define DIT_OOP_PROJECT_1_POMODORO_H
#include <wx/wx.h>
#include <thread>

class pomodoro {
public:
     void startSession(int,int,wxStaticText*,wxGauge*,pomodoro*);
     void pauseSession();
     void getStatistics();
     void resetScreen(wxStaticText *text, wxGauge *gauge);
     bool quitRequested=false;
     bool processing=false;
     std::thread backgroundThread;
     bool pauseflag=false;
     bool cancelFlag=false;




private:
int totalWorkTime;
int sessionsCompleted;
};


#endif //DIT_OOP_PROJECT_1_POMODORO_H
