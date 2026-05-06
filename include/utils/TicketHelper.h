#ifndef TICKETHELPER.H
#define TICKETHELPER.H

#include "Ticket.h"
#include <iostream>

class TicketHelper {
    public:
    static bool validateDate(const std::string &date);
    static int calculatePriority(const std::string &date);

    private:
    static bool isFormatValid(const std::string &date);
    static bool isValuesValid(int y, int m, int d);
    static int dateToDays(int y, int m, int d);
    static int determinePriority(int diff);
};

#endif