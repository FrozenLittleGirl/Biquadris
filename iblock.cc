#include "iblock.h"
#include "block.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


Iblock::Iblock(int x, int y, int angle, bool isHeavy, int heavyCount, char name): 
Block(0, 0, 0, isHeavy, heavyCount, 'I') {};



vector<string> Iblock::getRotateDefault() {
    vector<string> RotateDefault;
    RotateDefault.push_back("    ");
    RotateDefault.push_back("    ");
    RotateDefault.push_back("    ");
    RotateDefault.push_back("IIII");
    return RotateDefault;
}

vector<string> Iblock::getRotate90() {
    vector<string> Rotate90;
    Rotate90.push_back("I   ");
    Rotate90.push_back("I   ");
    Rotate90.push_back("I   ");
    Rotate90.push_back("I   ");
    return Rotate90;
}


vector<string> Iblock::getRotate180() {
    vector<string> Rotate180;
    Rotate180.push_back("    ");
    Rotate180.push_back("    ");
    Rotate180.push_back("    ");
    Rotate180.push_back("IIII");
    return Rotate180;
}


vector<string> Iblock::getRotate270() {
    vector<string> Rotate270;
    Rotate270.push_back("I   ");
    Rotate270.push_back("I   ");
    Rotate270.push_back("I   ");
    Rotate270.push_back("I   ");
    return Rotate270;
}
