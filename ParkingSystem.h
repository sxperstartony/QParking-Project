#ifndef PARKINGSYSTEM_H
#define PARKINGSYSTEM_H

#include <string>
#include "config.h"

using namespace std;

class ParkingSystem {
    private: 
        ConfigData config;

        Garage* garage;
    
    public:
        ParkingSystem();

        ~ParkingSystem();

        // Intializing the entire system
        bool initalize(string configfiel);

        //Reading and executing interations
        void processInteractions();

        void dropoff(
            string name,
            string phone,
            string time
        );

        void pickup(
            int customerID
        );

        void output();
};

#endif
