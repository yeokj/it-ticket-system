#include "User.h"
#include <iostream>

User::User(int id, const std::string &name, const std::string &email) : id(id), 
                                                                        name(name), 
                                                                        email(email) {}

User::~User() {}

void User::setID(int id) {
    this->id = id;
}

int User::getID() const {
    return id;
}

void User::setName(const std::string &name) {
    this->name = name;
}

std::string User::getName() const {
    return name;
}

void User::setEmail(const std::string &email) {
    this->email = email;
}

std::string User::getEmail() const {
    return email;
}

Client::Client(int id, const std::string &name, const std::string &email, const std::string &company) : User(id, name, email),
                                                                                                        company(company) {}

Client::~Client() {}

void Client::setCompany(const std::string &company) {
    this->company = company;
}

std::string Client::getCompany() const {
    return company;
}

Technician::Technician(int id, const std::string &name, const std::string &email, int emplID, const std::string &department) : User(id, name, email),
                                                                                                                                emplID(emplID),
                                                                                                                                department(department) {}

Technician::~Technician() {}

void Technician::setEmplID(int emplID) {
    this->emplID = emplID;
}

int Technician::getEmplID() const {
    return emplID;
}

void Technician::setDepartment(const std::string &department) {
    this->department = department;
}

std::string Technician::getDepartment() const {
    return department;
}