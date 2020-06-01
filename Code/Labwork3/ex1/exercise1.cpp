#include <iostream>
#include "Image.h"
using namespace std;


/*
 * Simple function, that displays the program usage, then that exists.
 */
void usage(const char*const name) {
  std::cerr<<"Usage: "<<name<<" input.ppm threshold output.ppm"<<std::endl;
  exit(-1);
}

/*
 * Main function.
 */
int main() {


  /*if( ac != 4 )
    usage(av[0]);

  const Image in = Image::read( av[1] );

  const Image out = in.convert( atof( av[2] ) );

  out.writeP1( av[3] );
*/


    const Image in = Image::read("Baboon.512.ppm");
    const Image out = in.convert(128);
    out.writeP1("output.ppm");
  return 0;
}



