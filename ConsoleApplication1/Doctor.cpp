#include "Doctor.h"

Doctor::Doctor() = default;

Doctor::Doctor(string name, string id, string address, string phoneNumber, string email, string gender, float basicSalary, float liveExpensive, string hireDate, int completedBooking, string department):Employee::Employee(name, id, address, phoneNumber, email, gender, basicSalary, liveExpensive, hireDate)
{
	this->completedBooking = completedBooking;
	this->department = department;
}

bool Doctor::operator==(const Doctor& other) const
{
	return name == other.name && personalId == other.personalId;
}

void Doctor::setCompletedBooking(const int& completedBooking)
{
	this->completedBooking = completedBooking;
}

int Doctor::getCompletedBooking()
{
	return this->completedBooking;
}

void Doctor::setDepartment(const string& department)
{
	this->department = department;
}

string Doctor::getDepartment()
{
	return this->department;
}

float Doctor::getSalary()
{
	return getBasicSalary() + getBasicSalary() * getLiveExpensive() / 100;
}

void Doctor::toString()
{
	Employee::toString();
	cout << "Completed Booking: " << completedBooking << "\nDepartment: " << department << endl;
}

json Doctor::toJson() const
{
	json j = Employee::toJson();
	j["completedBooking"] = completedBooking;
	j["department"] = department;
	return j;
}

Doctor Doctor::fromJson(const json& j)
{
	return Doctor(
		j.at("name"), j.at("id"), j.at("address"), j.at("phoneNumber"), j.at("email"), j.at("gender"),
		j.at("basicSalary"), j.at("liveExpensive"), j.at("hireDate"),
		j.at("completedBooking"), j.at("department")
	);
	
}
