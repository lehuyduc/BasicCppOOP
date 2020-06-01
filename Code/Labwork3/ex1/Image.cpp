#include <iostream>
#include <fstream>
#include "Image.h"

Image::Image() {}

Image::Image(const unsigned width, const unsigned height, const unsigned char code) {
        m_width = width;
        m_height = height;
        m_code = code;
        switch( m_code ) {
        case 6:
            m_pixels = new unsigned char[3*m_width*m_height];
            break;
        case 1:
            m_pixels = new unsigned char[m_width*m_height];
            break;
        default:
            std::cerr<<"Image(): bad code!"<<std::endl;
            exit(-1);
        }
  }

Image::~Image() {
    delete m_pixels;
}

Image Image::read( const char*const filename ) {
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

Image Image::convert(const float threshold) const {
        Image res;
        res.m_width = m_width;
        res.m_height = m_height;
        res.m_code = 1;
        res.m_pixels = new unsigned char[m_width*m_height];

        for(unsigned y=0; y<m_height; ++y)
        for(unsigned x=0; x<m_width; ++x) {
            const unsigned int offset = 3*( y*m_width + x );
            const unsigned char red = m_pixels[offset];
            const unsigned char green = m_pixels[offset+1];
            const unsigned char blue = m_pixels[offset+2];
            const float l = 0.299f * (float)red  + 0.587f * (float)green + 0.114f * (float)blue;
            res.m_pixels[y*m_width + x] = l < threshold ? 0 : 255;
        }

        return res;
    }

void Image::writeP1( const char*const filename ) const {
        std::ofstream ofs(filename);

        ofs<<"P1"<<std::endl;
        ofs<<m_width<<std::endl;
        ofs<<m_height<<std::endl;

        // TODO: write the pixel (using '1' or '0')
        for (int i=0;i<m_width;i++) {
            for (int j=0;j<m_height;j++) {
                if (m_pixels[i*m_width + j]==0) ofs << "0";
                else ofs << "1";
            }
            ofs << "\n";
        }
        ofs.close();
    }
