#pragma once
#include<string>
#include"Doctor.h"
#include"Patient.h"
#include "json.hpp"
using namespace std;
class Booking
{
private:
	string bookingId;
	string date;
	string details;
	string department;
	Doctor doctor;
	Patient patient;

public:
	Booking();
	Booking(string id, string date, string details, string department, Doctor doctor, Patient patient );

	bool operator==(const Booking& other) const;

	void setBookingId(const string& id);
	string getBookingId();
	void setDate(const string& date);
	string getDate();
	void setDetails(const string& details);
	string getDetails();
	void setDepartment(const string& department);
	string getDepartment();
	void setDoctor(const Doctor& doctor);
	Doctor getDoctor();
	void setPatient(const Patient& patient);
	Patient getPatient();
	void toString();

	nlohmann::json toJson() const;
	static Booking fromJson(const nlohmann::json& j);
};


