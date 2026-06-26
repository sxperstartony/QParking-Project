#include "config.h"
#include <iostream>
#include <fstream>
using namespace std;


//This will read the config file and store the data in that config
bool readConfigFile(string fileName, ConfigData& config)
{
    ifstream inputFile;


    if (!inputFile.is_open())
    {
        cout << "Could not open selected config file" << endl;
        return false; 
    }

    //takes in the number of garages and the garage size
    inputFile >> config.numGarages >> config.garageSize;
    //file name for gargage occupancy
    inputFile >> config.occupancyFile;
    //file name for the customers information
    inputFile >> config.customerFile;

    inputFile.close();

    return true;
}


