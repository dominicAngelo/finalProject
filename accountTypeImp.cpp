#include "accountType.h"
#include <algorithm>
#include <iostream>

using namespace std;

//This is for the addAccount member. This adds the inputted username and password into their respective arrays and pushes them back.
void accountType::addAccount(const string& username, const string& password) 
{
    usernames.push_back(username);
    passwords.push_back(password);
}

//This is for the login member, which is self explanatory. It checks the username and password arrays for anything that matches what the user inputted.
bool accountType::login(const string& username, const string& password) 
{//i in this is set by the username inputted, which then looks for the respective password
    for (size_t i = 0; i < usernames.size(); ++i) {
        if (usernames[i] == username && passwords[i] == password) {
            return true;
        }
    }
    return false;
}

//This adds the appointment date and description to the appointments array and runs the sortAppointments member (shown later).
void accountType::addAppointment(const string& date, const string& description) {
    appointments.push_back({ date, description });
    sortAppointments();
}

//This removes an appointment based on the date the user inputs.
void accountType::removeAppointment(const string& date) {
    appointments.erase(remove_if(appointments.begin(), appointments.end(),
        [&date](const Appointment& app) { return app.date == date; }),
        appointments.end());
}

//This prints the appointments array for viewing within the program.
void accountType::viewAppointments() {
    for (const auto& app : appointments) {
        cout << "Date: " << app.date << ", Description: " << app.description << endl;
    }
}

//This sorts the appointments by date. The lowest date value gets put at the top of the array list while the largest gets put on the bottom. 
//This is run every time the addAppointment function is run.
void accountType::sortAppointments() {
    sort(appointments.begin(), appointments.end(), [](const Appointment& a, const Appointment& b) { return a.date < b.date; });
}
