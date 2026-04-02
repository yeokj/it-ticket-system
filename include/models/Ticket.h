#ifndef TICKET_H
#define TICKET_H

#include <string>

// Class to represent an incident ticket (created by Kyame)
class Ticket {
public:
    // Constructor
    Ticket();
    Ticket( int ticketId, 
            const std::string &clientName, 
            const std::string &technicianName, 
            const std::string &issueDescription, 
            int dueDate,
            int priorityLevel);

    // Setters and Getters
    void SetTicketNum(int ticketNum);
    int GetTicketNum() const;

    void SetClient(std::string clientInfo);
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
    int ticketId;
    const std::string &clientName;
    const std::string &technicianName;
    const std::string &issueDescription;
    int dueDate;
    int priorityLevel;
};

#endif
