#include "appointmentType.h"
#include <string>

void appointmentType::changeDate(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
	//changes the date to the values in the parameters
}

void appointmentType::changeTime(int h, int m) {
	hour = h;
	minute = m;
}

void appointmentType::changeDescription(string desc) {
	description = desc;
	//changes the description to the string in the parameter
}

void appointmentType::removeAppointment(appointmentType appointment) {
	year = 0;
	month = 0;
	day = 0;
	hour = 0;
	minute = 0;
	description = "";
}

bool appointmentType::isEmpty() const {
    return (description == "" && year == 0 && month == 0 && day == 0);  // or check date fields if you prefer
}

string appointmentType::getDescription(appointmentType appointment) const {
	return appointment.description;
}

string appointmentType::getDate(appointmentType appointment) const {
	string date = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
	return date;
} 

string appointmentType::getTime(appointmentType appointment) const {
	string time = to_string(hour) + ":" + to_string(minute);
	return time;
}

