#ifndef INTAKE_H
#define INTAKE_H

#include <stdio.h>
#include <iostream>
#include <tuple>
#include <sqlite3.h>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
#include "../Model/PHIModel.h"
#include "../LiteDB/LiteDB.h"
#include "../src/main.h"

bool intakeCSV(string fileName);




#endif