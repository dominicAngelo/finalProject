#ifndef EXPORTER_H
#define EXPORTER_H

#include "accountType.h"
#include <vector>
#include <string>

using namespace std;

//This header file is meant to store all member functions that export to txt files
//The one below is to export the schedule array to a txt file
void exportToFile(const vector<Appointment>& appointments, const string& filename);

#endif
