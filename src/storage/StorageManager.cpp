#include "StorageManager.h"
#include <iostream>
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
    std::ifstream clientIn(clientFile);
    std::ifstream techIn(technicianFile);
    std::ifstream tickIn(ticketFile);

    std::unordered_map<int, std::shared_ptr<Client>> clientMap;
    std::unordered_map<int, std::shared_ptr<Technician>> techMap;

    tickets.clear();

    if (!clientIn.is_open() && !techIn.is_open() && !tickIn.is_open()) {
        return true;
    }
    if (!clientIn.is_open() || !techIn.is_open() || !tickIn.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(clientIn, line)) {
        auto tokens = parseLine(line);
        if (tokens.size() < 4) continue;

        try {
            auto client = std::make_shared<Client>(std::stoi(tokens[0]), tokens[1], tokens[2], tokens[3]);
            clientMap[client->getID()] = client;
        }
        catch (const std::invalid_argument &e) {
            std::cerr << "Error: Corrupted token found where a number was expected. Skipping row.\n";
        }
        catch (const std::out_of_range &e) {
            std::cerr << "Error: Numeric value exceeds integer size limit. Skipping row.\n";
        }
    }
    
    while (std::getline(techIn, line)) {
        auto tokens = parseLine(line);
        if (tokens.size() < 5) continue;
        try {
            auto technician = std::make_shared<Technician>(std::stoi(tokens[0]), tokens[1], tokens[2], stoi(tokens[3]), tokens[4]);
            techMap[technician->getID()] = technician;
        }
        catch (const std::invalid_argument &e) {
            std::cerr << "Error: Corrupted token found where a number was expected. Skipping row.\n";
        }
        catch (const std::out_of_range &e) {
            std::cerr << "Error: Numeric value exceeds integer size limit. Skipping row.\n";
        }
    }

    while (std::getline(tickIn, line)) {
        auto tokens = parseLine(line);
        if (tokens.size() < 7) continue;
        
        try {
            int ticketID = std::stoi(tokens[0]), clientID = std::stoi(tokens[1]), techID = std::stoi(tokens[2]);

            auto clientPtr = clientMap[clientID];
            if (!clientPtr) {
                std::cerr << "Warning: Skipping ticket ID " << ticketID << " because Client ID " << clientID << " does not exist.\n";
                continue; 
            }

            std::shared_ptr<Technician> techPtr = nullptr;
            if (techID != 0) {
                techPtr = techMap[techID];
            }

            std::string issueDescription = tokens[3], dueDate = tokens[4], issueStatus = tokens[6];
            int priorityLevel = stoi(tokens[5]);
            
            Ticket ticket;
            ticket.setTicketId(ticketID);
            ticket.setClient(clientPtr);
            ticket.setTechnician(techPtr);
            ticket.setIssueDescription(issueDescription);
            ticket.setDueDate(dueDate);
            ticket.setPriorityLevel(priorityLevel);
            ticket.setIssueStatus(issueStatus);

            tickets.push_back(ticket);
        }
        catch (const std::invalid_argument &e) {
            std::cerr << "Error: Corrupted token found where a number was expected. Skipping row.\n";
        }
        catch (const std::out_of_range &e) {
            std::cerr << "Error: Numeric value exceeds integer size limit. Skipping row.\n";
        }
    }
    clientIn.close();
    techIn.close();
    tickIn.close();

    return true;
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