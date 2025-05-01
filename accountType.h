#ifndef account_test;
#define account_test

#include "appointmentType.h"
#include "orderedArrayListType.h"

class accountType {
public:
	void readData();
	//reads the data from the file associated with the account
	void addAppointment();
	//adds an appointment to the appointments list
	void deleteAppointment();
	//remove an appointment from the appointments list
protected:
	appointmentType appointments[100];
	//the above is a placeholder. I originally tried to use a linked list, but couldn't figure out a good way to have it return the needed data from a search. Try to impliment a dynamic array instead
	string fname, lname;
	//the name associated with the account. used to access it's file
};

#endif
