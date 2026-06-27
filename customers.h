#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <string>

using namespace std;



class Customer {
private:
    int customerID;
    string phoneNumber;
    string name;

public:
    Customer(int id, string phone, string customerName);

    int getCustomerID() const;

    string getPhoneNumber() const;

    string getCustomerName() const;
};



#endif
