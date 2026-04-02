#include "TicketService.h"
#include "Ticket.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Function to append a new ticket to the incident list
void appendTicket(vector<Ticket>& tickets) {
    Ticket ticket;
    int ticketNum = rand() % 100;
    string clientInfo, techSupport, issue;
    int dueDate;
    int folderNum;

    ticket.SetTicketNum(ticketNum);
    cout << "\nTicket number: " << ticketNum << endl;

    // Input client, technician, and issue information
    cout << "What is the client's name? ";
    cin.ignore();
    getline(cin, clientInfo);
    ticket.SetClientInfo(clientInfo);

    cout << "What is your name? ";
    getline(cin, techSupport);
    ticket.SetTechSupport(techSupport);

    cout << "What is the issue? ";
    cin >> issue;
    ticket.SetIssue(issue);

    // Generate a random due date (1 to 31 days)
    dueDate = rand() % 31 + 1;
    ticket.SetDueDate(dueDate);
    cout << "We will fix it in " << dueDate << " days." << endl;

    // Display priority based on due date
    cout << "Priority: " << ticket.GetPriority() << endl;

    tickets.push_back(ticket);
    cout << "\nIncident Successfully Added Successfully!" << endl;
}

// Function to create a new incident at a specified position
void createTicket(vector<Ticket>& tickets) {
    Ticket ticket;
    int ticketNum = rand() % 100;
    string clientInfo, techSupport, issue;
    int dueDate;
    int index = 0;

    ticket.SetTicketNum(ticketNum);
    cout << "\nTicket number: " << ticketNum << endl;

    // Ask for the index at which to insert the incident
    if (!tickets.empty()) {
        cout << "\nEnter the index number where you want to add this incident (0 to " << tickets.size() << "): ";
        cin >> index;

        if (index < 0 || index > tickets.size()) {
            cout << "\nInvalid index number. Must be between 0 and " << tickets.size() << "." << endl;
            return;
        }
    } else {
        cout << "\nIncident list is currently empty. Adding the incident in index number 1." << endl;
        index = 0;
    }

    // Input client, technician, and issue information
    cout << "\nWhat is the client's name? ";
    cin >> clientInfo;
    ticket.SetClientInfo(clientInfo);

    cout << "What is your name? ";
    cin >> techSupport;
    ticket.SetTechSupport(techSupport);

    cout << "What is the issue? ";
    cin >> issue;
    ticket.SetIssue(issue);

    // Generate a random due date
    dueDate = rand() % 31 + 1;
    ticket.SetDueDate(dueDate);
    cout << "We will fix it in " << dueDate << " days." << endl;

    cout << "Priority: " << ticket.GetPriority() << endl;

    // Insert the incident at the specified index
    tickets.insert(tickets.begin() + index, ticket);
    cout << "\nIncident Successfully Added at position " << index << "!" << endl;
}

