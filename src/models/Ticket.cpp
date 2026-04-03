#include "Ticket.h"
#include <iostream>

// Default constructor initializes all members to default values
Ticket::Ticket() : ticketId(-1), 
                    clientName("John Doe"), 
                    technicianName("Unassigned"), 
                    issueDescription("None"), 
                    dueDate("YYYY-MM-DD"), 
                    priorityLevel(0), 
                    issueStatus("Open") {}

// Parameterized constructor initializes members with provided values
Ticket::Ticket(int ticketId, 
                const std::string &clientName, 
                const std::string &technicianName, 
                const std::string &issueDescription, 
                const std::string &dueDate, 
                int priorityLevel)
         :  ticketId(ticketId), 
            clientName(clientName), 
            technicianName(technicianName), 
            issueDescription(issueDescription), 
            dueDate(dueDate), 
            priorityLevel(priorityLevel),
            issueStatus("Open") {};

void Ticket::setTicketId(int ticketId) {
    this->ticketId = ticketId;
}

int Ticket::getTicketId() const {
    return ticketId;
}

void Ticket::setClientName(const std::string &clientName) {
    this->clientName = clientName;
}

const std::string &Ticket::getClientName() const {
    return clientName;
}

void Ticket::setTechnicianName(const std::string &technicianName) {
    this->technicianName = technicianName;
}

const std::string &Ticket::getTechnicianName() const {
    return technicianName;
}

void Ticket::setIssueDescription(const std::string &issueDescription) {
    this->issueDescription = issueDescription;
}

const std::string &Ticket::getIssueDescription() const {
    return issueDescription;
}

void Ticket::setDueDate(const std::string &dueDate) {
    this->dueDate = dueDate;
}

const std::string &Ticket::getDueDate() const {
    return dueDate;
}

void Ticket::setPriorityLevel(int priorityLevel) {
    this->priorityLevel = priorityLevel;
}
// Determines the priority level based on the due date
int Ticket::getPriorityLevel() const {
    return priorityLevel;
}

void Ticket::setIssueStatus(const std::string& status) {
    this->issueStatus = status;
}

const std::string &Ticket::getIssueStatus() const {
    return issueStatus;
}

void Ticket::display() const {
    std::cout << "\nTicket number: " << getTicketId() << std::endl;
    std::cout << "Client Name: " << getClientName() << std::endl;
    std::cout << "Technician Assigned: " << getTechnicianName() << std::endl;
    std::cout << "Issue: " << getIssueDescription() << std::endl;
    std::cout << "Due date: " << getDueDate() << std::endl;
    std::cout << "Priority Level: " << getPriorityLevel() << std::endl;
}

