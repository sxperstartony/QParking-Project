#include "ParkingSystem.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

ParkingSystem::ParkingSystem() {
    garage = nullptr;
}

ParkingSystem::~ParkingSystem() {
    delete garage;
}

bool ParkingSystem::initialize(
    string configFile) 
{
    bool success = 
        readConfigFile(
            configFile,
            config);
    
    if (!success) {
        return false;
    }

    garage = 
        new Garage(
            config.numGarages,
            config.garageSize);

    return true;
}

void ParkingSystem::processInteractions() {
    ifstream inputFile(
        config.interactionFile);
    
    if (!inputfile.is_open()) {
        cout << "Could not open interactions file" << endl;

        return;
    }

    string file;

    while(getline(
       inputFile,
       line)) 
       {
           if(line.empty())
           continue;

           if(line[0] == 'P') {
               string idText =
                line.substr(3);

                int customerID =
                stoi(idText);

                pickup(customerID);
           }

           else if (line[0] == 'D') 
           {
               stringstream ss(
                   line.substr(3));

                   string name;
                   string phone;
                   string time;

                   getline (ss, name ',');

                   getline (ss, phone, ',');

                   getline (ss, time);

                   dropoff (name, phone, time);
               
           }
       }

       inputFile.close();
}

void ParkingSystem::dropoff(string name, string phone, string time) {
    cout << "Dropoff Request: " << name << " " << phone << " " << time << endl;
}

void ParkingSystem:: pickup( int customerID) {
    cout << "Pickup Request: " << customerID << endl;
}

void ParkingSystem::output() {
    cout << "\nFinal Garage State\n";

    garage -> printGarage();
}

