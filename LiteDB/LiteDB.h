#ifndef SQLITEDB_H
#define SQLITEDB_H

#include <stdio.h>
#include <iostream>
#include <tuple>
#include <sqlite3.h>
using namespace std;
#include "../Model/PHIModel.h"
#include "../Model/representativeModel.h"

bool DBFunction();
bool closeDB(sqlite3 *db);
bool createTablePHI3(sqlite3 *db);
bool commitPHI(personalInfo &temp);
bool createTableRepresentative(sqlite3* DB);
bool commitRepresentativeModel(Representative &rep, int personID);



#endif
