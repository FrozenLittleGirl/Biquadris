#include "oblock.h"
#include <iostream>
#include <vector>
#include <string>


Oblock::Oblock(size_t x, size_t y, size_t angle, bool isHeavy, size_t heavyCount, char name): 
Block(0, 0, 0, isHeavy, heavyCount, 'O') {};



vector<string> Oblock::getRotateDefault() {
    vector<string> RotateDefault;
    RotateDefault.push_back("    ");
    RotateDefault.push_back("    ");
    RotateDefault.push_back("OO  ");
    RotateDefault.push_back("OO  ");
    return RotateDefault;
}

vector<string> Oblock::getRotate90() {
    vector<string> Rotate90;
    Rotate90.push_back("    ");
    Rotate90.push_back("    ");
    Rotate90.push_back("OO  ");
    Rotate90.push_back("OO  ");
    return Rotate90;
}


vector<string> Oblock::getRotate180() {
    vector<string> Rotate180;
    Rotate180.push_back("    ");
    Rotate180.push_back("    ");
    Rotate180.push_back("OO  ");
    Rotate180.push_back("OO ");
    return Rotate180;
}


vector<string> Oblock::getRotate270() {
    vector<string> Rotate270;
    Rotate270.push_back("    ");
    Rotate270.push_back("    ");
    Rotate270.push_back("OO  ");
    Rotate270.push_back("OO  ");
    return Rotate270;
}

