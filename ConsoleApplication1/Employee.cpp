#include "Employee.h"

Employee::Employee () = default;

Employee::Employee(string name, string id, string address, string phoneNumber, string email, string gender, float basicSalary, float liveExpensive, string hireDate):Person::Person(name, id, address, phoneNumber, email, gender)
{
	this->basicSalary = basicSalary;
	this->liveExpensive = liveExpensive;
	this->hireDate = hireDate;
}

void Employee::setBasicSalary(const float& basicSalary)
{
	this->basicSalary = basicSalary;
}

float Employee::getBasicSalary()
{
	return this->basicSalary;
}

void Employee::setLiveExpensive(const float& liveExpensive)
{
	this->liveExpensive = liveExpensive;
}

float Employee::getLiveExpensive()
{
	return this->liveExpensive;
}

void Employee::setHireDate(const string& hireDate)
{
	this->hireDate = hireDate;
}

string Employee::getHireDate()
{
	return this->hireDate;
}

void Employee::toString()
{
	Person::toString();
	cout << "\nBasic Salary: " << this->basicSalary << "\nLive Expensive: " << this->liveExpensive << "\nHire Date: " << this->hireDate << endl;
}

json Employee::toJson() const
{
	json j = Person::toJson();
	j["basicSalary"] = basicSalary;
	j["liveExpensive"] = liveExpensive;
	j["hireDate"] = hireDate;

	return j;
}
