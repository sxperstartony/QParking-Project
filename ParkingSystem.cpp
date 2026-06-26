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
    loadCustomers();

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

void ParkingSystem::loadCustomer() {
    ifstream file(config.customerFile);
        if(!file.is_open()) {
            cout << "Could not open customer file" << endl;
            return;
        }

        string line;

        while(getline(file, line)) {}

        file.close();
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
    ofstream outFile("finalGarageState.txt");
        if(!outFile.is_open()) {
            cout << "Could not create output file" << endl;
            return;
        }

        outFile << "\nFinal Garage State\n\n";

        for(int i = 0; i < 1; i++) {
            garage->printGarage();
        }
    outFile.close();
}

