//
// Created by Chris on 14/10/23.
//

#include "pomodoro.h"
#include <iostream>
#include <unistd.h>

using namespace std;
int i=0;
void pomodoro::startSession(int mins) {
    mins=mins*60;
    while (i<=mins){
        sleep(1);
        cout<<"\t\r" <<  i++ << flush;

    }
    cout << "\t\rFinished!"<<flush;
    sleep(1);
}
