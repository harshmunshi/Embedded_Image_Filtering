#ifndef _IMAGE_H
#define _IMAGE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//---------------------------------------------------------------------
/**
 * A pixel in a color image is represented by it's red blue and green 
 * primary colors / pixel values.
 **/
 //--------------------------------------------------------------------

class Pixel
{
    uint8_t red, blue, green;
    Pixel() : red(0), blue(0), green(0) { }; //default constructor with no args
    Pixel(uint8_t r, uint8_t b, uint8_t g) : red(r), blue(b), green(g) { }; //input constructor with r,g,b as inputs  
}

//----------------------------------------------------------------------
// define a matrix element which which is of the shape width * height
typedef vector<vector<Pixel>> Mat;


//----------------------------------------------------------------------
// define BMP reader protocols for image reading. Identify the contents
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

//-------------------------------------------------------------------
// Header for png files in the simplest possible form, will overload
// the read and write functions

typedef struct PNGHeader{
    uint64_t file_type {89504e470d0a1a0a};
    uint32_t length {0};
} PNGHead;

typedef struct IMAGEheader {
    uint32_t width{ 0 };
    uint32_t height{ 0 };
    uint8_t bit_depth{ 0 };
    uint8_t colot_type{ 0 };
    uint8_t compression_method{ 0 };
    uint8_t filter_method{ 0 };
    uint8_t interlace_method{ 0 };
} IHDR;




#endif