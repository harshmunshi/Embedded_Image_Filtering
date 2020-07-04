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
    
}