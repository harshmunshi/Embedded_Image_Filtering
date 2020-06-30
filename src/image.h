#ifndef _IMAGE_H
#define _IMAGE_H

#include <iostream>
using namespace std;

class Image{
    public:
        // set the row and column value
        Image(int row, int col):_row(row), _col(col) {};
        ~Image();
        // load the image using ifstream
        unsigned char* loadImage(string filename);
        void saveImage(unsigned char* image, string destination);
        
    private:
        int _row;
        int _col;
};

#endif