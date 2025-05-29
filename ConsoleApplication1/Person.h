#pragma once
#include<string>
#include <iostream>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;
class Person
{
protected:  
	string name, personalId, address, phoneNumber, email, gender;
public:
	Person();
	Person(string name, string id, string address, string phoneNumber, string email, string gender);
	void setName(const string& name);
	string getName();
	void setId(const string& id);
	string getId();
	void setAddress(const string& address);
	string getAddress();
	void setPhoneNumber(const string& phoneNumber);
	string getPhoneNumber();
	void setEmail(const string& email);
	string getEmail();
	void setGender(const string& gender);
	string getGender();
	void toString();

	virtual json toJson() const;
};

