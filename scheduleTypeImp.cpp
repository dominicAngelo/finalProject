#include "scheduleType.h"
#include <fstream>
#include <iostream>

void scheduleType::adminMenu() {
    int choice;
    do {
        std::cout << "\n=== Admin Menu ===\n";
        std::cout << "1. Load All Data\n";
        std::cout << "2. Add Group Appointment\n";
        std::cout << "3. Export Master Data\n";
        std::cout << "4. Modify specific account's appointments\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            loadAllData();
            break;
        case 2:
            addGroupAppointment();
                break;
        case 3:
            exportMasterData("master.txt"); //Use your actual filename
                break;
        case 4: {
            std::cout << "\n=== Account List ===\n";
            for (int i = 0; i < accountNum; ++i) {
                std::cout << i + 1 << ". " << accounts[i].getLname() << std::endl;
            }

            int accountChoice;
            std::cout << "Select an account by number: ";
            std::cin >> accountChoice;
            if (accountChoice < 1 || accountChoice > accountNum) {
                std::cout << "Invalid account selection.\n";
            }
            else {
                // simulate login as that account
                currentAccount = accounts[accountChoice - 1].getLname();
                isAdmin = false; // treat this as a user, not admin
                accounts[accountChoice - 1].normalMenu();
                isAdmin = true; // reset admin flag after done
            }
            break;
        }

        case 5:
            std::cout << "Exiting admin menu.\n";
            break;
        default:
            std::cout << "Invalid choice.\n";
        }
    } while (choice != 5);
}

void scheduleType::readMasterData(std::string filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        nonexistentFile(filename);
        std::ifstream file(filename);
    }

    std::string lname, password, dummy;

    while (!file.eof()) {
        std::getline(file, lname);
        std::getline(file, password);
        //here should be the code to add the above info to the relevant arrays
    }

    file.close();
}

 void scheduleType::appendList(accountType account) {
     accounts[accountNum] = account;
     accountNum++;
 }

void scheduleType::removeList(int location){
    if (location <0 || location >= length)
        cout << "The location of the item to be removed " << "is out of range." << endl;
    else
    {
        for (int i = location; i < length - 1; i++)
            list[i] = list[i+1];
        length--;
    }
}

void scheduleType::print() const{
    {
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";
    cout << endl;
    }
}

void scheduleType::nonexistentFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        // File does not exist, create it
        std::ofstream newFile(filename);
        if (newFile) {
            std::cout << filename << " created" << std::endl;
        }
        else {
            std::cerr << "Error creating: " << filename << std::endl;
        }
    }
    else {
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
        if (accounts[i].getLname() == searchName) {
            return i;
        }
    }
    return -1;
    //-1 should only be returned if the lastname is not found
}

void scheduleType::loadAllData() {
    if (isAdmin == false) {
        return;
    }
    for (int i = 0; i < accountNum; i++) {
        accounts[i].loadData();
    }

}
//admin only. loads all of the account data from their files into their classes
void scheduleType::addGroupAppointment() {
    string descPlaceHolder;
    string namePlaceHolder;
    int year, month, day, hour, minute;
    if (isAdmin == false) {
        return;
    }
    cout << "Enter the appointment details";
    cin >> descPlaceHolder >> namePlaceHolder >> year >> month >> day >> hour >> minute;
    bool isDone = false;

    while (!isDone) {
        cout << "Enter the last name of the next person to be added to the group, or enter DONE to finish and send" << endl;
        cin >> namePlaceHolder;
        if (namePlaceHolder == "DONE") {
            isDone = true;
        }
        else {
            int index = lNameSearch(namePlaceHolder);
            //the above is a place holder for the last name search method
            if (index == -1) {
                cout << "Account does not exist" << endl;
            }
            else {
                accounts[index].addAppointment(year, month, day, hour, minute, descPlaceHolder);
                cout << namePlaceHolder << " has had the appointment added to their appointment book" << endl;
            }
        }
        //a while loop should be used to add a certain appointment to each account
    }
    //admin only. adds an appointment to several account's appointment books
