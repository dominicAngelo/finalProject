#include <fstream>
#include "scheduleType.h"

using namespace std;

void scheduleType::readMasterData(string filename) {
	string placeholderNamesArray[100];
	string placeholderPasswordsArray[100];
	//this data is a placeholder until the dynamic arrays are implimented 
	ifstream inData;
	inData.open(filename);
	if (!file) {
        std::cerr << "Error opening masterfile: " << filename << std::endl;
        return;
    	}
	//file name should be the masterfile
	inData >> adminName >> adminPassword;
	//the data in the files should contain the last name, the passwords, and have no spaces. 
	int i = 0;
	while (!inData.eof() and (i < 100)) {
		inData >> placeholderNamesArray[i] >> placeholderPasswordsArray[i];
		i++;
	}
	if (i < 100) {
		cout << "Too much data. Excess accounts have been lost";
	}
	inData.close();
}

void scheduleType::exportMasterData(string filename) {
	string placeholderNamesArray[100];
	string placeholderPasswordsArray[100];
	//this data is a placeholder until the dynamic arrays are implimented 
	int length = 5;
	//length should be replaced with the int keeping track of the length of the account array as soon as possible
	ofstream outData;
	outData.open(filename);
	//file name should be the masterfile
	if (!file) {
        std::cerr << "Error opening masterfile: " << filename << std::endl;
        return;
    	}
	outData << adminName << endl << adminPassword << endl << endl;
	for (int i = 0; i < length; i++) {
		outData << placeholderNamesArray[i] << endl << placeholderPasswordsArray << endl << endl;
	}
	outData.close();
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
