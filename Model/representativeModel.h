#ifndef REPRESENTATIVEMODEL_H
#define REPRESENTATIVEMODEL_H


#include <stdio.h>
#include <iostream>
using namespace std;

class Representative{
    public: 
        int districtID;
        string name;
        string firstName;
        string lastName;
        string party;
        int DOI;

        void setDistrictID(int districtID){
            this->districtID = districtID;
        }
        int getDistrictID(){
            return districtID;
        }

        string getRepresentativeName(){
            return name;
        }
        string getParty(){
            return party;
        }
        int getDOI(){
            return DOI;
        }

        
        
    };

#endif