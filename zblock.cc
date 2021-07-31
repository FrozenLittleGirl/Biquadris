#include "zblock.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

Zblock::Zblock(int x, int y, int angle, bool isHeavy, int heavyCount, char name): 
Block(0, 0, 0, isHeavy, heavyCount, 'Z') {};


vector<string> Zblock::getRotateDefault() {
    vector<string> RotateDefault;
    RotateDefault.push_back("    ");
    RotateDefault.push_back("    ");
    RotateDefault.push_back("ZZ  ");
    RotateDefault.push_back(" ZZ ");
    return RotateDefault;
}

vector<string> Zblock::getRotate90() {
    vector<string> Rotate90;
    Rotate90.push_back("    ");
    Rotate90.push_back(" Z  ");
    Rotate90.push_back("ZZ  ");
    Rotate90.push_back("Z   ");
    return Rotate90;
}


vector<string> Zblock::getRotate180() {
    vector<string> Rotate180;
    Rotate180.push_back("    ");
    Rotate180.push_back("    ");
    Rotate180.push_back("ZZ  ");
    Rotate180.push_back(" ZZ ");
    return Rotate180;
}


vector<string> Zblock::getRotate270() {
    vector<string> Rotate270;
    Rotate270.push_back("    ");
    Rotate270.push_back(" Z  ");
    Rotate270.push_back("ZZ  ");
    Rotate270.push_back("Z   ");
    return Rotate270;
}



