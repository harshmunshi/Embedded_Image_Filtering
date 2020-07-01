#ifndef _IMAGE_H
#define _IMAGE_H

#include <iostream>
using namespace std;

/***************************************************************************************************************
BMP file format
Example reader is given in https://en.wikipedia.org/wiki/BMP_file_format#DIB_header_(bitmap_information_header)
The information in BMP header consists of:
    - A BMP header
    - A DIB header
    - Pixel data
The header confirms if the file is actually a BMP of something else. The DIB header gives more information on
the size of the image including rows and columns
****************************************************************************************************************/

struct BMPheader{
    uint16_t file_type{0x4D42};
    uint32_t file_size{ 0 }; // size of the file (54 bytes header + 16 bytes data)
    uint16_t reserved1{ 0 }; // not used
    uint16_t reserved2{ 0 }; // not used
    uint32_t offset{ 0 }; // start position
};

struct DIBheader{
    uint32_t size{ 0 };
    int32_t width{ 0 };
    int32_t height{ 0 };
    uint16_t cplanes{ 1 };

};



#endif