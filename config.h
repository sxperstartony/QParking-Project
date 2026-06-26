#ifndef CONFIG_H
#define CONFIG_H
#include <string>
#include <vector>
using namespace std;


struct ConfigData
{
    int numGarages;
    int garageSize;
    string occupancyFile;
    string customerFile;
};

bool readConfigFile(string fileName, ConfigData& config);


#endif
