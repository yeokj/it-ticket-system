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