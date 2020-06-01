#include <iostream>
#include <fstream>

// (very) basic structure for an Image
struct Image {
  unsigned m_width;
  unsigned m_height;
  unsigned char m_code; // 1 or 6
  unsigned char *m_pixels;
};


/* 
 * Creates an image by reading a P6 PPM file.
 * @param filename: name of the PPM file to read.
 * @return the readed image.
 */
Image read( const char*const filename ) {
  // attempt to open the file
  std::ifstream ifs(filename);
  if( !ifs.is_open() ) {
    std::cerr<<"Unable to open "<<filename<<". Exiting ..."<<std::endl;
    exit(-1);
  }
  Image res;
  std::string code;
  int size;
  ifs>>code>>res.m_width>>res.m_height>>size;
  if( code.compare( std::string("P6") ) != 0 ) {
    std::cerr<<"Bad input image file. Exiting ..."<<std::endl;
    exit(-1);
  }
  res.m_code = 6;
  res.m_pixels = new unsigned char[res.m_width*res.m_height*3];
  std::streampos start = ifs.tellg();
  ifs.close();

  ifs.open(filename, std::ios::in | std::ios::binary );
  if( !ifs.is_open() ) {
    std::cerr<<"Unable to open "<<filename<<". Exiting ..."<<std::endl;
    exit(-1);
  }
  ifs.seekg(start, std::ios::beg);
  ifs.read((char*)res.m_pixels, 3*res.m_width*res.m_height);
  ifs.close();
  return res;
}


/*
 * Convert a P6 image (RGB) into a black and white one (P1).
 * @param threshold: the threshold between which a pixel is set to black.
 * @return The converted black and white image.
 */
Image convert(Image img, const float threshold) {
  Image res;
  res.m_width = img.m_width;
  res.m_height = img.m_height;
  res.m_code = 1;
  res.m_pixels = new unsigned char[img.m_width*img.m_height];
  
  for(unsigned y=0; y<img.m_height; ++y)
    for(unsigned x=0; x<img.m_width; ++x) {
      const unsigned int offset = 3*( y*img.m_width + x );
      const unsigned char red = img.m_pixels[offset];
      const unsigned char green = img.m_pixels[offset+1];
      const unsigned char blue = img.m_pixels[offset+2];
      const float l = 0.299f * (float)red  + 0.587f * (float)green + 0.114f * (float)blue;
      res.m_pixels[y*img.m_width + x] = l < threshold ? 0 : 255;
    }

  return res;
}


/*
 * Write a given image in PPM format (code P1).
 * @param filename: the name of the file to write into.
 */
void writeP1( Image img, const char*const filename ) {
  std::ofstream ofs(filename);
  
  ofs<<"P1"<<std::endl;
  ofs<<img.m_width<<std::endl;
  ofs<<img.m_height<<std::endl;
  
  // TODO: write the pixel (using '1' or '0')
}


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
int main( int ac, char**av ) {
  if( ac != 4 ) 
    usage(av[0]);

  // TODO: read, convert, write ...

  return 0;
}


  
