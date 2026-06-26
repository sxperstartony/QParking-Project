#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <iostream>
#include <string>

using namespace std;



class Customer {
private:
    int customerID;
    int phoneNumber;
    string name;

public:
    Customer(int id, int phone, string customerName);

    int getCustomerID() const;

    int getPhoneNumber() const;

    string getCustomerName() const;
};



#endif