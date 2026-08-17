#include "Ticket.h"
#include "TicketService.h"
#include "StorageManager.h"
#include "Exceptions.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

int main () {
    std::vector<Ticket> tickets; // Stores all incident tickets
    TicketService service;
    StorageManager storage;

    if (!storage.loadFiles(tickets)) {
        std::cerr << "Failed to load files." << std::endl;
        return 1;
    }
    service.syncTickets(tickets);

    std::cout << "Welcome to York College Incident Management" << std::endl;

    std::string loginInput, password, userRole = "";
    int currentUserId = -1;

    // Login loop for authentication
    while (true) {
        std::cout << "Enter Username or User ID: ";
        std::getline(std::cin, loginInput);
        std::cout << "Password: ";
        std::getline(std::cin, password);

        if (loginInput == "Admin") {
            if (password == "York123") {
                userRole = "Admin";
                std::cout << "Login successful as Admin!\n" << std::endl;
                break;
            }
        } 
        else {
            try {
                int userId = std::stoi(loginInput);

                const auto& techMap = storage.getTechMap();
                const auto& clientMap = storage.getClientMap();

                // Check Technicians Map
                if (techMap.find(userId) != techMap.end()) {
                    if (password == "Tech" + loginInput) {
                        userRole = "Technician";
                        currentUserId = userId;
                        std::cout << "Login successful! Welcome, " << techMap.at(userId)->getName() << ".\n" << std::endl;
                        break;
                    }
                }
                // Check Clients Map
                else if (clientMap.find(userId) != clientMap.end()) {
                    if (password == "Client" + loginInput) {
                        userRole = "Client";
                        currentUserId = userId;
                        std::cout << "Login successful! Welcome, " << clientMap.at(userId)->getName() << ".\n" << std::endl;
                        break;
                    }
                }
            }
            catch (const std::invalid_argument& e) {
                std::cerr << "Error: Input must be 'Admin' or a numeric User ID.\n";
            }
            catch (const std::out_of_range& e) {
                std::cerr << "Error: Numeric ID value is too large.\n";
            }
        }
        std::cout << "Invalid credentials! Try again.\n" << std::endl;
    }

    std::cout << "What can we do for you today?" << std::endl;

    int choice;
    std::string choiceStr;

    // Main program loop for menu operations
    while (true){
        std::cout << "\nIT Ticket Management Menu\n";
        std::cout << "----------------------------------\n";
        if (userRole == "Client") {
            std::cout << "1) Create a Ticket\n";
            std::cout << "4) Find Ticket\n";
            std::cout << "5) Display My Tickets\n";
        } 
        else if (userRole == "Technician") {
            std::cout << "3) Organize Tickets\n";
            std::cout << "4) Find Ticket\n";
            std::cout << "5) Display Tickets\n";
            std::cout << "6) Update Ticket Details\n";
        } 
        else if (userRole == "Admin") {
            std::cout << "1) Create a Ticket\n";
            std::cout << "2) Remove Ticket\n";
            std::cout << "3) Organize Tickets\n";
            std::cout << "4) Find Ticket\n";
            std::cout << "5) Display Tickets\n";
            std::cout << "6) Update Ticket Details\n";
        }
        std::cout << "0) Exit\n";

        std::cout << "\nEnter your choice: ";
        std::getline(std::cin, choiceStr);

        try {
            choice = stoi(choiceStr);
        }
        catch (const std::invalid_argument &e) {
            choice = -1;
        }
        catch (const std::out_of_range &e) {
            choice = -1;
        }
        try {
            switch (choice) {
                case 0:
                    std::cout << "\nSaving files and exiting program. Thank you!";
                    storage.saveFiles(tickets);
                    return 0;
                case 1:
                    if (userRole == "Technician") {
                            throw UnauthorizedAccessException("Technicians are not authorized to create tickets.\n");
                            break;
                        }
                    service.createTicket(tickets);
                    break;
                case 2:
                    service.removeTicket(tickets, userRole);
                    break;
                case 3:
                    service.organizeTickets(tickets, userRole);
                    break;
                case 4:
                    service.findTickets(tickets, userRole, currentUserId);
                    break;
                case 5:
                    service.displayTickets(tickets, userRole, currentUserId);
                    break;
                case 6:
                    service.updateTicket(tickets, userRole);
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        }
        catch (const UnauthorizedAccessException &e) {
            std::cerr << "\n[Access Denied] " << e.what() << "\n";
        }
    }

    return 0;
}
