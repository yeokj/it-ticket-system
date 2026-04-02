#ifndef TICKETSERVICE_H
#define TICKETSERVICE_H

#include "Ticket.h"
#include <vector>

void createTicket(std::vector<Ticket>& tickets);
void appendTicket(std::vector<Ticket>& tickets);
void removeTicket(std::vector<Ticket>& tickets);
void sortTicket(std::vector<Ticket>& tickets);
void searchTicket(std::vector<Ticket>& tickets);
void priorityTicket(std::vector<Ticket>& tickets);
void reverseTicket(std::vector<Ticket>& tickets);
void displayAllTickets(const std::vector<Ticket>& tickets);
void updateTicket(std::vector<Ticket>& tickets);
void filterTicket(const std::vector<Ticket>& tickets);

#endif

