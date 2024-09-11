#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <iostream>
#include <tuple>
#include <sqlite3.h>
using namespace std;
#include "../Model/PHIModel.h"
#include "../LiteDB/LiteDB.h"
#include "../IntakeParsing/intake.h"


bool setPHIfromMain(personalInfo &temp,string name, string address, bool includeOffices, int phoneNumber,int PersonalID);


#endif