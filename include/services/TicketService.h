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

        // Display and Search:
        static void displayAllTickets(const std::vector<Ticket>& tickets); // Returns the full ticket vector        
        static void searchTickets(std::vector<Ticket>& tickets); // Searches for a specific ticket in the ticket vector
        static void filterTickets(const std::vector<Ticket>& tickets); // Returns tickets based on priority, status, issue, etc

        // Sorting and Ordering:
        static void sortTickets(std::vector<Ticket>& tickets); // Sorts tickets from lowest to highest priority
        static void prioritizeTickets(std::vector<Ticket>& tickets); // Sorts tickets from highest to lowest priority
        static void reverseTickets(std::vector<Ticket>& tickets); // Returns the tickets from new to old
};

#endif

