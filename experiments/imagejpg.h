#ifndef IMAGEJPG_H
#define IMAGEJPG_H

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
        
        void open(string);
};

#endif