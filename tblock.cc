#include "tblock.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


Tblock::Tblock(size_t x, size_t y, size_t angle, bool isHeavy, size_t heavyCount, char name): 
Block(0, 0, 0, isHeavy, heavyCount, 'T') {};



vector<string> Tblock::getRotateDefault() {
    vector<string> RotateDefault;
    RotateDefault.push_back("    ");
    RotateDefault.push_back("    ");
    RotateDefault.push_back("TTT ");
    RotateDefault.push_back(" T  ");
    return RotateDefault;
}

vector<string> Tblock::getRotate90() {
    vector<string> Rotate90;
    Rotate90.push_back("    ");
    Rotate90.push_back(" T  ");
    Rotate90.push_back("TT  ");
    Rotate90.push_back(" T  ");
    return Rotate90;
}


vector<string> Tblock::getRotate180() {
    vector<string> Rotate180;
    Rotate180.push_back("    ");
    Rotate180.push_back("    ");
    Rotate180.push_back(" T  ");
    Rotate180.push_back("TTT ");
    return Rotate180;
}


vector<string> Tblock::getRotate270() {
    vector<string> Rotate270;
    Rotate270.push_back("    ");
    Rotate270.push_back("T   ");
    Rotate270.push_back("TT  ");
    Rotate270.push_back("T   ");
    return Rotate270;
}

