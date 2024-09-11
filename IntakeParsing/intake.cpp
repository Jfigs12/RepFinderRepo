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


bool setPointertoCSV(){
    string file;
    cout << "Enter the name of the file you would like to analyze: ";
    cin >> file;
    ifstream myFile(file);
    if(!myFile.is_open()){
        cout << "File not found" << endl;
        return false;
    }
    else{
        cout << "File found" << endl;
        return true;
    }
}

