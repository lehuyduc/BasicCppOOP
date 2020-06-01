#pragma once

#include <iostream>
#include <exception>
using std::cout;

class DivisionException : public std::exception {
private:
    const char *msg;

public:
    DivisionException(const char *);
    const char* what() const throw();
};
