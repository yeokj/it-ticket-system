#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User {
public:
    User(int id, std::string name, std::string email);
    virtual ~User();
    void setID(int id);
    int getID() const;
    void setName(std::string name);
    std::string getName() const;
    void setEmail(std::string email);
    std::string getEmail() const;
protected:
    int id;
    std::string name;
    std::string email;
};

#endif