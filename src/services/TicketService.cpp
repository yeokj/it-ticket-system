#include "Ticket.h"
#include "TicketService.h"
#include "TicketHelper.h"
#include <stdlib.h>
#include <algorithm>

void TicketService::createTicket(std::vector<Ticket> &tickets) {
    std::shared_ptr<Client> client;
    std::shared_ptr<Technician> technician;
    Ticket ticket;

    int ticketID = TicketHelper::generateTicket(ticketSet);
    if (ticketID == 0) {
        std::cout << "Error: Ticket database is full. Cannot create new ticket.\n";
        return;
    }
    ticket.setTicketId(ticketID);
    std::cout << "\nTicket number: " << ticketID << std::endl;

    std::string clientName, clientEmail, clientCompany;

    bool isClientEmailValid = false;
    while (!isClientEmailValid) {
        std::cout << "\nEnter the client's email: " << std::endl;
        std::getline(std::cin >> std::ws, clientEmail);

        if (TicketHelper::validateEmail(clientEmail)) {
            isClientEmailValid = true;
        }
        else {
            std::cout << "Invalid email format. Please try again\n";
        }
    }

    client = TicketHelper::verifyClientEmail(tickets, clientEmail);

    if (client != nullptr) {
        std::cout << "Welcome back " << client->getName() << std::endl;
        ticket.setClient(client);
    }
    else {
        std::cout << "\nEnter the client's name? ";
        std::getline(std::cin >> std::ws, clientName);

        std::cout << "\nEnter the client's company: " << std::endl;
        std::getline(std::cin >> std::ws, clientCompany);

        client = std::make_shared<Client>(nextClientId, clientName, clientEmail, clientCompany);
        ticket.setClient(client);
        ++nextClientId;
    }

    std::string techName, techEmail, techDepartment;

    bool isTechEmailValid = false;
    while (!isTechEmailValid) {
        std::cout << "Enter the technician's email: " << std::endl;
        std::getline(std::cin >> std::ws, techEmail);

        if (TicketHelper::validateEmail(techEmail)) {
            isTechEmailValid = true;
        }
        else {
            std::cout << "Invalid email format. Please try again\n";
        }
    }

    technician = TicketHelper::verifyTechEmail(tickets, techEmail);

    if (technician != nullptr) {
        std::cout << "Hey " << technician->getName() << ", you got this!" << std::endl;
        ticket.setTechnician(technician);
    }
    else {
        int techEmplID = 1000 + nextTechId;

        std::cout << "Enter the technician's name? ";
        std::getline(std::cin >> std::ws, techName);

        std::cout << "Enter the technician's department: " << std::endl;
        std::getline(std::cin >> std::ws, techDepartment);

        technician = std::make_shared<Technician>(nextTechId, techName, techEmail, techEmplID, techDepartment);
        ticket.setTechnician(technician);
        ++nextTechId;
    }

    std::string issueDescription, dueDate;

    std::cout << "Enter the client's issue? ";
    std::getline(std::cin >> std::ws, issueDescription);
    ticket.setIssueDescription(issueDescription);

    bool isValid = false;
    while (!isValid) {
        std::cout << "Enter the date of the issue in this format ('YYY-MM-DD'): ";
        std::cin >> dueDate;

        if (TicketHelper::validateDate(dueDate)) {
            isValid = true;
        }
        else {
            std::cout << "\nInvalid entry, please try again.\n";
        }
    }
    ticket.setDueDate(dueDate);

    int p = TicketHelper::calculatePriority(dueDate);
    ticket.setPriorityLevel(p);

    std::cout << "Auto-assigned priority level: " << ticket.getPriorityLevel() << std::endl;

    tickets.push_back(ticket); 
    std::cout << "\nTicket Successfully Created!" << std::endl;
}

void TicketService::removeTicket(std::vector<Ticket> &tickets) {
    if (tickets.empty()) {
        std::cout << "\nNo tickets to delete." << std::endl;
        return;
    }

    displayTickets(tickets);

    int ticketChoice;

    while (true) {
        std::cout << "Select a ticket from (1 - " << tickets.size() << ") to remove: ";
        std::cin >> ticketChoice;

        if ((ticketChoice >= 1) && (ticketChoice <= tickets.size())) {
            int targetIndex = ticketChoice - 1;
            int idToRemove = tickets[targetIndex].getTicketId();

            tickets.erase(tickets.begin() + targetIndex);
            ticketSet.erase(idToRemove);

            std::cout << "Ticket successfully deleted\n";
            break;
        }
        else {
            std::cout << "Invalid input, please try again\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }
}

void TicketService::organizeTickets(std::vector<Ticket> &tickets) {
    if (tickets.empty()) {
        std::cout << "\nNo tickets to sort." << std::endl;
        return;
    }

    std::vector<Ticket> tempTickets = tickets;
    int sortChoice;

    while (true) {
        std::cout << "How would you like to sort the tickets\n";
        std::cout << "\n1) Ascending Order via Priority Level\n";
        std::cout << "2) Descending Order via Priority Level\n";
        std::cout << "3) Ascending Order via Due Date\n";
        std::cout << "4) Descending Order via Due Date\n";
        std::cout << "5) Reverse Order\n";
        std::cout << "6) Exit\n";

        std::cin >> sortChoice;

        switch (sortChoice) {
        case 1:
            TicketHelper::sortPriorityAscend(tempTickets);
            displayTickets(tempTickets);
            break;
        case 2:
            TicketHelper::sortPriorityDescend(tempTickets);
            displayTickets(tempTickets);
            break;
        case 3:
            TicketHelper::sortDateAscend(tempTickets);
            displayTickets(tempTickets);
            break;
        case 4:
            TicketHelper::sortDateDescend(tempTickets);
            displayTickets(tempTickets);
            break;
        case 5:
            TicketHelper::reverseOrder(tempTickets);
            displayTickets(tempTickets);
            break;
        case 6:
            std::cout << "Exiting back to the main menu...\n";
            return;
        default:
            std::cout << "Invalid entry, please try again\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            break;
        }
    }
}

void TicketService::updateTicket(std::vector<Ticket> &tickets) {
    if (tickets.empty()) {
        std::cout << "\nNo tickets to update." << std::endl;
        return;
    }

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
                tickets[ticketChoice - 1].setTechnician(newTechnician);
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
    if (tickets.empty()) {
        std::cout << "\nNo tickets available to filter." << std::endl;
        return;
    }

    int filterChoice;

    while (true) {
        std::cout << "\nEnter a priority level to filter tickets (1 (Highest) - 4 (Lowest): ";
        std::cin >> filterChoice;

        if ((filterChoice >= 1) && (filterChoice <= 4)) {
            std::cout << "Showing tickets at Priority Level: " << filterChoice << std::endl;
            break;
        }
        std::cout << "Invalid input, please try again\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    std::vector<Ticket> filteredTickets = TicketHelper::filterByPriority(tickets, filterChoice);

    if (filteredTickets.empty()) {
        std::cout << "No tickets found with the Priority Level you chosen.\n";
    }
    else {
        displayTickets(filteredTickets);
    }
}