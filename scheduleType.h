include <iostream>
#include "appointmentType.h"
#include "orderedArrayListType.h"

class scheduleType {

    //public variables, only included the array
public:


    //initializes the array, clears out all values (in case we need an empty array)
    void initArray() {
    }

    //adds one appointment to the array after the function is provided with the necessary values
    void appendArray(int y, int m, int d, string desc) {
    }

    void readMasterData(string filename);
    //reads all of the data from the master file 

    void exportMasterData(string filename);
    //exports all of the current master data to the master file
private:
    appointmentType *appointments;
    //variable for the appointments array
    string adminName;
    string adminPassword;
};
