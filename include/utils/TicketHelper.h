#ifndef TICKETHELPER.H
#define TICKETHELPER.H

#include "Ticket.h"
#include "TicketService.h"
#include <iostream>
#include <vector>

class TicketHelper {
public:
    static bool validateDate(const std::string &date);
    static int calculatePriority(const std::string &date);
    static void sortPriorityAscend(std::vector<Ticket> &tempTickets);
    static void sortPriorityDescend(std::vector<Ticket> &tempTickets);
    static void sortDateAscend(std::vector<Ticket> &tempTickets);
    static void sortDateDescend(std::vector<Ticket> &tempTickets);
    static void reverseOrder(std::vector<Ticket> &tempTickets);
    static int generateTicket(std::unordered_set<int> &ticketSet);

private:
    static bool isFormatValid(const std::string &date);
    static bool isValuesValid(int y, int m, int d);
    static int dateToDays(int y, int m, int d);
    static int determinePriority(int diff);
};

#endif