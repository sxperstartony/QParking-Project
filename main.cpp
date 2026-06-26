#include <iostream>

#include "ParkingSystem.h"

using namespace std;

int main() {
    ParkingSystem system;

    string configFile;

    cout << "Enter configuration file: " ;

    cin >> configFile;

    bool success = system.initialize( configFile);

    if (!success) {
      cout << "System initialization failed." << endl;

      return 1;
    }

    system.processInteractions();

    system.output();

    return 0;
}
