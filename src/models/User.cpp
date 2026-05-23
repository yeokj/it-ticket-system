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