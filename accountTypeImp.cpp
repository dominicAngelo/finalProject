#include "accountType.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "accountType.h"

using namespace std;


void accountType::normalMenu() {
    int choice;
    int yr, mon, day, hr, min;
    string desc;

    do {
        cout << "\n=== User Menu ===\n";
        cout << "1. View Appointments\n";
        cout << "2. Add Appointment\n";
        cout << "3. Delete Appointment\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Feature not implemented yet.\n";
            break;
        case 2:
            cin >> yr >> mon >> day >> hr >> min;
            //might need to add a dummy getline here
            getline(cin >> std::ws, desc);
            addAppointment(yr, mon, day, hr, min, desc);
            break;
        case 3:
            int index;
            cout << "Enter index of appointment to delete (0–99): ";
            cin >> index;
            if (index >= 0 && index < 100) {
                deleteAppointment(index);
            }
            else {
                cerr << "Invalid index.\n";
            }

            break;
        case 4:
            cout << "Goodbye!\n";
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);
}

void accountType::readData() {
    string filename = fname + "_" + lname + ".txt";
    ifstream file(filename);
    if (!file) {
        cerr << "Unable to open account file: " << filename << std::endl;
        return;
    }

    int yr, mon, day, hr, min;
    string desc;
    int index = 0;

    while (!file.eof()) {
        file >> yr >> mon >> day >> hr >> min;
        appointmentType temp(yr, mon, day, hr, min, desc);
        //might need to add a dummy getline here
        getline(file >> std::ws, desc);
        if (index < 100) {
            appointments.insert(temp);
            index++;
        }
    }

    file.close();
}

void accountType::addAppointment(int day, int month, int year, int hour, int minute, string desc) {
    appointmentType dummy(year, month, day, hour, minute, desc);
    appointments.insert(dummy);
}

void accountType::deleteAppointment(int index) {
    appointments.removeAt(index);
}

void accountType::addAccount(const string& userName)
{
    accounts->push_back(userName);
}

void accountType::removeAccount(const string& userName)
{
    auto it = find(accounts->begin(), accounts->end(), userName);
    if (it != accounts->end())
    {
        accounts->erase(it);
    }
}

void accountType::addPassword(const string& password)
{

    accounts->push_back(password);
}

void accountType::removePassword(const string& password)
{
    auto it = find(passwords->begin(), passwords->end(), password);
    if (it != passwords->end())
    {
        passwords->erase(it);
    }
}
