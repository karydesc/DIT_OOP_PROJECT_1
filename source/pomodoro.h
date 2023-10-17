//
// Created by Chris on 14/10/23.
//

#ifndef DIT_OOP_PROJECT_1_POMODORO_H
#define DIT_OOP_PROJECT_1_POMODORO_H
#include <wx/wx.h>

class pomodoro {
public:
     void startSession(int,int,wxStaticText*,wxGauge*,pomodoro*);
     void pauseSession();
     void getStatistics();
     void cancelSession(wxStaticText*,wxGauge*);

private:
int totalWorkTime;
bool cancelFlag=false;
int sessionsCompleted;
bool pauseflag=false;
};


#endif //DIT_OOP_PROJECT_1_POMODORO_H
