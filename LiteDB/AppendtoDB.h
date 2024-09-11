#ifndef APPENDTODB_H
#define APPENDTODB_H

#include <stdio.h>
#include <iostream>
#include <tuple>
#include <sqlite3.h>
using namespace std;
#include "../Model/PHIModel.h"
#include "../Model/representativeModel.h"

bool commitReptoDB(int personID, Representative rep);


#endif