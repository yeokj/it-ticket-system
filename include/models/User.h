#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User(int id, const std::string &name, const std::string &email);
    virtual ~User();
    void setID(int id);
    int getID() const;
    void setName(const std::string &name);
    std::string getName() const;
    void setEmail(const std::string &email);
    std::string getEmail() const;
protected:
    int id;
    std::string name;
    std::string email;
};

class Client : public User {
public:
    Client(int id, const std::string &name, const std::string &email, const std::string &company);
    virtual ~Client() override;
    void setCompany(const std::string &company);
    std::string getCompany() const;
private:
    std::string company;
};

class Technician : public User {
public:
    Technician(int id, const std::string &name, const std::string &email, int emplID, const std::string &department);
    virtual ~Technician() override;
    void setEmplID(int emplID);
    int getEmplID() const;
    void setDepartment(const std::string &department);
    std::string getDepartment() const;
private:
    int emplID;
    std::string department;
};

#endif