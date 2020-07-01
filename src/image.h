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

typedef struct BMPheader{
    uint16_t file_type{0x4D42};
    uint32_t file_size{ 0 }; // size of the file (54 bytes header + 16 bytes data)
    uint16_t reserved1{ 0 }; // not used
    uint16_t reserved2{ 0 }; // not used
    uint32_t offset{ 0 }; // start position
} BMPheader;

typedef struct DIBheader{
    uint32_t size{ 0 }; 
    int32_t width{ 0 };
    int32_t height{ 0 };
    uint16_t cplanes{ 1 };
    uint16_t bits_per_pixel{ 0 };
    uint32_t compression{ 0 };
    uint32_t image_size{ 0 };
    uint32_t x_pixel_per_m{ 0 };
    uint32_t y_pixel_per_m{ 0 };
    uint32_t num_colors{ 0 };
    uint32_t imp_colors{ 0 };
} DIBheader;

typedef struct BMPData {
    uint32_t red{0x00ff0000};
    uint32_t green{0x0000ff00};
    uint32_t blue{0x000000ff};
    uint32_t alpha{0xff000000};
    uint32_t color_sapce{0x73524742}; //sRGB
    uint32_t unused[16]{ 0 };
} BMPData;

#endif