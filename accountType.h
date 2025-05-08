#pragma once
#ifndef NEWACCOUNTTYPE_H
#define NEWACCOUNTTYPE_H

#include <string>
#include <vector>

using namespace std;
//This is the struct for Appointment, which holds the date and description variables of the program
struct Appointment 
{
    string date;
    string description;
};

class accountType 
{
public:
    //These are the three arrays that are used in the program, with the Appointment struct being used in the appointments array
    vector<string> usernames;
    vector<string> passwords;
    vector<Appointment> appointments;

    //This is the member function to add an account, which prompts the user to enter their username and password
    void addAccount(const string& username, const string& password);

    //This is the member function to log in, which is similar to the above member except it checks the usernames and passwords arrays for things that match
    bool login(const string& username, const string& password);

    //This is the member function to add an appointment to the schedule array, which prompts you to add the date and description of the appointment
    void addAppointment(const string& date, const string& description);

    //This is the member function to remove an appointment from the array, which removes based on the date
    void removeAppointment(const string& date);
    
    //This is the member function that prints the appointments array
    void viewAppointments();

    //This is the member function that sorts the appointments array by date
    void sortAppointments();
};

#endif
