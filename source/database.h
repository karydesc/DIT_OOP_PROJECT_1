//
// Created by Chris on 30/10/23.
//

#ifndef DIT_OOP_PROJECT_1_DATABASE_H
#define DIT_OOP_PROJECT_1_DATABASE_H
#include <string>
#include <sqlite3.h>
#include "pomodoro.h"
using namespace std;
class database {
public:
    void addUser(const string&, const string&);
    database();
    bool authUser(const string&,const string&);
    void close();
    void storeStats(const string&,pomodoro*);
private:
    sqlite3* db;
    int rc;
    char* error;
    sqlite3_stmt* stmt;
};
#endif //DIT_OOP_PROJECT_1_DATABASE_H
