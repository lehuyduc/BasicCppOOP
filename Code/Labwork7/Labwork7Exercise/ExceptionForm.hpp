#include <iostream>
#include <exception>
using std::cout;

class ExceptionForm : public std::exception {
    const char *msg;

public:
    ExceptionForm(const char *);
    ~ExceptionForm();
    const char* what() const throw();
};
