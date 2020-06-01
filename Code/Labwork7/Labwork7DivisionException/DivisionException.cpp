#include "DivisionException.hpp"

DivisionException::DivisionException(const char *mess) {
    msg = mess;
}

const char* DivisionException::what() const throw() {
    return msg;
}
