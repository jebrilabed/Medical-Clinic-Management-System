#pragma once
#include "Person.h"
#include "json.hpp"
using json = nlohmann::json;
class Patient :
    public Person
{
private:
    int bookingOrder;
public:
    Patient();
    Patient(string name, string id, string address, string poneNumber, string email, string gender, int bookingOrder);

    bool operator==(const Patient& other) const;

    void setBookingOrder(const int& bookingOrder);
    int getBookingOrder();
    void increaseBookingOrder();
    void decreaseBookingOrder();
    void toString();

    nlohmann::json toJson() const override;
    static Patient fromJson(const nlohmann::json& j);
};

