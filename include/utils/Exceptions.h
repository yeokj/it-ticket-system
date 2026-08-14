#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class DatabaseCorruptedException : public std::exception {
public:
    DatabaseCorruptedException(const std::string &msg);
    const char* what() const noexcept override;

private:
    std::string message;
};

class UnauthorizedAccessException : public std::exception {
public:
    UnauthorizedAccessException(const std::string &msg);
    const char* what() const noexcept override;

private:
    std::string message;
};

#endif
