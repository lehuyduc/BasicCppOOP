#include <iostream>
// TODO: write the following file:
#include "exercise4.h"


int main() {

  std::cout <<"vi = "<<vi<<std::endl;

  std::cout <<"f(vi) = "<<f(vi)<<std::endl;

    while (vi!=0) {
        std::cout << "Input: ";
        std::cin >> vi;
        std::cout << "Output = " << f(vi) << "\n";
    }
  return 0;

}
