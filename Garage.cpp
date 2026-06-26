#include "Garage.h"

#include <iostream>
#include <fstream>

using namespace std;

//the constructor
Garage::Garage( int garages, int size) {
  numGarages = garages;

  garageSize = size;

  levels.resize(numGarages, vector<Customer*>(garageSize,nullptr));
}

// Parking the customer
void Garage::dropoff( Customer& customer) {
  for(int level = 0; level < numGarages; level++) {
    
    for(int spot = 0; spot < garageSize; spot++) {
      
      if( levels[level][spot] == nullptr) {
        levels[level][spot] = &customer;
        cout << customer.getCustomerName() << " parked at Garage " << level + 1 << ", spot " << spot << endl;

        return;
      }
    }
  }

  cout << "Garage Full" << endl;
}

//Retrieving the customer
void Garage::pickup(int customerID) {
  for (int level = 0; level < numGarages; level++) {
    
    for(int spot = 0; spot < garageSize; spot++) {
      
      if(customer != nullptr && customer -> getCustomerID() == customerID) {
        cout << customer -> getCustomerName() << " retrieved" << endl;

        levels[level[spot] = nullptr;

        return;
      }
    }
  }
  cout << "Customer not found" << endl;
}

//Displaying
void Garage::printGarage() const {
  cout << "\nGarage Occupancy\n";

  for(int level = 0; level < numGarages; level++) {
    cout << "\nGarage " << level + 1 << endl;

    for(int spot = 0; spot < garageSize; spot++) {
      if(levels[level][spot] == nullptr) {
        cout << "-1";
      }
      else {
        cout << levels[level][spot] -> getCustomerID();
      }

      cout << " ";
    }
    cout << endl;
  }
}

//Save Occupancy
void Garage::saveGarageToFile( string fileName) const {
  ofstream output(fileName);

  if (!output) { 
    return;
  }

  for (int level = 0; level < numGarages; level++) {
    output << "Garage " << level + 1 << endl;

    for (int spot = 0; spot < garageSize; spot++) {
      if(levels[level][spot] == nullptr) {
        output << "-1";
      }
      else {
        output << levels[level][spot] -> getCustomerID();
      }

      output << " ";
    }
    output << endl;
  }
  output.close();
}









