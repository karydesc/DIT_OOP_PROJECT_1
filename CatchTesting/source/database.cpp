//
// Created by Chris on 30/10/23.
//

#include "database.h"
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <sstream>
using namespace std;


database::database() { //constructor that is called in the onInit method

    sqlite3_open("./file.db", &db);
    string query = "CREATE TABLE IF NOT EXISTS database(user TEXT, pass TEXT,workmins INT,sessionsCompleted INT);"; //create a table if it doesnt exist with 4 columns: user,pass,workmins,sessionscompleted
    sqlite3_exec(db, query.c_str(), NULL, NULL, &error); //execture the query
    cout<<"Connected to database successfully!"<<endl;

}


bool database::addUser(const string& user,  const string& pass) {
    stringstream query; //create a stringstream in which I will build the query
    query << "SELECT pass FROM database WHERE user = '" << user << "';"; //grab the row in which the user is matched, to see if user already exists
    rc = sqlite3_prepare_v2(db, query.str().c_str(), -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        cout << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return false;
    }
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        cout << "User already exists!..."<<endl<<"But authentication proceeds with found username: "<<endl;
        return authUser(user,pass);
        
    }


    //query with placeholders for the parameters, i would change it to use stringstream, but i am bored and it works just fine.
    const char* insertDataQuery = "INSERT INTO database(user, pass, workmins, sessionsCompleted) VALUES (?, ?, ?, ?);";

    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        cout << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return false;
    }

    sqlite3_bind_text(stmt, 1, user.c_str(), -1, SQLITE_STATIC); //bind values into the placeholders, I use stringstreams later
    sqlite3_bind_text(stmt, 2, pass.c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt); //execute the command

    if (rc != SQLITE_DONE) { //error handling
        cout << "Error executing statement: " << sqlite3_errmsg(db) << endl;
    }else cout<<"User inserted successfully"<<endl;

    sqlite3_finalize(stmt); //finalize stmt
    return true;
}




bool database::authUser(const string & user, const std::string & pass) {
    stringstream query; //create a stringstream in which I will build the query
    query << "SELECT pass FROM database WHERE user = '" << user << "';"; //grab the row in which the username is matched, get the password
    rc = sqlite3_prepare_v2(db, query.str().c_str(), -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        cout << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return false;
    }
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        // User found, get the username and password
        const char* storedPass = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)); //extract the password and cast it as a const char* for storing
        // Compare passwords
        if (pass == storedPass) { //handle cases
            cout << "Authentication successful! User: " << user;
            sqlite3_finalize(stmt);
            return true;
        } else {
            cout << "Authentication failed: Incorrect password!" << endl;
            return false;
        }
    } else {
        cout << "Authentication failed: User not found!" << endl;

    }

    sqlite3_finalize(stmt); //finalize stmt
    return false;

}

void database::close(){
    sqlite3_finalize(stmt); //close db and finalize stmt
    sqlite3_close(db);
}


