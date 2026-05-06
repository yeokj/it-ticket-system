#ifndef TICKETSERVICE_H
#define TICKETSERVICE_H

#include "Ticket.h"
#include <vector>

class TicketService {
    public:
        //CRUD Operations:
        static void createTicket(std::vector<Ticket>& tickets); // Creates and adds tickets to the ticket vector
        static void removeTicket(std::vector<Ticket>& tickets); // Removes tickets from the ticket vector
        static void updateTicket(std::vector<Ticket>& tickets); // Updates ticket in the ticket vector

        // View Operations:
        static void displayTickets(const std::vector<Ticket>& tickets); // Displays all tickets       
        static void findTickets(const std::vector<Ticket>& tickets); // Returns tickets based on priority, status, etc

        // Organization:
        static void organizeTickets(std::vector<Ticket>& tickets); // Sorts/Prioritizes tickets
};

#endif

