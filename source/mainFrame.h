//
// Created by Chris on 14/10/23.
//

#ifndef DIT_OOP_PROJECT_1_MAINFRAME_H
#define DIT_OOP_PROJECT_1_MAINFRAME_H
#include <wx/wx.h>

//declare mainframe class, inherit from wxFrame
class mainFrame : public wxFrame {
public:
    mainFrame(const wxString& title); //declare constructor that takes a wxstring by reference for the title of the frame
};


#endif //DIT_OOP_PROJECT_1_MAINFRAME_H