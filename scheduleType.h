include <iostream>
#include "accountType.h"
#include "orderedArrayListType.h"

class scheduleType {

    //public variables, only included the array
public:


    //initializes the array, clears out all values (in case we need an empty array)
    void initArray() {
    }

    //adds one appointment to the array after the function is provided with the necessary values
    void appendArray(int y, int m, int d, string desc) {
    }

    void readMasterData(string filename);
    //reads all of the data from the master file 

    void exportMasterData(string filename);
    //exports all of the current master data to the master file

    void createAccountBook();
    //creates the account array

    void nonexistentFile(const std::string& filename);
    //checks if the file exists

    void login();
    //handles logging in

    int lNameSearch();
    //searches for a last name in the accounts array and returns the index. If none is found, it returns -1

    void loadAllData();
    //admin only. loads all of the account data from their files into their classes

    void addGroupAppointment();
    //admin only. adds an appointment to several account's appointment books

private:
    accountType *accounts;
    //variable for the accounts array
    string adminName;
    string adminPassword;
    string currentAccount;
    bool isAdmin;
};
