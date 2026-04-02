#ifndef TICKET_H
#define TICKET_H

#include <string>

// Class to represent an incident ticket (created by Kyame)
class Ticket {
public:
//constructor
    Ticket();
    Ticket(int ticketNum, std::string clientInfo, std::string techSupport, std::string issue, int dueDate);
//setters and getters
    void SetTicketNum(int ticketNum);
    int GetTicketNum() const;
    void SetClientInfo(std::string clientInfo);
    std::string GetClientInfo() const;
    void SetTechSupport(std::string techSupport);
    std::string GetTechSupport() const;
    void SetIssue(std::string issue);
    std::string GetIssue() const;
    void SetDueDate(int dueDate);
    int GetDueDate() const;
    void SetPriority(int priorityLevel);
    int GetPriority() const;

    void Display() const;

private:
    int ticket;
    std::string client;
    std::string technician;
    std::string issue;
    int deadline;
    int priority;
};

#endif
