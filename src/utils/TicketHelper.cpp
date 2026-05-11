#include "TicketHelper.h"
#include <string>
#include <chrono>
#include <algorithm>

bool TicketHelper::isFormatValid(const std::string &date) {
    return (date.length() == 10 && ((date[4] == '-') && (date[7] == '-')));
}

bool TicketHelper::isValuesValid(int y, int m, int d) {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&t);

    int currYear = now_tm->tm_year + 1900, currMonth = now_tm->tm_mon + 1, currDay = now_tm->tm_mday;

    if ((y < currYear) || (y > (currYear + 3))) {
        return false;
    }

    if (y == currYear) {
        if ((m < currMonth) || (m > 12)) {
            return false;
        }
    }
    else {
        if ((m < 1) || (m > 12)) {
            return false;
        }
    }

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
        daysInMonth[2] = 29;
    }

   int maxDay = daysInMonth[m];

   if (y == currYear && m == currMonth) {
        if ((d < currDay) || (d > maxDay)) {
            return false;
        }
   }

   else {
        if ((d < 1) || (d > maxDay)) {
            return false;
        }
    }
    return true;
}

bool TicketHelper::validateDate(const std::string &date) {
    if (!isFormatValid(date)) {
        return false;
    }

    std::string year = date.substr(0, 4), month = date.substr(5, 2), day = date.substr(8, 2);
    int y = stoi(year), m = stoi(month), d = stoi(day);

    if (!isValuesValid(y, m, d)) {
        return false;
    }

    return true;
}

int TicketHelper::dateToDays(int y, int m, int d) {
    int total = y * 365;

    // Add leap days (approximate is fine for priority windows)
    total += (y / 4) - (y / 100) + (y / 400);

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Add days for months in the current year
    for (int i = 1; i < m; ++i) {
        total += daysInMonth[i];
    }

    // Add February leap day if we are past Feb in a leap year
    if (m > 2 && (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))) {
        total += 1;
    }

    return total + d;
}

int TicketHelper::determinePriority(int diff) {
    if ((diff >= 0) && (diff <= 2)) return 1;
    if ((diff >= 3) && (diff <= 7)) return 2;
    if ((diff >= 8) && (diff <= 14)) return 3;

    return 4;
}

int TicketHelper::calculatePriority(const std::string &date) {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&t);

    int currYear = now_tm->tm_year + 1900, currMonth = now_tm->tm_mon + 1, currDay = now_tm->tm_mday;
    int y = stoi(date.substr(0, 4)), m = stoi(date.substr(5, 2)), d = stoi(date.substr(8, 2));

    int dueTotal = dateToDays(y, m, d);
    int todayTotal = dateToDays(currYear, currMonth, currDay);

    return determinePriority(dueTotal - todayTotal);
}

void TicketHelper::sortPriorityAscend(std::vector<Ticket> &tempTickets) {
    std::sort(tempTickets.begin(), tempTickets.end(),
        [](const Ticket &a, const Ticket &b) {
            if (a.getPriorityLevel() == b.getPriorityLevel()) { 
                return a.getDueDate() < b.getDueDate(); 
            }
            return a.getPriorityLevel() < b.getPriorityLevel();
        });
}

void TicketHelper::sortPriorityDescend(std::vector<Ticket> &tempTickets) {
    std::sort(tempTickets.begin(), tempTickets.end(),
        [](const Ticket &a, const Ticket &b) {
            if (a.getPriorityLevel() == b.getPriorityLevel()) {
                return a.getDueDate() < b.getDueDate();
            }
            return a.getPriorityLevel() > b.getPriorityLevel();
        });
}

void TicketHelper::sortDateAscend(std::vector<Ticket> &tempTickets) {
    std::sort(tempTickets.begin(), tempTickets.end(),
        [](const Ticket &a, const Ticket &b) {
            if (a.getDueDate() == b.getDueDate()) {
                return a.getPriorityLevel() < b.getPriorityLevel();
            }
            return a.getDueDate() < b.getDueDate();
        });
}

void TicketHelper::sortDateDescend(std::vector<Ticket> &tempTickets) {
    std::sort(tempTickets.begin(), tempTickets.end(),
        [](const Ticket &a, const Ticket &b) {
            if (a.getDueDate() == b.getDueDate()) {
                return a.getPriorityLevel() < b.getPriorityLevel();
            }
            return a.getDueDate() > b.getDueDate();
        });
}

void TicketHelper::reverseOrder(std::vector<Ticket> &tempTickets) {
    std::reverse(tempTickets.begin(), tempTickets.end());
}