#include "scheduleType.h"
#include <fstream>
#include <iostream>

void scheduleType::readMasterData(std::string filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    int y, m, d;
    std::string desc;

    while (file >> y >> m >> d) {
        file >> std::ws;
        std::getline(file, desc);
        appendArray(y, m, d, desc);
    }

    file.close();
}

void scheduleType::appendArray(int year, int month, int day, const std::string& description) {
    // Example implementation
    std::cout << "Appending: " << year << "-" << month << "-" << day << ": " << description << std::endl;
}

void scheduleType::nonexistentFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        // File does not exist, create it
        std::ofstream newFile(filename);
        if (newFile) {
            std::cout << "Master file created: " << filename << std::endl;
        } else {
            std::cerr << "Error creating master file: " << filename << std::endl;
        }
    } else {
        std::cout << "Master file already exists: " << filename << std::endl;
    }
}

void login() {
    // Example login function
    std::cout << "Enter Username." << std::endl;
    std::string username;
    // There should be a function to check if the username is valid.
    std::cin >> username;
    std::cout << "Enter Password." << std::endl;
    std::string password;
    // There should be a function to check if the password is valid.
    std::cin >> password;
}
