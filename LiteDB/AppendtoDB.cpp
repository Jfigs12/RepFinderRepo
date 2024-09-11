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
#include "../Model/representativeModel.h"


bool commitReptoDB(int personID, Representative rep){
    //commit representative to database in corralation to PHI database
    bool temp = commitRepresentativeModel(rep, personID);
    if(temp != true){
        cout << "Error commiting representative to database" << endl;
        return false;
    }

    return true;
}
