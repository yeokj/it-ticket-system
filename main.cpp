// main file contains menu for the program
//incident.h file contains member functions of an incident
//incidentfunctions.h file conatins memebers functions of incident as a object vector
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
#include "Ticket.h"
#include "TicketService.h"

using namespace std;

int main () {

    vector<Ticket> tickets; // Stores all incident tickets
    srand(time(0)); // Initialize random seed for generating ticket numbers
    int ticketNum = rand() % 100;
    string clientInfo;
    string techSupport;
    string Issue;
    int dueDate;
    int Priority;
    string username;
    string password;

    // Sample incidents for testing purposes
    tickets.push_back(Ticket(1, "John Doe", "Jane Smith", "System Crash", 1));  // Priority 1
    tickets.push_back(Ticket(2, "Alice Brown", "Tom Johnson", "Network Issue", 5)); // Priority 2
    tickets.push_back(Ticket(3, "Mike Davis", "Emma Wilson", "Software Bug", 8));  // Priority 3
    tickets.push_back(Ticket(4, "Sara Connor", "Kyle Reese", "Hardware Failure", 12)); // Priority 3
    tickets.push_back(Ticket(5, "Bruce Wayne", "Alfred Pennyworth", "Power Outage", 15)); // Priority 4
    tickets.push_back(Ticket(6, "Clark Kent", "Lois Lane", "Login Failure", 20)); // Priority 4

    cout << "Welcome to York College Incident Management" << endl;

    // Login loop for authentication
    while (true) {
        cout << "Enter Username: ";
        getline(cin, username);
        cout << "Password: ";
        getline(cin, password);


        // use username and password to log in
        if (username == "Admin" && password == "York123") {
            cout << "Login successful!" << endl;
            break;
        } else {
            cout << "Username or Password is incorrect! Try again!" << endl;
        }
    }

    cout << "What can we do for you today?" << endl;

    int choice;

    // Main program loop for menu operations
    while (true){

        cout << "\nIncident Ticket Management Menu" << endl;
        cout << "----------------------------------" << endl;
        cout << "1) Append an Incident" << endl;
        cout << "2) Create an Incident" << endl;
        cout << "3) Remove an Incident" << endl;
        cout << "4) Sort the Incidents" << endl;
        cout << "5) Search for an Incident" << endl;
        cout << "6) Find Highest/Lowest Priority Incident" << endl;
        cout << "7) Reverse the order of Incidents" << endl;
        cout << "8) Display the Incidents" << endl;
        cout << "9) Update details of an Incident" << endl;
        cout << "10) Filter the Incidents" << endl;
        cout << "0) Exit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Exiting program. Thank you!" << endl;
                return 0;
            case 1:
                appendTicket(tickets); // fatima because create and append are same
                break;
            case 2:
                createTicket(tickets); // fatima
                break;
            case 3:
                removeTicket(tickets); // daiwe
                break;
            case 4:
                sortTicket(tickets); // kyame
                break;
            case 5:
                searchTicket(tickets); // kyame
                break;
            case 6:
                priorityTicket(tickets); // daiwe
                break;
            case 7:
                reverseTicket(tickets); //kyame
                break;
            case 8:
                displayAllTickets(tickets); // daiwe
                break;
            case 9:
                updateTicket(tickets); // fatima
                break;
            case 10:
                filterTicket(tickets); // fatima
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }


    return 0;
}
