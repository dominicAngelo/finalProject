#ifndef appointment_test
#define appointment_test
#include <string>

using namespace std;

class appointmentType {
public:

	void changeDate(int y, int m, int d);
	void changeTime(int m, int h);
	void changeDescription(string desc); 
	void removeAppointment(appointmentType appointment);
	bool isEmpty() const;
	string getDescription(appointmentType appointment) const;
	string getDate(appointmentType appointment) const; 
	string getTime(appointmentType appointment) const;              

	appointmentType() {
		year = 0;
		month = 0;
		day = 0;
		hour = 0;
		minute = 0;
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
	string description;
};

#endif