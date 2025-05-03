#include <iostream>
#include "accountType.h"
#include "orderedArrayListType.h"

class scheduleType {

    //public variables, only included the array
public:


    //initializes the array, clears out all values (in case we need an empty array)
    void initArray() {
    }

    void readMasterData(string filename);
    //reads all of the data from the master file 

    void appendList(accountType account);
    //Adds things to the array

    void removeList(int location);
    //Removes things from the array

    void printList() const;

    void exportMasterData(string filename);
    //exports all of the current master data to the master file

    void createAccountBook();
    //creates the account array

    void nonexistentFile(const std::string& filename);
    //checks if the file exists

    void login();
    //handles logging in

    int lNameSearch(string searchName);
    //searches for a last name in the accounts array and returns the index. If none is found, it returns -1

    void loadAllData();
    //admin only. loads all of the account data from their files into their classes

    void addGroupAppointment();
    //admin only. adds an appointment to several account's appointment books

private:
    void adminMenu(); // Added: handles admin-only options

    accountType* accounts;
    //variable for the accounts array
    int accountNum;
    //variable for the number of accounts
    string adminName;
    string adminPassword;
    string currentAccount;
    bool isAdmin;
};
