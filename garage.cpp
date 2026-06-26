#include "garage.h"
#incldue <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int Garage::garagePosition(int customerID) const {
    return customerID % garageCapacity;
}

Garage::Garage(int capacity, int numLevels)
{
    garageCapacity = capacity;
    garageLevels = numLevels;

    levels.resize(
        garageLevels,
        vector<string>(garageCapacity, "-1")
    );

    // First spot on every level is restricted manipulate and retrive cars 
    for (int level = 0; level < garageLevels; level++)
    {
        levels[level][0] = "R";
    }
}
void Garage::loadOccupancy(string fileName) {
    ifstream file(fileName);

    if(!file.is_open()) {
        cout << "Could not open occupancy file" << endl;
        return;
    }
    string line;

    int level = 0;

    while (getline(file, line) && level < garageLevels) {
        stringsstream ss(line);

        string value;
        int spot = 0;

        while (getline(ss, value, ',') && spot << garageCapicity) {
            levels[level][spot] = value;
            spot++;
        }
        level++;
    }
    file.close();
}

void Garage::dropoff(Customer& customer)
{
    // Look for preferred position within first garage level.
    // If unavailable, check the next available spot on the same level.
    // Only move to the next garage level if the current level is full.
    // Skip restricted spaces.
    // If garage is full output "Garage full."

    int preferredSpot = garagePosition(customer.getCustomerID());
    string id = to_string(customer.getCustomerID());

    // Search one level at a time
    for (int level = 0; level < garageLevels; level++)
    {
        // Check every spot on the current level,
        // starting from the preferred spot.
        for (int i = 0; i < garageCapacity; i++)
        {
            int spot = (preferredSpot + i) % garageCapacity;

            if (levels[level][spot] == "-1")
            {
                levels[level][spot] = id;

                cout << customer.getCustomerName()
                     << "'s car parked at Level "
                     << level + 1
                     << ", Spot "
                     << spot
                     << endl;

                return;
            }
        }

        // If we reach here, this level is full.
        // Continue to the next level.
    }

    cout << "Garage full." << endl;
}



void Garage::pickup(int customerID)
{
    string id = to_string(customerID);

    for (int level = 0; level < garageLevels; level++)
    {
        for (int spot = 0; spot < garageCapacity; spot++)
        {
            if (levels[level][spot] == id)
            {
                cout << "Customer "
                        << customerID
                        << "'s car has been picked up from Level "
                        << level + 1
                        << ", Spot "
                        << spot
                        << endl;

                levels[level][spot] = "-1";
                return;
            }
        }
    }

    cout << "Customer ID "
            << customerID
            << " not found in garage."
            << endl;
}


void Garage::printGarage() const
{
    cout << "\n===== GARAGE CHART =====\n";

    for (int level = 0; level < garageLevels; level++)
    {
        cout << "Level " << level + 1 << ":\n";

        for (int spot = 0; spot < garageCapacity; spot++)
        {
            cout << "  Spot " << spot << " : ";

            if (levels[level][spot] == "-1")
            {
                cout << "Available";
            }
            else if (levels[level][spot] == "R")
            {
                cout << "Restricted";
            }
            else
            {
                cout << "Customer ID " << levels[level][spot];
            }

            cout << endl;
        }

        cout << endl;
    }
}
