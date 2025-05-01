#ifndef adminAccount
#define adminAccount

#include <iostream>
#include "accountType.h"

class adminType: public accountType {
public:
	void loadAllData();
	//loads all of the account data from their files into their classes
	void addGroupAppointment();
	//adds an appointment to several account's appointment books

private:


};

#endif
