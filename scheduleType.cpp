#include <fstream>
#include "scheduleType.h"

using namespace std;

void scheduleType::readMasterData(string filename) {
	string placeholderNamesArray[100];
	string placeholderPasswordsArray[100];
	string adminName, adminPassword;
	//this data is a placeholder until the dynamic arrays are implimented 
	ifstream inData;
	inData.open(filename);
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
}

