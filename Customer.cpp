#include "Customer.h"

using namespace std;

//Empty the constructor
Customer::Customer() {
  customerID = -1;
  name = "";
  phone = "";
}

//Constructor
Customer::Customer( int id, string customerName, string customerPhone) {
  customerID = id;
  name = customerName;
  phone = customerPhone;
}

//Getting the ID
int customer::getCustomerID() const {
  return customerID;
}

//Getting the name
string Customer::getCustomerName() const{
  return name;
}

//getting the phone
string Customer::getPhoneNumber() const {
  return phone;
}
