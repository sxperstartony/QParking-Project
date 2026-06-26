#ifndef CONFIG_H
#define CONFIG_H

#include <string>

using namespace std;


struct ConfigData
{
    int numGarages;
    int garageSize;
    string occupancyFile;
    string customerFile;
    string InteractionFile;
};

bool readConfigFile(string fileName, ConfigData& config);


#endif
