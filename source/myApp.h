//
// Created by Chris on 14/10/23.
//

#ifndef DIT_OOP_PROJECT_1_MYAPP_H
#define DIT_OOP_PROJECT_1_MYAPP_H
#include <wx/wx.h>
//myApp class needed to represent the application itself
class myApp : public wxApp{ //inheriting from wxApp class
    public:
        virtual bool OnInit();
};


#endif //DIT_OOP_PROJECT_1_MYAPP_H
