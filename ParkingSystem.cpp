#include "ParkingSystem.h"
#include "customers.h"

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

bool ParkingSystem::initialize(string configFile) {
    bool success = readConfigFile(configFile, config);
    
    if (!success) {
        return false;
    }

    garage = new Garage(config.numGarages, config.garageSize);

    garage -> loadOccupancy( config.occupancyFile);

    return true;
}

//Read interaction file
void ParkingSystem::processInteractions() {
    ifstream inputFile("interactions.txt");
    
    if (!inputFile.is_open()) {
        cout << "Could not open interactions file" << endl;

        return;
    }

    string line;

    while(getline(inputFile,line)) {
           if(line.empty()){
               continue;
           }

            //Pickup
           if(line[0] == 'P') {
               string idText =
                line.substr(3);

                int customerID =
                stoi(idText);

                pickup(customerID);
           }

            // drop off request
           else if (line[0] == 'D') 
           {
               stringstream ss(line.substr(3));

                   string name;
                   string phone;
                   string time;

                   getline (ss, name ,',');

                   getline (ss, phone, ',');

                   getline (ss, time);

                   dropoff (name, phone, time);
               
           }
       }

       inputFile.close();
}

//drop off
void ParkingSystem::dropoff(string name, string phone, string time) {
    static int nextID = 100;
    Customer customer(nextID, stoi(phone), name);
    nextID++;

    garage -> dropoff(customer);
    cout << "Arrival Time: " << time << endl;
}

void ParkingSystem::pickup( int customerID) {
    garage ->pickup(customerID);
}

void ParkingSystem::output() {
    cout << "\nFinal Garage State\n";

    garage -> printGarage();
}

