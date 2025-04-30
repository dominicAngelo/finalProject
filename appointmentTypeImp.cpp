
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
