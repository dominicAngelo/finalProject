
#include "appointmentType.h"

void appointmentType::changeDate(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
	//changes the date to the values in the parameters
}

void appointmentType::changeDescription(string desc) {
	description = desc;
	//changes the description to the string in the parameter
}
bool appointmentType::isEmpty() const {
    return (description == "" and year == 0 and month == 0 and day == 0);  // or check date fields if you prefer
}
