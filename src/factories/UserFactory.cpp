#include "UserFactory.h"
#include "Exceptions.h"
#include <iostream>
#include <stdexcept>

std::shared_ptr<User> UserFactory::createUser(const std::string& type, const std::vector<std::string>& tokens) {
    if (type == "Client") {
        if (tokens.size() < 4) {
            throw DatabaseCorruptedException("UserFactory : Insufficient columns for Client record.");
        }

        int id = 0;
        try {
            id = std::stoi(tokens[0]);
        }
        catch (const std::invalid_argument &e) {
            throw DatabaseCorruptedException("UserFactory : Client ID failed to parse");
        }
        std::string name = tokens[1];
        std::string email = tokens[2];
        std::string company = tokens[3];

        return std::make_shared<Client>(id, name, email, company);
    } 
    else if (type == "Technician") {
        if (tokens.size() < 5) {
            throw DatabaseCorruptedException("UserFactory Error : Insufficient columns for Technician record.");
        }

        int id = 0, emplID = 0;
        try {
            id = std::stoi(tokens[0]);
        }
        catch (const std::invalid_argument &e) {
            throw DatabaseCorruptedException("UserFactory : Technician ID failed to parse");
        }
        std::string name = tokens[1];
        std::string email = tokens[2];
        try {
            emplID = std::stoi(tokens[3]);
        }
        catch (const std::invalid_argument &e) {
            throw DatabaseCorruptedException("UserFactory : Technician emplID failed to parse");
        }
        std::string department = tokens[4];

        return std::make_shared<Technician>(id, name, email, emplID, department);
    } 
    else {
        throw DatabaseCorruptedException("UserFactory : Unknown user type: " + type);
    }
}