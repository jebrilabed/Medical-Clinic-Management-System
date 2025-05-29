#include "Booking.h"

Booking::Booking() = default;

Booking::Booking(string id, string date, string details, string department, Doctor doctor, Patient patient):bookingId(id),date(date),details(details),department(department),doctor(doctor),patient(patient)
{
}

bool Booking::operator==(const Booking& other) const
{
	return bookingId == other.bookingId;
}

void Booking::setBookingId(const string& id)
{
	this->bookingId = id;
}

string Booking::getBookingId()
{
	return this->bookingId;
}

void Booking::setDate(const string& date)
{
	this->date = date;
}

string Booking::getDate()
{
	return this->date;
}

void Booking::setDetails(const string& details)
{
	this->details = details;
}

string Booking::getDetails()
{
	return this->details;
}

void Booking::setDepartment(const string& department)
{
	this->department = department;

}

string Booking::getDepartment()
{
	return this->department;
}

void Booking::setDoctor(const Doctor& doctor)
{
	this->doctor = doctor;
}

Doctor Booking::getDoctor()
{
	return this->doctor;
}

void Booking::setPatient(const Patient& patient)
{
	this->patient = patient;
}

Patient Booking::getPatient()
{
	return this->patient;
}

void Booking::toString()
{
	cout <<"Booking Id: "<< bookingId << "\nDate: " << date << "\nDetails" << details << "\nDepartment: " << department << "\nDoctor: " << doctor.getName() << "\nPatient: " << patient.getName() << endl;
}

nlohmann::json Booking::toJson() const
{
	return {
		{"BookingId", bookingId},
		{"Date", date},
		{"Details", details},
		{"Department", department},
		{"doctor", doctor.toJson()},
		{"patient", patient.toJson()}
	};
}

Booking Booking::fromJson(const nlohmann::json& j)
{
	return Booking(
		j.at("BookingId").get<string>(),
		j.at("Date").get<string>(),
		j.at("Details").get<string>(),
		j.at("Department").get<string>(),
		Doctor::fromJson(j.at("Doctor")),
		Patient::fromJson(j.at("Patient"))
		);
}
