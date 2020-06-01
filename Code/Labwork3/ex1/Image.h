#ifndef __IMAGE__
#define __IMAGE__

#include <iostream>

class Image {
  unsigned m_width;
  unsigned m_height;
  unsigned char m_code; // 1 or 6
  unsigned char *m_pixels;

  Image(); // private!

 public:
  // constructor
  Image(const unsigned width, const unsigned height, const unsigned char code);

  // destructor
  ~Image();

  // factory
  static Image read(const char*const filename);

  // convert
  Image convert(const float threshold) const;

  // write in black and white
  void writeP1( const char*const filename ) const;

  // no more methods are necessary yet ...
};

#endif
