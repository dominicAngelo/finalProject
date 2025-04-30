#include <iostream>
#include <vector>
#include "appointmentType.h"

class ScheduleType {

    //public variables, only included the array
    public:
        std::vector<appointmentType> appointmentArr;

    //initializes the array, clears out all values (in case we need an empty array)
    void initArray() {
        appointmentArr.clear();
    }

    //adds one appointment to the array after the function is provided with the necessary values
    void appendArray(int y, int m, int d, string desc) {
        appointmentArr.push_back(appointmentType(y, m, d, desc));
    }

};
