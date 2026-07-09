#include "Ticket.h"
#include "TicketService.h"
#include "StorageManager.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

int main () {
    std::vector<Ticket> tickets; // Stores all incident tickets
    TicketService service;
    StorageManager storage;

    if (storage.loadFiles(tickets)) {
        service.syncTickets(tickets); 
    }

    std::cout << "Welcome to York College Incident Management" << std::endl;

    std::string username, password;

    // Login loop for authentication
    while (true) {
        std::cout << "Enter Username: ";
        std::getline(std::cin, username);
        std::cout << "Password: ";
        std::getline(std::cin, password);


        if (username == "Admin" && password == "York123") {
            std::cout << "Login successful!" << std::endl;
            break;
        } else {
            std::cout << "Username or Password is incorrect! Try again!" << std::endl;
        }
    }

    std::cout << "What can we do for you today?" << std::endl;

    int choice;

    // Main program loop for menu operations
    while (true){
        std::cout << "\nIT Ticket Management Menu\n";
        std::cout << "----------------------------------\n";
        std::cout << "1) Create a Ticket\n"; // Your roadmap merged append into create!
        std::cout << "2) Remove Ticket\n";
        std::cout << "3) Organize Tickets\n";
        std::cout << "4) Find Ticket\n";
        std::cout << "5) Display Tickets\n";
        std::cout << "6) Update Ticket Details\n";
        std::cout << "0) Exit\n";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 0:
                std::cout << "Saving files and exiting program. Thank you!\n";
                storage.saveFiles(tickets);
                return 0;
            case 1:
                service.createTicket(tickets);
                break;
            case 2:
                service.removeTicket(tickets);
                break;
            case 3:
                service.organizeTickets(tickets);
                break;
            case 4:
                service.findTickets(tickets);
                break;
            case 5:
                service.displayTickets(tickets);
                break;
            case 6:
                service.updateTicket(tickets);
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
