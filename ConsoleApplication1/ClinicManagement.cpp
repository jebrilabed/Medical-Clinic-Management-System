#include "Manager.h"
#include "Doctor.h"
#include "Patient.h"
#include "Booking.h"
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

Manager manager;
list <Doctor> doctors;
list <Patient> patients;
list <Booking> bookings;
string name, id, address, phoneNumber, email, gender, hireDate;
float basicSalary, liveExpensive, managerBonus;

enum mainMenu {
    addEmployee = 1,
    addPatient = 2,
    addBooking = 3,
    showDoctors = 4,
    showBooking = 5,
    showSalaries = 6,
    deletBooking = 7,
    countBooking = 8,
    saveData = 9,
    Exit=10
};

enum addEmployeeMenu {
    addManager = 1,
    addDoctor = 2,
    backToMain1 = 3
};

enum showDoctorMenu {
    generalDoctors = 1,
    allDoctors = 2,
    backToMain2 = 3
};

enum employeesSalaryMenu {
    managerSalary = 1,
    doctorSalary = 2,
    backToMain3 = 3
};

void getPersonalInfo() {
    cout << "\nEnter The Name: ";
    getline(cin, name);
    cout << "Enter The Id: ";
    getline(cin, id);
    cout << "Enter The Address: ";
    getline(cin, address);
    cout << "Enter The Phone Number: ";
    getline(cin, phoneNumber);
    cout << "Enter The Email: ";
    getline(cin, email);
    cout << "Enter The Gender: ";
    getline(cin, gender);
}

void getEmployeeInf() {
    cout << "Enter The Hire Date: ";
    getline(cin, hireDate);
    cout << "Enter The Basic Salary: ";
    cin >> basicSalary;
    cout << "Enter The Live Expinsive: ";
    cin >> liveExpensive;
    cin.ignore();
}

void funAddManager() {
    cout << "\n--------Get The Manager Information--------" << endl;
    getPersonalInfo();
    getEmployeeInf();
    float managerBonus;
    cout << "Enter The Manager Manager Bonus: ";
    cin >> managerBonus;
    cin.ignore();
    cout << "-------------------------------------------" << endl;
    Manager newManager(name, id, address, phoneNumber, email, gender, basicSalary, liveExpensive, hireDate, managerBonus);
    manager = newManager;
    cout << "The Manager Is Added Successfully" << endl;
}

void funAddDoctor() {
    cout << "\n--------Get The Doctor Information--------" << endl;
    getPersonalInfo();
    getEmployeeInf();
    string department;
    int completedBooking;
    cout << "Enter The Doctor Department: ";
    getline(cin, department);
    cout << "Enter The Doctor Completed Booking: ";
    cin >> completedBooking;
    cin.ignore();
    cout << "-------------------------------------------" << endl;
    Doctor newDoctor(name, id, address, phoneNumber, email, gender, basicSalary, liveExpensive, hireDate, completedBooking, department);
    doctors.push_back(newDoctor);
    cout << "The Doctor Is Added Successfully" << endl;
}

void funAddPatient() {
    cout << "\n-------Get The Patients Information-------" << endl;
    getPersonalInfo();
    int bookingOrder;
    cin >> bookingOrder;
    cin.ignore();
    cout << "-------------------------------------------" << endl;
    Patient newPatient(name, id, address, phoneNumber, email, gender, bookingOrder);
    patients.push_back(newPatient);
    cout << "The Patient Is Added Successfully" << endl;
}

void funAddBooking() {
    string bookingId, date, details, department;
    Doctor doctor;
    Patient patient;
    cout << "Enter The Patient Name: ";
    getline(cin, name);
    patient.setName(name);
    cout << "Enter The Patient Id: ";
    getline(cin, id);
    patient.setId(id);

    for (const Patient& pat : patients) {
        if (pat == patient)
            patient = pat;
    }
    if (patient.getAddress() == "")
    {
        cout << "This Patient Is Not Found" << endl;
        return;
    }

    cout << "Enter The Department of Booking: ";
    getline(cin, department);

    cout << "Enter The Doctor Name: ";
    getline(cin, name);
    doctor.setName(name);
    cout << "Enter The Doctor Id: ";
    getline(cin, id);
    doctor.setId(id);

    for (const Doctor& doc : doctors) {
        if (doc == doctor)
            doctor = doc;
    }
    if (doctor.getAddress() == "")
    {
        cout << "This Doctor Is Not Found" << endl;
        return;
    }
    else if (doctor.getDepartment() != department) {
        cout << "This Doctor Is Not In This Department" << endl;
        return;
    }

    cout << "Enter The Booking Order: ";
    getline(cin, bookingId);
    cout << "Enter The Booking Date: ";
    getline(cin, date);
    cout << "Enter The Booking Details: ";
    getline(cin, details);
  
    Booking newBook(bookingId, date, details, department, doctor, patient);
    bookings.push_back(newBook);
    cout << "The Booking Is Added Successfully" << endl;
}

void showGeneralDoctors() {
    for ( Doctor& doc : doctors) {
        if (doc.getDepartment() == "General Doctor")
            doc.toString();
    }
}

void showAllDoctors() {
    for (Doctor& doc : doctors) 
        doc.toString();
}

void funShowBooking() {
    Patient patient;
    cout << "Enter The Patient Name: ";
    getline(cin, name);
    patient.setName(name);
    cout << "Enter The Patient Id: ";
    getline(cin, id);
    patient.setId(id);

    for (Booking& book : bookings) {
        if (book.getPatient() == patient) {
            book.toString();
            break;
        }
    }
}

