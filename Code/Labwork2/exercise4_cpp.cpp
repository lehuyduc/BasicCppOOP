#include <iostream>
// TODO: write the following file:
#include "exercise4.h"

// This one is wrong. If we put all 3 files in a project, it doesn't need this line
//#include "exercise4_c.c"


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
