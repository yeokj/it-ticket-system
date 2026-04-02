#include "Ticket.h"
#include <string>
using namespace std;

// Default constructor initializes all members to default values
Ticket::Ticket() : ticket(-1), client("No Client"), technician("No Technician"), issue("No Issue"), deadline(-1), priority(0) {}

// Parameterized constructor initializes members with provided values
Ticket::Ticket(int ticketNum, string clientInfo, string techSupport, string issue, int dueDate)
         :  ticket(ticketNum), client(clientInfo), technician(techSupport), issue(issue), deadline(dueDate), priority(0) {};

void Ticket::SetTicketNum(int ticketNum) {
    ticket = ticketNum;
}

int Ticket::GetTicketNum() const {
    return ticket;
}

void Ticket::SetClientInfo(string clientInfo) {
    client = clientInfo;
}

string Ticket::GetClientInfo() const {
    return client;
}

void Ticket::SetTechSupport(string techSupport) {
    technician = techSupport;
}

string Ticket::GetTechSupport() const {
    return technician;
}

void Ticket::SetIssue(string issue) {
    this->issue = issue;
}

string Ticket::GetIssue() const {
    return issue;
}

void Ticket::SetDueDate(int dueDate) {
    deadline = dueDate;
    SetPriority(GetPriority()); // Automatically updates priority based on due date
}

int Ticket::GetDueDate() const {
    return deadline;
}

void Ticket::SetPriority(int priorityLevel) {
    priority = priorityLevel;
}
// Determines the priority level based on the due date
int Ticket::GetPriority() const {
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

void Ticket::Display() const {
    cout << "\nTicket number: " << ticket << endl;
    cout << "Client Name: " << client << endl;
    cout << "Technician Assigned: " << technician << endl;
    cout << "Issue: " << issue << endl;
    cout << "Due date: " << deadline << " days" << endl;
    cout << "Priority Level: " << GetPriority() << endl;
}

