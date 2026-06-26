#ifndef GARAGE_H
#define GARAGE_H

#include <vector>
#include <string>

#include "Customer.h"

using namespace std;

class Garage {
private:
  int numGarages;
  int garageSize;

  //Garage -> level -> spot
  vector < vector <Customer*>>levels;

public:
  Garage( int garages, int size);

  //Park the customer
  void dropoff(Customer& customer);

  //Retrieving the customer
  void pickup(int customerID);

  //Display garage
  void printGarage() const;

  //Save the data intot he output file
  void saveGarageToFile( string filename) const;
};

#endif
