#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include "Ticket.h"
#include "User.h"
#include <fstream>
#include <memory>
#include <string>

class StorageManager {
public:
    StorageManager(const std::string &cFile = "client.csv", 
                    const std::string &tFile = "technician.csv", 
                    const std::string &tickFile = "ticket.csv");
    bool saveFiles(const std::vector<Ticket> &tickets);
    bool loadFiles(std::vector<Ticket> &tickets);
private:
    std::string clientFile;
    std::string technicianFile;
    std::string ticketFile;
    std::vector<std::string> parseLine(const std::string &data);
};

#endif