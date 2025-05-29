#pragma once
#include "Employee.h"
#include "json.hpp"

class Manager :
    public Employee
{
private:
    float managerBonus;
    
public:
    Manager();
    Manager(string name, string id, string address, string phoneNumber, string email, string gender, float basicSalary, float liveExpensive, string hireDate, float managerBonus);
    void setManagerBonus(const float& managerBonus);
    float getManagerBonus();
    void toString();
    float getSalary() override;


};

