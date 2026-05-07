#include "Ticket.h"
#include "TicketService.h"
#include "TicketHelper.h"
#include <stdlib.h>
#include <algorithm>

void TicketService::createTicket(std::vector<Ticket> &tickets) {
    Ticket ticket;
    int ticketId = std::rand() % 100;
    std::string clientName, technicianName, issueDescription, dueDate;

    ticket.setTicketId(ticketId);
    std::cout << "\nTicket number: " << ticketId << std::endl;

    // Input client, technician, and issue information
    std::cout << "\nWhat is the client's name? ";
    std::getline(std::cin >> std::ws, clientName);
    ticket.setClientName(clientName);

    std::cout << "What is your name? ";
    std::cin >> technicianName;
    ticket.setTechnicianName(technicianName);

    std::cout << "What is the issue? ";
    std::cin >> issueDescription;
    ticket.setIssueDescription(issueDescription);

    bool isValid = false;
    while (!isValid) {
        std::cout << "Enter the date of the issue in this format ('YYY-MM-DD'): " << std::endl;
        std::cin >> dueDate;

        if (TicketHelper::validateDate(dueDate)) {
            isValid = true;
        }
        else {
            std::cout << "Invalid entry, please try again" << std::endl;
        }
    }
    ticket.setDueDate(dueDate);

    int p = TicketHelper::calculatePriority(dueDate);
    ticket.setPriorityLevel(p);

    std::cout << "Auto-assigned priority level: " << ticket.getPriorityLevel() << std::endl;

    // Insert the incident at the specified index
    tickets.push_back(ticket); 
    std::cout << "\nIncident Added Successfully!" << std::endl;
}

void TicketService::removeTicket(std::vector<Ticket> &tickets) {
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

void TicketService::organizeTickets(std::vector<Ticket> &tickets) {
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

void TicketService::displayTickets(const std::vector<Ticket> &tickets) {
    if (tickets.empty()) {
        std::cout << "\nNo incidents to display." << std::endl;
        return;
    }

    int i = 1;
    for (const auto &ticket : tickets) {
        std::cout << i << ")\n";
        ticket.display();
        std::cout << std::endl;
        ++i;
    }
}

void TicketService::updateTicket(std::vector<Ticket> &tickets) {
    if (tickets.empty()) {
        std::cout << "\nNo incidents to update." << std::endl;
        return;
    }

    std::cout <<"Please select a ticket to update.\n";

    displayTickets(tickets);

    int ticketChoice;
    while (true) {
        std::cout <<"Select a ticket number (1 - " << tickets.size() << "):";
        std::cin >> ticketChoice;

        if ((ticketChoice >= 1) && (ticketChoice <= tickets.size())) {
            std::cout << "Updating ticket #" << ticketChoice;
            break;
        }
        std::cout << "Invalid input, please try again\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    bool done = false;
    int statusChoice;
    while (!done) {
        std::cout << "\nWhat would you like to update?\n";
        std::cout << "1) Update status to 'In Progress'\n";
        std::cout << "2) Update status to 'On Hold'\n";
        std::cout << "3) Update status to 'Resolved'\n";
        std::cout << "4) Update Technicain\n";
        std::cout << "5) Exit\n"; 
        
        std::cin >> statusChoice;

        switch (statusChoice) {
            case 1:
                tickets[ticketChoice - 1].setIssueStatus("In Progress");
                done = true;
                break;
            case 2:
                tickets[ticketChoice - 1].setIssueStatus("On Hold");
                done = true;
                break;
            case 3:
                tickets[ticketChoice - 1].setIssueStatus("Resolved");
                done = true;
                break;
            case 4: {
                std::string newTechnician;
                std::cout << "Enter technician's name: ";
                std::getline(std::cin >> std::ws, newTechnician);
                tickets[ticketChoice - 1].setTechnicianName(newTechnician);
                done = true;
                break;
            }
            case 5:
                std::cout << "Update cancelled\n";
                return;
            default:
                std::cout << "Invalid entry, please try again\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                break;
        }
    }
    std::cout << "Ticket updated successfully\n";
}

void TicketService::findTickets(const std::vector<Ticket> &tickets) {
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