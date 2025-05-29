#include "Person.h"

Person::Person() = default;
Person::Person(string name, string id, string address, string phoneNumber, string email, string gender):name(name), personalId(id), address(address), phoneNumber(phoneNumber), email(email), gender(gender)
{
	
}

void Person::setName(const string& name)
{
	this->name = name;
}

string Person::getName()
{
	return this->name;
}

void Person::setId(const string& id)
{
	this->personalId = id;
}

string Person::getId()
{
	return this->personalId;
}

void Person::setAddress(const string& address)
{
	this->address = address;
}

string Person::getAddress()
{
	return this->address;
}

void Person::setPhoneNumber(const string& phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

string Person::getPhoneNumber()
{
	return this->phoneNumber;
}

void Person::setEmail(const string& email)
{
	this->email = email;
}

string Person::getEmail()
{
	return this->email;
}

void Person::setGender(const string& gender)
{
	this->gender = gender;
}

string Person::getGender()
{
	return this->gender;
}

void Person::toString()
{
	cout << "Name: " << this->name << "\nId: " << this->personalId << "\nAddress: " << this->address << "\nPhone Number : " << this->phoneNumber << "\nEmail: " << this->email << "\nGender: " << this->gender << endl;
}

json Person::toJson() const
{
	return {
		{"name", name},
		{"personalId", personalId},
		{"address", address},
		{"phoneNumber", phoneNumber},
		{"email", email},
		{"gender", gender}
	};
}
