#include <iostream>
#include <vector>
#include <string>
#include "block.h"

Block::Block(size_t x, size_t y, size_t angle, bool isHeavy, size_t heavyCount, char name):
xCoord{x}, yCoord{y}, rotateAngle{angle}, heavy{isHeavy}, howHeavy{heavyCount}, name{name} {}



size_t Block::getXcoord() {
    return xCoord;
}




size_t Block::getYcoord() {
    return yCoord;
}



size_t Block::getAngle() {
    return rotateAngle;
}




bool Block::isHeavy() {
    return heavy;
}



size_t Block::getHowHeavy() {
    return howHeavy;
}


char Block::getName() {
    return name;
}


void Block::setXcoord(size_t x) {
    this->xCoord = x;
}



void Block::setYcoord(size_t y) {
    this->yCoord = y;
}



void Block::setAngle(size_t angle) {
    this->rotateAngle = angle;
}



void Block::setHeavy(bool isHeavy) {
    this->heavy = isHeavy;
}



void Block::setHowHeavy(size_t heavyCount) {
    this->howHeavy = heavyCount;
}
