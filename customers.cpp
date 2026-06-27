#include "customers.h"

Customer::Customer(int id, string phone, string customerName)
{
    customerID = id;
    phoneNumber = phone;
    name = customerName;
}

int Customer::getCustomerID() const
{
    return customerID;
}

string Customer::getPhoneNumber() const
{
    return phoneNumber;
}

string Customer::getCustomerName() const
{
    return name;
}
