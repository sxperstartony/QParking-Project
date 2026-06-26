#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer {
private:
  int customerID;
  string name;
  string phone;

public:
  Customer();

  Customer(int id, string customerName, string customerPhone);

  int getCustomerID() const;

  string getCustomerName() const;

  string getPhoneNumber() const;
};

#endif
