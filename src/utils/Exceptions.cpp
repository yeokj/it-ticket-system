#include "Exceptions.h"

DatabaseCorruptedException::DatabaseCorruptedException(const std::string &msg) : message(msg) {}

const char* DatabaseCorruptedException::what() const noexcept {
    return message.c_str();
}

UnauthorizedAccessException::UnauthorizedAccessException(const std::string &msg) : message(msg) {}

const char* UnauthorizedAccessException::what() const noexcept {
    return message.c_str();
}