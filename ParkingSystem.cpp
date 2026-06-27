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
    ifstream inputFile(config.interactionFile);
    
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
               string idText = line.substr(2);
               idText.erase(0, idText.find_first_not_of(" "));

               try {
                   int customerID = stoi(idText);
                   pickup(customerID);
                }
                catch (...) {
                    cout << "Invalid customer ID(skipped)\n";
                }
           }

            // drop off request
           else if (line[0] == 'D') 
           {
               stringstream ss(line.substr(2));

                   string name;
                   string phone;
                   string time;

                   getline (ss, name ,',');
                   getline (ss, phone, ',');
                   getline (ss, time);

                   phone.erase(0, phone.find_first_not_of(" "));
                   phone.erase(phone.find_last_not_of(" ") + 1);

                   dropoff (name, phone, time);
               
           }
       }

       inputFile.close();
}


//drop off
void ParkingSystem::dropoff(string name, string phone, string time) {
    static int nextID = 100;

    Customer customer(nextID, phone, name);

    garage ->dropoff(customer);

    cout << "Arrival Time: " << time << endl;
    nextID++;
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

        streambuf* old = cout.rdbuf();
        cout.rdbuf(outFile.rdbuf());

        cout << "\nFinal Garage State\n";
        garage->printGarage();

        cout.rdbuf(old);

    outFile.close();
}
