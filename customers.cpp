#include "customers.h"

Customer::Customer(int id, int phone, string customerName)
{
    customerID = id;
    phoneNumber = phone;
    name = customerName;
}

int Customer::getCustomerID() const
{
    return customerID;
}

int Customer::getPhoneNumber() const
{
    return phoneNumber;
}

string Customer::getCustomerName() const
{
    return name;
}