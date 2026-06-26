#ifndef GARAGE_H
#define GARAGE_H

#include <iostream>
#include <vector>
#include <string>
#include "customers.h"

using namespace std;



class Garage {
private:
    int garageCapacity;
    int garageLevels;

    // Gargage [level][position]
    // "-1" = available parking space
    // "R"  = restricted parking space
    // "<customer id>" = occupied parking space
    vector<vector<string>> levels;

    int garagePosition(int customerID) const;

public:
    Garage(int capacity, int numLevels);

    void dropoff(Customer& customer);

    void pickup(int customerID);

    void printGarage() const;
};




#endif
