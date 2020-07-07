#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "imagejpg.h"
using namespace std;

Mat Image::open(string fname)
{
    ifstream file{fname.c_str(), ios::in | ios::binary};
    // define a matrix element
    /*
    Step 1: Allot the memory size of header and seek forward
    Step 2: Check if is it a legit jpeg file
    Step 3: Read the data in sequence and allot to the pixel class.
    */
}

int main(int argc, char** argv){
    return 0;
}