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
    string interactionFile;
};

bool readConfigFile(string fileName, ConfigData& config);


#endif
