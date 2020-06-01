#include <iostream>
#include "ExceptionForm.hpp"
using std::cout;

ExceptionForm::ExceptionForm(const char* mess) {
    msg = mess;
}

ExceptionForm::~ExceptionForm() {
    delete msg;
}

const char* ExceptionForm::what() const throw() {
    return msg;
}
