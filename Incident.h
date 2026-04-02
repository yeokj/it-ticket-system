#ifndef INCIDENT_H
#define INCIDENT_H

#include <iostream>
#include <string>
using namespace std;

// Class to represent an incident ticket (created by Kyame)
class Incident {
public:
//constructor
    Incident();
    Incident(int ticketNum, string clientInfo, string techSupport, string issue, int dueDate);
//setters and getters
    void SetTicketNum(int ticketNum);
    int GetTicketNum() const;
    void SetClientInfo(string clientInfo);
    string GetClientInfo() const;
    void SetTechSupport(string techSupport);
    string GetTechSupport() const;
    void SetIssue(string issue);
    string GetIssue() const;
    void SetDueDate(int dueDate);
    int GetDueDate() const;
    void SetPriority(int priorityLevel);
    int GetPriority() const;

    void Display() const;

private:
    int ticket;
    string client;
    string technician;
    string issue;
    int deadline;
    int priority;
};

#endif
