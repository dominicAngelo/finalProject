
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

        accountType dummy;

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
                accounts.retrieveAt(i, dummy);
                std::cout << i + 1 << ". " << dummy.getLname() << std::endl;
            }

            int accountChoice;
            std::cout << "Select an account by number: ";
            std::cin >> accountChoice;
            if (accountChoice < 1 || accountChoice > accountNum) {
                std::cout << "Invalid account selection.\n";
            }
            else {
                // simulate login as that account
                accounts.retrieveAt(accountChoice - 1, dummy);
                currentAccount = dummy.getLname();
                isAdmin = false; // treat this as a user, not admin
                dummy.normalMenu();
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
    accounts.insert(account);
    accountNum++;
}

void scheduleType::removeList(int location) {
    if (location < 0 || location >= accountNum)
        cout << "The location of the item to be removed " << "is out of range." << endl;
    else
    {
        accounts.removeAt(location);
    }
}

void scheduleType::printAll() const {
    {
        for (int i = 0; i < accountNum; i++) {
            accountType dummy;
            accounts.retrieveAt(i, dummy);
            cout << dummy.getLname() << " ";
        }
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
    std::cin >> username;
    while (names.seqSearch(username) == -1) {
        std::cout << "Invalid username." << std::endl;
        std::cout << "Enter Username." << std::endl;
        std::string username;
        std::cin >> username;
    }
    int nameIndex = names.seqSearch(username);
    std::cout << "Enter Password." << std::endl;
    std::string password;
    // There should be a function to check if the password is valid.
    std::cin >> password;
    string currentPassword;
    passwords.retrieveAt(nameIndex, currentPassword);
    while (currentPassword != password) {
        std::cout << "Bad password" << std::endl;
        std::cout << "Enter Password." << std::endl;
        std::cin >> password;
    }
}

int scheduleType::lNameSearch(string searchName) {
    accountType dummy;
    for (int i = 0; i < accountNum; i++) {
        accounts.retrieveAt(i, dummy);
        if (dummy.getLname() == searchName) {
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
    accountType dummy;
    for (int i = 0; i < accountNum; i++) {
        accounts.retrieveAt(i, dummy);
        dummy.readData();
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
                accountType dummy;
                accounts.retrieveAt(index, dummy);
                dummy.addAppointment(year, month, day, hour, minute, descPlaceHolder);
                accounts.replaceAt(index, dummy);
                ;
                cout << namePlaceHolder << " has had the appointment added to their appointment book" << endl;
            }
        }
        //a while loop should be used to add a certain appointment to each account
    }
    //admin only. adds an appointment to several account's appointment books
}

void scheduleType::exportMasterData(string filename) {

}
//exports all of the current master data to the master file

void scheduleType::createAccountBook() {

}
//creates the account array
