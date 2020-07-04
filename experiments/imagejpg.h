#ifndef _IMAGEJPG_H
#define _IMAGEJPG_H

#include <vector>
#include <iostream>
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
};

//----------------------------------------------------------------------
// define a matrix element which which is of the shape width * height
typedef vector<vector<Pixel>> Mat;

//---------------------------------------------
/* Writing the "informal" header for jpeg files
   A jpeg file consists of the following things:
   * SOI (start of image): FF D8 //16 bits
*/
//----------------------------------------------


//----------------------------------------------
/* The JFIF APP0 marker consists of information 
   regarding the properties of the data, width,
   height, pixel densities and the actual data.

*/
//----------------------------------------------

typedef struct JFIFHeader {
    uint16_t SOI {0xFFD8};
    uint16_t APP0 {0xFFE0};
    uint16_t length {0};
    uint8_t Identifier[5]; //"JFIF"
    uint16_t Version;
    uint8_t Units;
    uint16_t Xdensity;
    uint16_t Ydensity;
    uint8_t Xthumbnail;
    uint8_t Ythumbnail;
} JFIFHead;

// The image size = xthumbnail * ythumbnail. Each cross-section will have 3 values

class Image
{
    private:
        Mat mat;
    public:
        /**
         *  input is a string
         *  output is a Mat element
         *  Use the structure to locate the data
         **/
        Mat open(string);
};

#endif