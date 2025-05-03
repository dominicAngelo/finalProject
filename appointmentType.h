#ifndef appointment_test
#define appointment_test
#include <string>

using namespace std;

class appointmentType {
public:
	void changeDate(int y, int m, int d);
	//changes the date to the variables in the parameters
	void changeDescription(string desc);
	//changes the description to what is in the parameter
	bool isEmpty() const;
	//checks if the appointment is empty
	appointmentType() {
		year = 0;
		month = 0;
		day = 0;
		description = "";
	}
	//default constructor
	appointmentType(int yr, int mon, int d, int hr, int min, string desc) {
		year = yr;
		month = mon;
		day = d;
		hour = hr;
		minute = min;
		description = desc;
	}
	//constructor with parameters
private:
	int year;
	int month;
	int day;
	int minute;
	int hour;
	int id;
	string description;
};



#endif
