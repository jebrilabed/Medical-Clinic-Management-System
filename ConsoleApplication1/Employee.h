#pragma once
#include "Person.h"
#include <string>
using namespace std;
class Employee :
    public Person
{
protected:
    float basicSalary;
    float liveExpensive = 5.5;
    string hireDate;
   
public:
    Employee();
    Employee(string name, string id, string address, string phoneNumber, string email, string gender, float basicSalary, float liveExpensive, string hireDate);
    void setBasicSalary(const float& basicSalary);
    float getBasicSalary();
    void setLiveExpensive(const float& liveExpensive);
    float getLiveExpensive();
    void setHireDate(const string& hireDate);
    string getHireDate();
    void toString();
    virtual float getSalary() = 0;

    virtual json toJson() const override;
};