// Function to remove an incident by ticket number
void removeTicket(vector<Ticket>& tickets) {
    if (tickets.empty()) {
        cout << "\nNo incidents to delete." << endl;
        return;
    }

    int ticketNum;
    cout << "\nEnter ticket number to delete an incident: ";
    cin >> ticketNum;

    bool found = false;
    for (auto it = tickets.begin(); it != tickets.end(); ++it) {
        if (it->GetTicketNum() == ticketNum) {
            // Display incident before deletion for debugging
            cout << "\nDeleting incident with ticket number: " << ticketNum << endl;
            it->Display();

            tickets.erase(it); // Erase the incident
            cout << "\nIncident with ticket number " << ticketNum << " has been deleted." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nNo incident found with ticket number " << ticketNum << endl;
    }
}

// Function to display incidents in reverse order of priority
void reverseTicket(vector<Ticket>& tickets) {
    Ticket ticket;
    if (tickets.empty()) {
        cout << "\nNo incidents to reverse." << endl;
        return;
    }

    cout << "\nShowing Incidents in reverse priority order." << endl;

    // Iterate through the incidents in reverse order
    for (int i = tickets.size() - 1; i >= 0; i--) {
       tickets[i].Display();
    }
    cout << endl;
}

// Function to sort incidents by priority
void sortTicket(vector<Ticket>& tickets) {
    if (tickets.empty()) {
        cout << "\nNo incidents to sort." << endl;
        return;
    }

    // Sort incidents based on priority (highest first)
    for (int i = 0; i < tickets.size() - 1; i++) {
        for (int j = 0; j < tickets.size() - i - 1; j++) {
            if (tickets[j].GetPriority() < tickets[j + 1].GetPriority()) {
                // Swap incidents[j] and incidents[j + 1]
                Ticket temp = tickets[j];
                tickets[j] = tickets[j + 1];
                tickets[j + 1] = temp;
            }
        }
    }

    cout << "\nIncident List (Top Priority First):" << endl;
    int index=1;
    for (const auto& ticket : tickets) {
        cout << "\n" << index << ")" << endl;
        ticket.Display();
        index++;
    }
}
// Function to search for an incident by ticket number
void searchTicket(vector<Ticket>& tickets){
    Ticket ticket;
    int ticketNum;

    cout << "Find your ticket via our Ticket Search Engine:" << endl;
    cin >> ticketNum;

    if (tickets.empty()) {
        cout << "\nNo incidents to search." << endl;
        return;
    }

    for (auto i = tickets.begin(); i != tickets.end(); i++) {
        if (ticketNum == i->GetTicketNum()) {
             i->Display();
            return;
        }
    }
    cout << "\nNo ticket found."<< endl;
}
// Function to filter incidents by priority level (highest or lowest)
void priorityTicket(vector<Ticket>& tickets) {
    int index=1;
    string choice;

    if (tickets.empty()) {
        cout << "\nThere are no incidents." << endl;
        return;
    }

    cout << "What priority do you want to search (lowest or highest): ";
    cin >> choice;

    // Convert choice to lowercase using a loop
    for (auto &ch : choice) {
        ch = tolower(ch);  // Convert each character to lowercase
    }

    if (choice == "highest") {
        // Display incidents with the highest priority (priority = 1)
        for (auto i = tickets.begin(); i != tickets.end(); i++) {
            if (i->GetPriority() == 1) {
                cout << "\n" << index << ")" << endl;
                i->Display();
                index++;
            }
        }
    } else if (choice == "lowest") {
        // Display incidents with the lowest priority (priority = 4)
        for (auto i = tickets.begin(); i != tickets.end(); i++) {
            if (i->GetPriority() == 4) {
                cout << "\n" << index << ")" << endl;
                i->Display();
                index++;
            }
        }
    } else {
        cout << "Please enter either 'lowest' or 'highest'." << endl;
    }

    cout << endl;
}

// Function to display all incidents
void displayAllTickets(const vector<Ticket>& tickets) {

    if (tickets.empty()) {
        cout << "\nNo incidents to display." << endl;
        return;
    }
    int i = 1;
    for (const auto& ticket : tickets) {
        cout << i << ")\n";
        ticket.Display();
        cout << endl;
        i++;
        }
}

// Function to update an incident's due date or technician
void updateTicket(vector<Ticket>& tickets) {
    if (tickets.empty()) {
        cout << "\nNo incidents to update." << endl;
        return;
    }

    int ticketNum;
    cout << "\nEnter the ticket number of the incident you want to update: ";
    cin >> ticketNum;

    bool found = false;
    for (auto& ticket : tickets) {
        if (ticket.GetTicketNum() == ticketNum) {
            found = true;
            ticket.Display();

            int choice;
            cout << "\nWhat would you like to update?" << endl;
            cout << "1) Update Due Date" << endl;
            cout << "2) Update Technician" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                int newDueDate;
                cout << "\nEnter new due date: ";
                cin >> newDueDate;
                ticket.SetDueDate(newDueDate);
                cout << "\nDue date updated successfully." << endl;
            } else if (choice == 2) {
                string newTechnician;
                cout << "\nEnter new technician name: ";
                cin.ignore(); // Clear input buffer
                getline(cin, newTechnician);
                ticket.SetTechSupport(newTechnician);
                cout << "\nTechnician updated successfully." << endl;
            } else {
                cout << "\nInvalid choice. Update canceled." << endl;
            }
            ticket.Display();
            break;
        }
    }

    if (!found) {
        cout << "\nNo incident found with ticket number " << ticketNum << endl;
    }
}
// Function to filter incidents based on a specific priority
void filterTicket(const vector<Ticket>& tickets) {
    int index=1;
    if (tickets.empty()) {
        cout << "\nNo incidents available to filter." << endl;
        return;
    }

    int filterPriority;
    cout << "\nEnter the priority level to filter incidents (1 - Low, 2 - Mid, 3 - High, 4 - Highest): ";
    cin >> filterPriority;

    vector<Ticket> filteredTickets;
    for (const auto& ticket : tickets) {
        if (ticket.GetPriority() == filterPriority) {
            filteredTickets.push_back(ticket);
        }
    }

    if (!filteredTickets.empty()) {
        cout << "\nFiltered Incidents with Priority Level " << filterPriority << ":" << endl;
        for (const auto& ticket : filteredTickets) {
            cout << "\n" << index << ")" << endl;
            ticket.Display();
            cout << endl;
            index++;
        }
    } else {
        cout << "\nNo incidents found with priority level " << filterPriority << endl;
    }
}

