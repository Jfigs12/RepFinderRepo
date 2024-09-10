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



// Eventually Encapsulate this into a while loop to check every 5 values,
//it restarts the for loop by breaking out of it and checking if the file parsing is done yet
//This will intake a CSV file
bool intakeCSV(string fileName){
    ifstream file(fileName);
    string line;
    bool firstLine = true;
    while(getline(file, line)){
        if(firstLine){
            firstLine = false;
            continue;
        }
        vector<string> values;
        stringstream ss(line);
        string token;
        while(getline(ss, token, ',')){
            values.push_back(token);
        }
        
    }
    return true;
}

