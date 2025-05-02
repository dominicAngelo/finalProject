#include "scheduleType.h"
#include <fstream>
#include <iostream>

void scheduleType::readMasterData(std::string filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        nonexistentFile(filename);
        std::ifstream file(filename);
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
            std::cout << filename << " created" << std::endl;
        } else {
            std::cerr << "Error creating: " << filename << std::endl;
        }
    } else {
        std::cout << "Master file already exists: " << filename << std::endl;
    }
}

void scheduleType::login() {
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

int scheduleType::lNameSearch(string searchName) {
    for (int i = 0; i < accountNum; i++) {
        if (accounts[i].lname == searchName) {
            return i;
        }
    }
    return -1;
    //-1 should only be returned if the lastname is not found
}

void scheduleType::loadAllData() {
    if (isAdmin == false){
        return
            }
    for (int i = 0; i < accountNum; i++){
        accounts[i].loadData;
        //loadData is a place holder for the method that will be put into the account class
    }

}
    //admin only. loads all of the account data from their files into their classes
void scheduleType::addGroupAppointment() {
    string appointmentDetailsPlaceHolder;
    string namePlaceHolder;
        if (isAdmin == false){
        return
            }
        cout << "Enter the appointment details";
        cin >> appointmentDetailsPlaceHolder;
    bool isDone = false;
    
    while (!isDone){
        cout << "Enter the last name of the next person to be added to the group, or enter DONE to finish and send" << endl;
        cin >> namePlaceHolder;
        if (namePlaceHolder == "DONE"){
            isDone = true;
        }
        else {
            int index = scheduleType.lNameSearch(namePlaceHolder);
            //the above is a place holder for the last name search method
            if (index == -1){
                cout << "Account does not exist" << endl;
            }
            else {
                accounts[index].addAppointment(appointmentDetailsPlaceHolder);
                cout << namePlaceHolder << " has had the appointment added to their appointment book" << endl;
            }
    }
    //a while loop should be used to add a certain appointment to each account
}
    //admin only. adds an appointment to several account's appointment books
