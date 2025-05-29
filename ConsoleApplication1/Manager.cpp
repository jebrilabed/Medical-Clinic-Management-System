#include "Manager.h"

Manager::Manager() = default;

Manager::Manager(string name, string id, string address, string phoneNumber, string email, string gender, float basicSalary, float liveExpensive, string hireDate, float managerBonus):Employee::Employee(name, id, address, phoneNumber, email, gender, basicSalary, liveExpensive, hireDate)
{
	this->managerBonus = managerBonus;
}

void Manager::setManagerBonus(const float& managerBonus)
{
	this->managerBonus = managerBonus;
}

float Manager::getManagerBonus()
{
	return this->managerBonus;
}

void Manager::toString()
{
	Employee::toString();
	cout << "Manager Bonus: " << managerBonus << endl;
}

float Manager::getSalary()
{

	return getBasicSalary() + getBasicSalary() * getLiveExpensive() / 100 + managerBonus;
}



