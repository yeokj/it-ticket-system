#include "TicketHelper.h"
#include <string>
#include <chrono>

bool isFormatValid(const std::string &date) {
    if (date.length() != 10 || ((date[4] != '-') || (date[7] != '-'))) {
        return false;
    }
    return true;
}

bool isValuesValid(int y, int m, int d) {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&t);

    int currYear = now_tm->tm_year + 1900;

    if ((y < currYear) || (y > (currYear + 3))) {
        return false;
    }
    
    if ((m < 1) || (m > 12)) {
        return false;
    }

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
        daysInMonth[2] = 29;
    }

   int maxDay = daysInMonth[m];

    if ((d < 1) || (d > maxDay)) {
        return false;
    }
    return true;
}

bool validateDate(const std::string &date) {
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

int dayToDate(int y, int m, int d) {

}

int calculatePriority(const std::string &date) {
    
}