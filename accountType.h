#ifndef account_test;
#define account_test
using namespace std;

#include "appointmentType.h"
#include "orderedArrayListType.h"

class accountType {
public:
	void readData();
	//reads the data from the file associated with the account

	void createAppointmentsBook();
	//creates the account book array

	void addAppointment();
	//adds an appointment to the appointments list

	void deleteAppointment();
	//remove an appointment from the appointments list
protected:
	appointmentType *appointments;
	//pointer holding the appointments array
	string fname, lname;
	//the name associated with the account. used to access it's file
};

#endif
