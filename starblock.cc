#include "starblock.h"
#include "block.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


starblock::starblock(int x, int y, int angle, bool isHeavy, int heavyCount, char name): 
Block(x, y, 0, false, 0, '*') {};



vector<string> starblock::getRotateDefault() {
    vector<string> RotateDefault;
    RotateDefault.push_back("    ");
    RotateDefault.push_back("    ");
    RotateDefault.push_back("    ");
    RotateDefault.push_back("*   ");
    return RotateDefault;
}

vector<string> starblock::getRotate90() {
    vector<string> Rotate90;
    Rotate90.push_back("    ");
    Rotate90.push_back("    ");
    Rotate90.push_back("    ");
    Rotate90.push_back("*   ");
    return Rotate90;
}


vector<string> starblock::getRotate180() {
    vector<string> Rotate180;
    Rotate180.push_back("    ");
    Rotate180.push_back("    ");
    Rotate180.push_back("    ");
    Rotate180.push_back("*   ");
    return Rotate180;
}


vector<string> starblock::getRotate270() {
    vector<string> Rotate270;
    Rotate270.push_back("    ");
    Rotate270.push_back("    ");
    Rotate270.push_back("    ");
    Rotate270.push_back("*   ");
    return Rotate270;
}
