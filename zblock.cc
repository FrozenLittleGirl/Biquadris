#include "zblock.h"
#include <iostream>
#include <vector>
#include <string>

Zblock::Zblock(size_t x, size_t y, size_t angle, bool isHeavy, size_t heavyCount, char name): 
Block(0, 0, 0, isHeavy, heavyCount, 'Z') {};


vector<string> Zblock::getRotateDefault() {
    vector<string> RotateDefault;
    RotateDefault.push_back("    ");
    RotateDefault.push_back("    ");
    RotateDefault.push_back("zz  ");
    RotateDefault.push_back(" zz ");
    return RotateDefault;
}

vector<string> Zblock::getRotate90() {
    vector<string> Rotate90;
    Rotate90.push_back("    ");
    Rotate90.push_back(" z  ");
    Rotate90.push_back("zz  ");
    Rotate90.push_back("z   ");
    return Rotate90;
}


vector<string> Zblock::getRotate180() {
    vector<string> Rotate180;
    Rotate180.push_back("    ");
    Rotate180.push_back("    ");
    Rotate180.push_back("zz  ");
    Rotate180.push_back(" zz ");
    return Rotate180;
}


vector<string> Zblock::getRotate270() {
    vector<string> Rotate270;
    Rotate270.push_back("    ");
    Rotate270.push_back(" z  ");
    Rotate270.push_back("zz  ");
    Rotate270.push_back("z   ");
    return Rotate270;
}

