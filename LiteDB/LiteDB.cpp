#include <stdio.h>
#include <iostream>
#include <tuple>
#include <sqlite3.h>
using namespace std;
#include "../Model/PHIModel.h"
#include "../Model/representativeModel.h"
#include "../Model/representativeModel.h"

sqlite3* temp;
bool createTablePHI3(sqlite3* DB);
bool closeDB(sqlite3* DB);
bool commitPHI(personalInfo &temp);
bool createTableRepresentative(sqlite3* DB);
bool commitRepresentativeModel(Representative rep);
bool joinTables();



//initate the database connection/create the data base
bool DBFunction(){
    sqlite3* DB; // Declare a pointer to a SQLite database
    int exit = sqlite3_open("test.db", &DB); // Open a database connection

    if (exit) {
        cerr << "Error open DB " << sqlite3_errmsg(DB) << endl; 
        temp = DB; 
        return false;
    }
    else {
        cout << "Opened Database Successfully!" << endl;
        bool tableStatsPHI = createTablePHI3(DB);
        bool tableStatsRep = createTableRepresentative(DB);
        temp = DB; 
        bool tablejoin = joinTables();
        
       

    }
    
    return true;
    
}

//create the tables in the database

bool createTablePHI3(sqlite3* DB){
    string sql = "CREATE TABLE PHI("
                 "ID INT PRIMARY KEY     NOT NULL,"
                 "NAME           TEXT    NOT NULL,"
                 "ADDRESS        TEXT    NOT NULL,"
                 "INCLUDEOFFICES INT     NOT NULL,"
                 "PHONENUMBER    INT     NOT NULL);";
    int plsdnterror = 0;
    plsdnterror = sqlite3_exec(DB, sql.c_str(), NULL, 0, NULL); 
    if (plsdnterror != SQLITE_OK) {
        cerr << "Error W/ Table PHI" << endl; 
        sqlite3_close(DB); 
        return false;
    }
    else {
        cout << "Table created Successfully" << endl; 
    }
    return true;
}

bool closeDB(sqlite3* DB){
    sqlite3_close(DB); 
    return true;
}


bool createTableRepresentative(sqlite3* DB){
    string sql = "CREATE TABLE Representative("
                 "ID INT PRIMARY KEY     NOT NULL,"
                 "NAME           TEXT    NOT NULL,"
                 "ADDRESS        TEXT    NOT NULL,"
                 "PHONENUMBER    INT     NOT NULL);";
    int plsdnterror = 0;
    plsdnterror = sqlite3_exec(DB, sql.c_str(), NULL, 0, NULL); 
    if (plsdnterror != SQLITE_OK) {
        cerr << "Error W/ Table Representative" << endl; 
        sqlite3_close(DB); 
        return false;
    }
    else {
        cout << "Table created Successfully" << endl; 
    }
    return true;
}


//commit the personalInfo object to the database as well as the Representative object
bool commitPHI(personalInfo &PHI){
    string sql = "INSERT INTO PHI (ID, NAME, ADDRESS, INCLUDEOFFICES, PHONENUMBER) VALUES (?,?,?,?,?)";
    sqlite3_stmt* stmt; 
    int plsdnterror = sqlite3_prepare(temp, sql.c_str(), -1, &stmt, NULL); 
    if (plsdnterror != SQLITE_OK) {
        cerr << "Error W/ Table PHI" << endl; 
        sqlite3_close(temp); 
        return false;
    }
    sqlite3_bind_int(stmt, 1, PHI.getID());
    sqlite3_bind_text(stmt, 2, PHI.getName().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, PHI.getAddress().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, PHI.includeOffices);
    sqlite3_bind_int(stmt, 5, PHI.getPhoneNumber());
    plsdnterror = sqlite3_step(stmt); 
    if (plsdnterror != SQLITE_DONE) {
        cerr << "Error W/ Table PHI" << endl; 
        sqlite3_close(temp); 
        return false;
    }
    sqlite3_finalize(stmt); 
    return true;
}

bool commitRepresentativeModel(Representative rep, int personID){
    string sql = "INSERT INTO Representative (ID, NAME, ADDRESS, PHONENUMBER) VALUES (?,?,?,?)";
    sqlite3_stmt* stmt; 
    int plsdnterror = sqlite3_prepare(temp, sql.c_str(), -1, &stmt, NULL); 
    if (plsdnterror != SQLITE_OK) {
        cerr << "Error W/ Table Representative" << endl; 
        sqlite3_close(temp); 
        return false;
    }
    sqlite3_bind_int(stmt, 1, rep.getDistrictID());
    sqlite3_bind_text(stmt, 2, rep.getRepresentativeName().c_str(), -1, SQLITE_STATIC); // Line 97: Bind the representative name to the prepared statement
    sqlite3_bind_int(stmt, 3, personID);
    sqlite3_bind_text(stmt, 3, rep.getParty().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, rep.getDOI());
    plsdnterror = sqlite3_step(stmt); 
    if (plsdnterror != SQLITE_DONE) {
        cerr << "Error W/ Table Representative" << endl; 
        sqlite3_close(temp); 
        return false;
    }
    sqlite3_finalize(stmt); 
    return true;
}

//join the two tables with the PHI table being able to access the Representative table but not the other way around
bool joinTables(){
    string sqlCMD = "SELECT * FROM PHI JOIN Representative ON PHI.ID = Representative.ID";
    sqlite3_stmt* stmt; 
    int plsdnterror = sqlite3_prepare(temp, sqlCMD.c_str(), -1, &stmt, NULL); 
    if (plsdnterror != SQLITE_OK) {
        cerr << "Error W/ Table PHI" << endl; 
        sqlite3_close(temp); 
        return false;
    }
    plsdnterror = sqlite3_step(stmt); 
    if (plsdnterror != SQLITE_DONE) {
        cerr << "Error W/ Table PHI" << endl; 
        sqlite3_close(temp); 
        return false;
    }
    sqlite3_finalize(stmt); 
    return true;
}



