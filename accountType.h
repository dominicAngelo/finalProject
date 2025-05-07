#ifndef account_test
#define account_test
#include <vector>

using namespace std;


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

	void addAccount(const string& userName);
	//adds an account name to the accounts array

	void removeAccount(const string& userName);
	//removes an account name from the accounts array

	void addPassword(const string& password);
	//adds a password to the passwords array

	void removePassword(const string& password);
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

private:
	string *appointments;
	//Pointer for the appointments array

	int appointmentSize;
	//This is for the appointment array size

	string *accounts;
	//Pointer for the accounts array

	int accountsSize;
	//This is for the accounts array size

	string *passwords;
	//Pointer for the passwords array

	int passwordsSize;
	//This is for the passwords array size
		
	string fname, lname;
	//The name associated with the account. used to access it's file
};

#endif#pragma once
