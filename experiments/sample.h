#ifndef _SAMPLE_H
#define _SAMPLE_H
#include <vector>
#include <iostream>

using namespace std;

class Pixel
{
    public:
        uint8_t red, blue, green;
        Pixel() : red(0), blue(0), green(0) { }; //default constructor with no args
        Pixel(uint8_t r, uint8_t b, uint8_t g) : red(r), blue(b), green(g) { }; //input constructor with r,g,b as inputs  
};

typedef vector<vector<Pixel>> Mat;


#endif