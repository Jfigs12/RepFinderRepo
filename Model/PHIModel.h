#ifndef PHIMODEL_H
#define PHIMODEL_H

#include <stdio.h>
#include <iostream>
using namespace std;

class personalInfo{
    private:
        string name;
        string address;
        int phoneNumber;
    public:
        int PersonalID;
        bool includeOffices;
        


    bool setPHI(string name, string address, bool includeOffices, int phoneNumber, int PersonalID){
        try{
            this->name = name;
            this->address = address;
            this->includeOffices = includeOffices;  
            this->phoneNumber = phoneNumber;
            this->PersonalID = PersonalID;
            return true;
        }
        catch(exception e){
            return false;
        }
        
    }

    //return private class variables as an object
    personalInfo getPHI(){
        personalInfo temp;
        temp.name = this->name;
        temp.address = this->address;
        temp.includeOffices = this->includeOffices;
        temp.phoneNumber = this->phoneNumber;
        return temp;
    }
    int getID(){
        return PersonalID;
    }
    
    string getName(){
        return name;
    }
    int getID()const{
        return PersonalID;
    }
    string getAddress(){
        return address;
    }
    int getPhoneNumber(){
        return phoneNumber;
    }



};
#endif