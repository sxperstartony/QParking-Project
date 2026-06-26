#include <iostream>

#include "ParkingSystem.h"

usign namespace std;

int main() {
  ParkingSystem system;

  string configFile;

  cout << "Enter conifguration file: ";
  cin >> configFile;

  //Initialize the system
  if (!system.initialize(configFile)) {
    cout << "Initialization failed." << endl;

    return 1;
  }

  //Read and exexute interactions
  system.processInteractions();

  //Print final garage occupancy
  system.output();

  return 0;
}
