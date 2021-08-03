#include "lblock.h"
#include "block.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


Lblock::Lblock(int x, int y, int angle, bool isHeavy, int heavyCount, char name): 
Block(0, 0, 0, isHeavy, heavyCount, 'L') {};



vector<string> Lblock::getRotateDefault() {
    vector<string> RotateDefault;
    RotateDefault.push_back("    ");
    RotateDefault.push_back("    ");
    RotateDefault.push_back("  L ");
    RotateDefault.push_back("LLL ");
    return RotateDefault;
}

vector<string> Lblock::getRotate90() {
    vector<string> Rotate90;
    Rotate90.push_back("    ");
    Rotate90.push_back("L   ");
    Rotate90.push_back("L   ");
    Rotate90.push_back("LL  ");
    return Rotate90;
}


vector<string> Lblock::getRotate180() {
    vector<string> Rotate180;
    Rotate180.push_back("    ");
    Rotate180.push_back("    ");
    Rotate180.push_back("LLL ");
    Rotate180.push_back("L   ");
    return Rotate180;
}


vector<string> Lblock::getRotate270() {
    vector<string> Rotate270;
    Rotate270.push_back("    ");
    Rotate270.push_back("LL  ");
    Rotate270.push_back(" L  ");
    Rotate270.push_back(" L  ");
    return Rotate270;
}
