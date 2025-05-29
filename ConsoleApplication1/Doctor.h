#pragma once
#include "Employee.h"
#include "json.hpp"
using json = nlohmann::json;
class Doctor :
    public Employee
{
private:
    int completedBooking;
    string department;
public:
    Doctor();
    Doctor(string name, string id, string address, string phoneNumber, string email, string gender, float basicSalary, float liveExpensive, string hireDate, int completedBooking, string department);
  
    bool operator==(const Doctor& other) const;
    
    void setCompletedBooking(const int& completedBooking);
    int getCompletedBooking();
    void setDepartment(const string& department);
    string getDepartment();
    float getSalary() override;
    void toString();

    json toJson() const override;
    static Doctor fromJson(const json& j);
};

