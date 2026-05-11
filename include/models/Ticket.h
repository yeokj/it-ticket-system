#ifndef TICKET_H
#define TICKET_H

#include <string>

// Class to represent a Ticket (created by Kyame)
class Ticket {
public:
    // Constructor
    Ticket();
    Ticket(int ticketId, 
            const std::string &clientName, 
            const std::string &technicianName, 
            const std::string &issueDescription, 
            const std::string &dueDate,
            int priorityLevel);

    // Setters and Getters
    void setTicketId(int ticketId);
    int getTicketId() const;

    void setClientName(const std::string &clientName);
    const std::string &getClientName() const;

    void setTechnicianName(const std::string &technicianName);
    const std::string &getTechnicianName() const;

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
    std::string clientName;
    std::string technicianName;
    std::string issueDescription;
    std::string dueDate;
    int priorityLevel;
    std::string issueStatus;
};

#endif
