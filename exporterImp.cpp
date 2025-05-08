#include "exporter.h"
#include <fstream>
#include <iostream>

//This definition takes the appointments array and exports it to a txt file
void exportToFile(const vector<Appointment>& appointments, const string& filename)
{
	ofstream outFile(filename);
	if (!outFile)
	{
		//If there is a problem with opening the file, this will trigger, which is unlikely as it will create a new file if it can't find one
		cerr << "Error: Could not open the file for writting. \n";
		return;
	}
	//This exports the dates and descriptions of the appointments to the schedule file. The colon ": " is to separate the dates and descriptions of the appointment
	for (const auto& appointment : appointments)
	{
		outFile << appointment.date << ": " << appointment.description << "\n";

	}
	outFile.close();
	cout << "The schedule has been successfully exported to " << filename << "\n";
}
