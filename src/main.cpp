#include <stdio.h>
#include <iostream>
#include <tuple>
#include <sqlite3.h>
using namespace std;
#include "../Model/PHIModel.h"
#include "../LiteDB/LiteDB.h"
#include "../IntakeParsing/intake.h"
#include "../LiteDB/AppendtoDB.h"


bool setPHIfromMain(personalInfo &temp,string name, string address, bool includeOffices, int phoneNumber,int PersonalID){
    temp.setPHI(name, address, includeOffices, phoneNumber, PersonalID);
    return true;
}
void checkSetDB(){
    bool test = DBFunction();
    if(test){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    
}




int main(){
    printf("test1");
    personalInfo p1;
    Representative rep1;
    setPHIfromMain(p1, "John Doe", "1234 Elm St", true, 1234567890, 1);
    checkSetDB();
    bool test = commitPHI(p1);
    printf("test2");
    commitReptoDB(3, rep1);

    return 0;
    

    
    
}


