//
// Created by Chris on 14/10/23.
//

#ifndef DIT_OOP_PROJECT_1_MYAPP_H
#define DIT_OOP_PROJECT_1_MYAPP_H
#include <wx/wx.h>
#include "database.h"
#include <string>
//myApp class needed to represent the application itself
class myApp : public wxApp{ //inheriting from wxApp class
    public:
        virtual bool OnInit();
        database* GetDatabase() const { return myDB; }
        string getUser() const {return user;}

    private:
        string user;
        database* myDB;
};


#endif //DIT_OOP_PROJECT_1_MYAPP_H
