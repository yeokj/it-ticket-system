#include "UserFactory.h"
#include <iostream>
#include <stdexcept>

std::shared_ptr<User> UserFactory::createUser(const std::string& type, const std::vector<std::string>& tokens) {
    try {
        if (type == "Client") {
            if (tokens.size() < 4) {
                std::cerr << "[UserFactory Error] Insufficient tokens for Client creation.\n";
                return nullptr;
            }
            int id = std::stoi(tokens[0]);
            std::string name = tokens[1];
            std::string email = tokens[2];
            std::string company = tokens[3];

            return std::make_shared<Client>(id, name, email, company);
        } 
        else if (type == "Technician") {
            if (tokens.size() < 5) {
                std::cerr << "[UserFactory Error] Insufficient tokens for Technician creation.\n";
                return nullptr;
            }
            int id = std::stoi(tokens[0]);
            std::string name = tokens[1];
            std::string email = tokens[2];
            int emplID = std::stoi(tokens[3]);
            std::string department = tokens[4];

            return std::make_shared<Technician>(id, name, email, emplID, department);
        } 
        else {
            std::cerr << "[UserFactory Error] Unknown user type: " << type << "\n";
            return nullptr;
        }
    } 
    catch (const std::exception& e) {
        std::cerr << "[UserFactory Exception] Failed to parse tokens for type " 
                  << type << ": " << e.what() << "\n";
        return nullptr;
    }
}