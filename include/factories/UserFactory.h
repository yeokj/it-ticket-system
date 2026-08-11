#ifndef USERFACTORY_H
#define USERFACTORY_H

#include "User.h"
#include <memory>
#include <string>
#include <vector>

class UserFactory {
public:
    static std::shared_ptr<User> createUser(const std::string& type, const std::vector<std::string>& tokens);
};

#endif