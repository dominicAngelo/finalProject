#ifndef account_test
#define account_test
using namespace std;

#include "appointmentType.h"

class accountType {
public:
	void normalMenu();
	//the menu function

	void readData();
	//reads the data from the file associated with the account

	void addAppointment(int day, int month, int year, int hour, int minute, string desc);
	//adds an appointment to the appointments list


	void deleteAppointment(int index);
	//remove an appointment from the appointments list

	void addAccount(string userName);
	//adds an account name to the accounts array

	void removeAccount(int index);
	//removes an account name from the accounts array

	void addPassword(string password);
	//adds a password to the passwords array

	void removePassword(int index);
	//removes a password from the passwords array

	void normalMenu();
	//added a public normal user menu

	string getLname() {
		return lname;
	}

	accountType() {
		fname = "";
		lname = "";

	}

protected:
	appointmentType appointments[20];
	//pointer holding the appointments array
	appointmentType accounts[20];
	//pointer holding the accounts array
	appointmentType passwords[20];
	//pointer holding the passwords array

	string fname, lname;
	//the name associated with the account. used to access it's file
};

#endif
