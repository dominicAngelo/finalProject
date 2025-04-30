#include <iostream>
#include <vector>
#include "appointmentType.h"

class ScheduleType {

    //public variables, only included the array
public:


    //initializes the array, clears out all values (in case we need an empty array)
    void initArray() {
        appointmentArr.clear();
    }

    //adds one appointment to the array after the function is provided with the necessary values
    void appendArray(int y, int m, int d, string desc) {
        appointmentArr.push_back(appointmentType(y, m, d, desc));
    }

    void readMasterData(string filename);
    //reads all of the data from the master file 
private:
    std::vector<appointmentType> appointmentArr;
    //variable for the appointment array
};
