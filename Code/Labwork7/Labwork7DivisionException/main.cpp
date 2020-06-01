#include <iostream>
#include "DivisionException.hpp"

double divi(double a, double b) {
    if (b!=0) return a/b;
    else throw DivisionException("Division by zero!");
}

int main()
{
    try {
        cout << divi(5,0) << "\n";
    }
    catch (DivisionException e) {
        cout << e.what() << "\n";
    }
    return 0;
}
