//
// Created by Chris on 30/10/23.
//

#include "database.h"
#include <iostream>
#include "sqlite3.h"
#include <string>
#include <sstream>
#include "myApp.h"
#include <fstream>
#include <ctime>
using namespace std;


wxDECLARE_APP(myApp);
database::database() { //constructor that is called in the onInit method
    sqlite3_open("file.db", &db);
    string query = "CREATE TABLE IF NOT EXISTS database(user TEXT, pass TEXT,workmins INT,sessionsCompleted INT);"; //create a table if it doesnt exist with 4 columns: user,pass,workmins,sessionscompleted
    sqlite3_exec(db, query.c_str(), NULL, NULL, &error); //execture the query
    cout<<"Connected to database successfully!"<<endl;
}


void database::addUser(const string& user,  const string& pass) {
    //query with placeholders for the parameters
    const char* insertDataQuery = "INSERT INTO database(user, pass, workmins, sessionsCompleted) VALUES (?, ?, ?, ?);";

    rc = sqlite3_prepare_v2(db, insertDataQuery, -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        cout << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return;
    }


    sqlite3_bind_text(stmt, 1, user.c_str(), -1, SQLITE_STATIC); //bind values into the placeholders, I use stringstreams later
    sqlite3_bind_text(stmt, 2, pass.c_str(), -1, SQLITE_STATIC);


    rc = sqlite3_step(stmt); //execute the command

    if (rc != SQLITE_DONE) { //error handling
        cout << "Error executing statement: " << sqlite3_errmsg(db) << endl;
    }else cout<<"Data inserted successfully"<<endl;

    sqlite3_finalize(stmt); //finalize stmt
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

void database::storeStats(const string& user,pomodoro* session) {
    stringstream query; //create a query variable
    query << "SELECT workmins, sessionsCompleted FROM database WHERE user= '" << user << "';"; //build the query
    rc = sqlite3_prepare_v2(db, query.str().c_str(), -1, &stmt, 0); //prepare statement

    if (rc != SQLITE_OK) { //handle errors
        cout << "Error preparing SELECT statement: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return;
    }

    rc = sqlite3_step(stmt);//execute statement
    int prevWM=0; //initialize variables here, so they don't go out of scope inside the if statement
    int prevSC=0;
    if (rc == SQLITE_ROW) {
         prevWM = sqlite3_column_int(stmt, 0); //extract previous values from database
         prevSC = sqlite3_column_int(stmt, 1);

        cout << "Previous workmins: " << prevWM << endl; //print old values from database
        cout << "Previous sessions completed: " << prevSC << endl;

        sqlite3_finalize(stmt); // Reset the statement for reuse
        query.str("");       // Clear the stringstream

        query << "UPDATE database SET workmins = ?, sessionsCompleted = ? WHERE user= '" << user << "';";
        rc = sqlite3_prepare_v2(db, query.str().c_str(), -1, &stmt, 0); //executing stmt

        if (rc != SQLITE_OK) { //error handling
            cout << "Error preparing UPDATE statement: " << sqlite3_errmsg(db) << endl;
            sqlite3_close(db);
            return;
        }

        sqlite3_bind_int(stmt, 1, prevWM + (session->WorkSeconds/60 - session-> lastCurrentSessionMinutes)); //bind for execution
        sqlite3_bind_int(stmt, 2, prevSC + (session->sessionsCompleted - session-> lastCurrentSessionCount));//I remove from the result the time and session count of the
        session-> lastCurrentSessionMinutes=session->WorkSeconds / 60 ;// already existing instance to prevent for example: pressing log multiple times
        session->lastCurrentSessionCount=session->sessionsCompleted;//and adding the same minutes worked over and over again
        rc = sqlite3_step(stmt); //exectute statement

        if (rc != SQLITE_DONE) { //handle error
            cout << "Error executing UPDATE statement: " << sqlite3_errmsg(db) << endl;
            sqlite3_close(db);
            return;
        }
        cout << "Update successful!" << endl;
    }

    sqlite3_reset(stmt); // Finalize the statement

    time_t now = time(nullptr); //getting current time and printing it on a txt file along with statistics
    char* data_time = ctime(&now);
    string filename = "./data/"+user+".txt"; //create a file for each user that will store the statistics for viewing.

    ofstream myFile(filename,ios::trunc);
    myFile << "Last Update: "<< data_time << " USER: " << wxGetApp().getUser() << "   Number of sessions:" << prevSC + ((session->sessionsCompleted - session-> lastCurrentSessionCount)) << "  Number of minutes worked: " << prevWM + (session->WorkSeconds/60 - session-> lastCurrentSessionMinutes) << endl;
    myFile.close(); //write to file, username is a member of the myApp class, so it can be accessed globally.

}
void database::close(){
    sqlite3_finalize(stmt); //close db and finalize stmt
    sqlite3_close(db);
}


