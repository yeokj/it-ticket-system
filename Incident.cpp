#include "Incident.h"
#include <string>
using namespace std;

// Default constructor initializes all members to default values
Incident::Incident() : ticket(-1), client("No Client"), technician("No Technician"), issue("No Issue"), deadline(-1), priority(0) {}

// Parameterized constructor initializes members with provided values
Incident::Incident(int ticketNum, string clientInfo, string techSupport, string issue, int dueDate)
         :  ticket(ticketNum), client(clientInfo), technician(techSupport), issue(issue), deadline(dueDate), priority(0) {};

void Incident::SetTicketNum(int ticketNum) {
    ticket = ticketNum;
}

int Incident::GetTicketNum() const {
    return ticket;
}

void Incident::SetClientInfo(string clientInfo) {
    client = clientInfo;
}

string Incident::GetClientInfo() const {
    return client;
}

void Incident::SetTechSupport(string techSupport) {
    technician = techSupport;
}

string Incident::GetTechSupport() const {
    return technician;
}

void Incident::SetIssue(string issue) {
    this->issue = issue;
}

string Incident::GetIssue() const {
    return issue;
}

void Incident::SetDueDate(int dueDate) {
    deadline = dueDate;
    SetPriority(GetPriority()); // Automatically updates priority based on due date
}

int Incident::GetDueDate() const {
    return deadline;
}

void Incident::SetPriority(int priorityLevel) {
    priority = priorityLevel;
}
// Determines the priority level based on the due date
int Incident::GetPriority() const {
    if (deadline <= 1) {
        return 1;
    } else if (deadline > 1 && deadline <= 7) {
        return 2;
    } else if (deadline > 7 && deadline <= 14) {
        return 3;
    } else {
        return 4;
    }
}

void Incident::Display() const {
    cout << "\nTicket number: " << ticket << endl;
    cout << "Client Name: " << client << endl;
    cout << "Technician Assigned: " << technician << endl;
    cout << "Issue: " << issue << endl;
    cout << "Due date: " << deadline << " days" << endl;
    cout << "Priority Level: " << GetPriority() << endl;
}

