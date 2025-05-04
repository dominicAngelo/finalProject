#include "accountType.h"
#include <iostream>
#include <fstream>

void accountType::normalMenu() {
    int choice;
    int yr, mon, day, hr, min;
    std::string desc;

    do {
        std::cout << "\n=== User Menu ===\n";
        std::cout << "1. View Appointments\n";
        std::cout << "2. Add Appointment\n";
        std::cout << "3. Delete Appointment\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Feature not implemented yet.\n";
            break;
        case 2:
            cin >> yr >> mon >> day >> hr >> min;
            //might need to add a dummy getline here
            std::getline(cin >> std::ws, desc);
            addAppointment(yr, mon, day, hr, min, desc);
                break;
        case 3:
            int index;
            std::cout << "Enter index of appointment to delete (0–99): ";
            std::cin >> index;
            if (index >= 0 && index < 100) {
                deleteAppointment(index);
            }
            else {
                std::cerr << "Invalid index.\n";
            }
            
            break;
        case 4:
            std::cout << "Goodbye!\n";
        default:
            std::cout << "Invalid choice.\n";
        }
    } while (choice != 4);
}

void accountType::readData() {
    std::string filename = fname + "_" + lname + ".txt";
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open account file: " << filename << std::endl;
        return;
    }

    int yr, mon, day, hr, min;
    std::string desc;
    int index = 0;

    while (!file.eof()) {
        file >> yr >> mon >> day >> hr >> min;
        appointmentType temp(yr, mon, day, hr, min, desc);
        //might need to add a dummy getline here
        std::getline(file >> std::ws, desc);
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
