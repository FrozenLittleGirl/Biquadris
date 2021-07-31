#include "jblock.h"
#include "block.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


Jblock::Jblock(int x, int y, int angle, bool isHeavy, int heavyCount, char name): 
Block(0, 0, 0, isHeavy, heavyCount, 'J') {};

vector<string> Jblock::getRotateDefault() {
    vector<string> RotateDefault;
    RotateDefault.push_back("    ");
    RotateDefault.push_back("    ");
    RotateDefault.push_back("J   ");
    RotateDefault.push_back("JJJ ");
    return RotateDefault;
}

vector<string> Jblock::getRotate90() {
    vector<string> Rotate90;
    Rotate90.push_back("    ");
    Rotate90.push_back("JJ  ");
    Rotate90.push_back("J   ");
    Rotate90.push_back("J   ");
    return Rotate90;
}


vector<string> Jblock::getRotate180() {
    vector<string> Rotate180;
    Rotate180.push_back("    ");
    Rotate180.push_back("    ");
    Rotate180.push_back("JJJ ");
    Rotate180.push_back("  J ");
    return Rotate180;
}


vector<string> Jblock::getRotate270() {
    vector<string> Rotate270;
    Rotate270.push_back("    ");
    Rotate270.push_back(" J  ");
    Rotate270.push_back(" J  ");
    Rotate270.push_back("JJ  ");
    return Rotate270;
}
