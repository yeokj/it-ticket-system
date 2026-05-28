#include "StorageManager.h"
#include <sstream>
#include <unordered_set>

StorageManager::StorageManager(const std::string &cFile,
                                const std::string &tFile,
                                const std::string &tickFile) :
                                clientFile(cFile),
                                technicianFile(tFile),
                                ticketFile(tickFile)
                                {}

bool StorageManager::saveFiles(const std::vector<Ticket> &tickets) {
    std::ofstream clientOut(clientFile);
    std::ofstream techOut(technicianFile);
    std::ofstream tickOut(ticketFile);

    std::unordered_set<int> savedClientID;
    std::unordered_set<int> savedTechID;

    if (!clientOut.is_open() || !techOut.is_open() || !tickOut.is_open()) {
        return false;
    }

    for (const auto &ticket : tickets) {
        if (savedClientID.find(ticket.getClient()->getID()) == savedClientID.end()) {
            auto client = ticket.getClient();
            clientOut << client->getID() << ',' 
                    << client->getName() << ',' 
                    << client->getEmail() << ',' 
                    << client->getCompany() <<'\n';
            savedClientID.insert(ticket.getClient()->getID());
        }
        if (ticket.getTechnician() != nullptr) {
            if (savedTechID.find(ticket.getTechnician()->getID()) == savedTechID.end()) {
                auto technician = ticket.getTechnician();
                techOut << technician->getID() << ',' 
                        << technician->getName() << ',' 
                        << technician->getEmail() << ',' 
                        << technician->getEmplID() << ',' 
                        << technician->getDepartment() << '\n';
                savedTechID.insert(ticket.getTechnician()->getID());
            }
        }
        tickOut << ticket.getTicketId() << ','
                << ticket.getClient()->getID() << ','
                << (ticket.getTechnician() != nullptr ? ticket.getTechnician()->getID() : 0) << ','
                << ticket.getIssueDescription() << ','
                << ticket.getDueDate() << ','
                << ticket.getPriorityLevel() << ','
                << ticket.getIssueStatus() << '\n';
    }
    clientOut.close();
    techOut.close();
    tickOut.close();

    return true;
}

bool StorageManager::loadFiles(std::vector<Ticket> &tickets) {
    
}

std::vector<std::string> StorageManager::parseLine(const std::string &line) {
    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string token;

    while (std::getline(ss, token, ',')) {
        tokens.push_back(token);
    }
    return tokens;
}