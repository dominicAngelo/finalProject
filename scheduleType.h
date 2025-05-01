#include <iostream>
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
private:
    //TO DO put the dynamic array here
    //variable for the appointment array
    string adminName;
    string adminPassword;
};
