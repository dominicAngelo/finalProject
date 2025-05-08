#include "accountType.h"
#include "exporter.h"
#include <iostream>

using namespace std;

int main() 
{
    //This is to set everything so the program can run.
    accountType account;
    int choice;
    string username, password, date, description;

    //This loops until the exit button is pressed, which allows for the user to select more than one option per session.
    while (true) {
        //This is the display for the menu, with the number the user enters triggering the switch, with the number entered bringing up different cases.
        cout << "1. Add Account\n2. Login\n3. Add Appointment\n4. Remove Appointment\n5. View Appointments\n6. Export to file\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            //This runs the addAccount logic, prompting the user to enter the username and password to add to the arrays.
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            account.addAccount(username, password);
            break;

        case 2:
            //This calls the authentication logic, and prompts the user to enter the username or password. 
            //If the username is not in the array or the password isn't correct, it will say its invalid.
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            if (account.login(username, password)) {
                cout << "Login successful!\n";
            }
            else {
                cout << "Invalid username or password.\n";
            }
            break;

        case 3:
            //This promts the user to enter the date and description for the appointments, and runs the logic to add it to the array.
            cout << "Enter date (YYYY-MM-DD): ";
            cin >> date;
            cout << "Enter description: ";
            cin.ignore();
            getline(cin, description);
            account.addAppointment(date, description);
            break;

        case 4:
            //This prompts the user to enter a date to remove the respective appointment.
            cout << "Enter date of appointment to remove (YYYY-MM-DD): ";
            cin >> date;
            account.removeAppointment(date);
            break;

        case 5:
            //This runs the print logic to show the appointments in the program.
            account.viewAppointments();
            break;

        case 6:
            //This triggers the export logic, which creates the schedule.txt file if none exists.
            exportToFile(account.appointments, "schedule.txt");
            break;

        case 7:
            //This is the exit logic, which closes the program.
            return 0;
        default:
            //If anything other than numbers fron 1-7 are entered, this runs.
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
