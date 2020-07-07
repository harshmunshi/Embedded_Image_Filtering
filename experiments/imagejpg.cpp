#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "imagejpg.h"
using namespace std;

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

struct JFIFHeader {
    uint16_t SOI{0xFFD8};
    uint16_t APP0 {0xFFE0};
    uint16_t length {0};
    uint8_t Identifier[5]; //"JFIF"
    uint16_t Version;
    uint8_t Units;
    uint16_t Xdensity;
    uint16_t Ydensity;
    uint8_t Xthumbnail;
    uint8_t Ythumbnail;
};
// The image size = xthumbnail * ythumbnail. Each cross-section will have 3 values


void Image::open(string fname)
{

    JFIFHeader JFIFHead;
    // clear the buffer
    for (int i = 0; i < mat.size(); i++)
    {
        mat[i].clear();
    }
    mat.clear();

    ifstream file{fname, ios::in | ios::binary};
    // define a matrix element
    /*
    Step 1: Allot the memory size of header and seek forward
    Step 2: Check if is it a legit jpeg file
    Step 3: Read the data in sequence and allot to the pixel class.
    */
    if(file) {
        JFIFHeader JFIFHead;
        file.read((char*)(&JFIFHead), sizeof(JFIFHead));
        if(JFIFHead.SOI != 0xFFD8){
            cout << JFIFHead.SOI << endl;
            throw runtime_error("Error! Cannot recognize this file!");
            }
    }
}

int main(int argc, char** argv){
    Image im;
    im.open(argv[1]);
    return 0;
}