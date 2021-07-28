#include "block.h"
#include "sblock.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;



Sblock::Sblock(size_t x, size_t y, size_t angle, bool isHeavy, size_t heavyCount, char name): 
Block(0, 0, 0, isHeavy, heavyCount, 'I') {};



vector<string> Sblock::getRotateDefault() {
    vector<string> RotateDefault;
    RotateDefault.push_back("    ");
    RotateDefault.push_back("    ");
    RotateDefault.push_back(" SS ");
    RotateDefault.push_back("SS  ");
    return RotateDefault;
}

vector<string> Sblock::getRotate90() {
    vector<string> Rotate90;
    Rotate90.push_back("    ");
    Rotate90.push_back("S   ");
    Rotate90.push_back("SS  ");
    Rotate90.push_back(" S  ");
    return Rotate90;
}


vector<string> Sblock::getRotate180() {
    vector<string> Rotate180;
    Rotate180.push_back("    ");
    Rotate180.push_back("    ");
    Rotate180.push_back(" SS ");
    Rotate180.push_back("SS  ");
    return Rotate180;
}


vector<string> Sblock::getRotate270() {
    vector<string> Rotate270;
    Rotate270.push_back("    ");
    Rotate270.push_back("S   ");
    Rotate270.push_back("SS  ");
    Rotate270.push_back(" S  ");
    return Rotate270;
}