void showDoctorSalary() {
    Doctor doctor;
    cout << "Enter The Doctor Name: ";
    getline(cin, name);
    doctor.setName(name);
    cout << "Enter The Doctor Id: ";
    getline(cin, id);
    doctor.setId(id);

    for (Doctor& doc : doctors) {
        if (doc == doctor) {
            cout << "The Salary Of Doctor: " << doc.getSalary() << endl;
            break;
        }
    }
}

void funDeletBooking() {
    string bookingId;
    cout << "Enter The Booking Id: ";
    getline(cin, bookingId);

    for (Booking& book : bookings) {
        if (bookingId == book.getBookingId()) {
            bookings.remove(book);
            break;
        }
    }
    cout << "The Booking Is Deleted Successfully" << endl;
}

void funCountBooking() {
    Patient patient;
    cout << "Enter The Patient Name: ";
    getline(cin, name);
    patient.setName(name);
    cout << "Enter The Patient Id: ";
    getline(cin, id);
    patient.setId(id);

    for (Patient& pat : patients) {
        if (pat == patient) {
            cout << "The Number Of The Booking Order: " << pat.getBookingOrder() << endl;
            break;
        }
    }
}

void funSaveData(const string data) {
    json j;
    j["doctors"] = json::array();
    j["patients"] = json::array();
    j["bookings"] = json::array();
    
    

    for (const Doctor& doctor : doctors) {
        j["doctors"].push_back(doctor.toJson());
    } 

    for (const Patient& patient : patients) {
        j["patients"].push_back(patient.toJson());
    }
    
    for (const Booking& booking : bookings) {
        j["bookings"].push_back(booking.toJson());
    }

    ofstream file(data);
    file << j.dump(4);
    file.close();

}

void loadData(const string& data) {
    ifstream file(data);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << data << endl;
        return;
    }

    json j;
    file >> j;
    file.close();

    doctors.clear();
    patients.clear();
    bookings.clear();
  


    for (const auto& docJson : j["doctors"]) {
        doctors.push_back(Doctor::fromJson(docJson));
    } 

    for (const auto& patJson : j["patients"]) {
        patients.push_back(Patient::fromJson(patJson));
    } 

    for (const auto& bookJson : j["bookings"]) {
        bookings.push_back(Booking::fromJson(bookJson));
    }
    
}

int main()
{
    loadData("clintData.json");

    int intChoice;
    mainMenu choice;
    do {
        cout << "\n---------Medical Clinic Management---------" << endl;
        cout << " 1- Add Employee.\n" << " 2- Add Patient.\n" << " 3- Add Booking.\n" << " 4- Show Doctors.\n" << " 5- Show bookings for a specific Patient.\n" << " 6- Show Employees Salaries.\n" << " 7- Delete booking.\n" << " 8- Count of booking to any Patient.\n" << " 9- Save data in a binary file.\n" << " 10- Exit" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Enter Your Choice: ";
        cin >> intChoice;
        cin.ignore();
        choice = (mainMenu)intChoice;

        switch (choice)
        {
        case addEmployee: {
            addEmployeeMenu choice;
            do{
            cout << "\n-------------Add Employee Menu-------------" << endl;
            cout << " 1- Add Manager.\n" << " 2- Add Doctor.\n" << " 3- Back to the main menu."<<endl;
            cout << "-------------------------------------------" << endl;
            cout << " Enter Your Choice: ";

            cin >> intChoice;
            cin.ignore();
            choice = (addEmployeeMenu)intChoice;
            
                switch (choice)
                {
                case addManager: {
                    if (manager.getName() == "")
                        funAddManager();
                    break;
                }
                case addDoctor: {
                    funAddDoctor();
                    break;
                }
                case backToMain1: {
                    break;
                }
                default: {
                    cout << "\nInviled Input" << endl;
                    break;
                }
                }
            } while (choice != addEmployeeMenu::backToMain1);
            break;
        }
        case addPatient: {
            funAddPatient();
            break;
        }
        case addBooking: {
            funAddBooking();
            break;
        }
        case showDoctors: {
            cout << " 1- General Doctor Employees.\n" << " 2- All Doctors.\n" << " 3- Back to the main menu." << endl;
            cout << " Enter Your Choice: ";
            cin >> intChoice;
            showDoctorMenu choice = (showDoctorMenu)intChoice;
            switch (choice)
            {
            case generalDoctors: {
                showGeneralDoctors();
                break;
            }
            case allDoctors: {
                showAllDoctors();
                break;
            }
            case backToMain2: {
                break;
            }
            default: {
                cout << "Inviled Input" << endl;
                break;
            }
            }
            break;
        }
        case showBooking: {
            funShowBooking();
            break;
        }
        case showSalaries: {
            cout << " 1- Manager salary.\n" << " 2- Specific Doctor Salary.\n" << " 3- Back to the main menu." << endl;
            cout << " Enter Your Choice: ";
            cin >> intChoice;
            employeesSalaryMenu choice = (employeesSalaryMenu)intChoice;
            switch (choice)
            {
            case managerSalary: {
                cout << "The Salary Of Manager: " << manager.getSalary() << endl;
                break;
            }
            case doctorSalary: {
                showDoctorSalary();
                break;
            }
            case backToMain3: {
                break;
            }
            default: {
                cout << "Inviled Input" << endl;
                break;
            }
            }
            break;
        }
        case deletBooking: {
            funDeletBooking();
            break;
        }
        case countBooking: {
            funCountBooking();
            break;
        }
        case saveData: {
            funSaveData("clintData.json");
            cout << "Data Saved Successfully" << endl;
            break;
        }
        case Exit:{
            break;
        }
        default: {
            cout << "Inviled Input" << endl;
            break;
        }
        }

    }while(choice != mainMenu::Exit);
}

