#include "Patient.h"

Patient::Patient() = default;

Patient::Patient(string name, string id, string address, string poneNumber, string email, string gender, int bookingOrder):Person::Person(name, id, address, poneNumber, email, gender)
{
	this->bookingOrder = bookingOrder;
}

bool Patient::operator==(const Patient& other) const
{
	return name == other.name && personalId == other.personalId;
}


void Patient::setBookingOrder(const int& bookingOrder)
{
	this->bookingOrder = bookingOrder;
}

int Patient::getBookingOrder()
{
	return this->bookingOrder;
}

void Patient::increaseBookingOrder()
{
	this->bookingOrder++;
}

void Patient::decreaseBookingOrder()
{
	this->bookingOrder--;
}

void Patient::toString()
{
	Person::toString();
	cout << "Booking Order: " << bookingOrder << endl;
}

nlohmann::json Patient::toJson() const
{
	json j = Person::toJson();
	j["bookingOrder"] = bookingOrder;
	return j;
}

Patient Patient::fromJson(const nlohmann::json& j)
{
	return Patient(
		j.at("name"), j.at("id"), j.at("address"), j.at("phoneNumber"), j.at("email"), j.at("gender"),
		j.at("bookingOrder")
	);
}
