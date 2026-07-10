#ifndef TICKETSERVICE_H
#define TICKETSERVICE_H

#include "Ticket.h"
#include <vector>
#include <unordered_set>

class TicketService {
public:
    //CRUD Operations:
    void createTicket(std::vector<Ticket>& tickets); // Creates and adds tickets to the ticket vector
    void removeTicket(std::vector<Ticket>& tickets); // Removes tickets from the ticket vector
    void updateTicket(std::vector<Ticket>& tickets); // Updates ticket in the ticket vector

    // View Operations:
    void displayTickets(const std::vector<Ticket>& tickets);
    void displayTickets(const std::vector<Ticket>& tickets, const std::string &userRole, int currentUserId); // Displays all tickets
    
    void findTickets(const std::vector<Ticket>& tickets);
    void findTickets(const std::vector<Ticket>& tickets, const std::string &userRole, int currentUserId); // Returns tickets based on priority, status, etc

    // Organization:
    void organizeTickets(std::vector<Ticket>& tickets); // Sorts/Prioritizes tickets

    // Data Hydration
    void syncTickets(const std::vector<Ticket>& tickets);

private:
    std::unordered_set<int> ticketSet;
    int nextClientId;
    int nextTechId;
};

#endif

