#include "Ticket.h"
#include <iostream>

// Default constructor initializes all members to default values
Ticket::Ticket() : ticketId(-1), 
                    client(nullptr), 
                    technician(nullptr), 
                    issueDescription("None"), 
                    dueDate("YYYY-MM-DD"), 
                    priorityLevel(0), 
                    issueStatus("Open") {}

// Parameterized constructor initializes members with provided values
Ticket::Ticket(int ticketId, 
                std::shared_ptr<Client> client, 
                std::shared_ptr<Technician> technician, 
                const std::string &issueDescription, 
                const std::string &dueDate, 
                int priorityLevel)
         :  ticketId(ticketId), 
            client(client), 
            technician(technician), 
            issueDescription(issueDescription), 
            dueDate(dueDate), 
            priorityLevel(priorityLevel),
            issueStatus("Open") {}

void Ticket::setTicketId(int ticketId) {
    this->ticketId = ticketId;
}

int Ticket::getTicketId() const {
    return ticketId;
}

void Ticket::setClient(std::shared_ptr<Client> client) {
    this->client = client;
}

std::shared_ptr<Client> Ticket::getClient() const {
    return client;
}

void Ticket::setTechnician(std::shared_ptr<Technician> technician) {
    this->technician = technician;
}

std::shared_ptr<Technician> Ticket::getTechnician() const {
    return technician;
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

    if (client == nullptr) {
        std::cout << "Client Name: Unknown" << std::endl;
    }
    else {
        std::cout << "Client Name: " << getClient()->getName() << std::endl;
    }

    if (technician == nullptr) {
        std::cout << "Technician Assigned: Unassigned" << std::endl;
    }
    else {
        std::cout << "Technician Assigned: " << getTechnician()->getName() << std::endl;
    }

    std::cout << "Issue: " << getIssueDescription() << std::endl;
    std::cout << "Due date: " << getDueDate() << std::endl;
    std::cout << "Priority Level: " << getPriorityLevel() << std::endl;
    std::cout << "Status: " << getIssueStatus() << std::endl;
}

