#ifndef TICKET_H
#define TICKET_H

#include "User.h"
#include <string>
#include <memory>

// Class to represent a Ticket (created by Kyame)
class Ticket {
public:
    // Constructor
    Ticket();
    Ticket(int ticketId, 
            std::shared_ptr<Client> client, 
            std::shared_ptr<Technician> technician, 
            const std::string &issueDescription, 
            const std::string &dueDate,
            int priorityLevel);

    // Setters and Getters
    void setTicketId(int ticketId);
    int getTicketId() const;

    void setClient(std::shared_ptr<Client> client);
    std::shared_ptr<Client> getClient() const;

    void setTechnician(std::shared_ptr<Technician> technician);
    std::shared_ptr<Technician> getTechnician() const;

    void setIssueDescription(const std::string &issueDescription);
    const std::string &getIssueDescription() const;

    void setDueDate(const std::string &dueDate);
    const std::string &getDueDate() const;

    void setPriorityLevel(int priorityLevel);
    int getPriorityLevel() const;

    void setIssueStatus(const std::string &issueStatus);
    const std::string &getIssueStatus() const;

    void display() const;

private:
    int ticketId;
    std::shared_ptr<Client> client;
    std::shared_ptr<Technician> technician;
    std::string issueDescription;
    std::string dueDate;
    int priorityLevel;
    std::string issueStatus;
};

#endif
