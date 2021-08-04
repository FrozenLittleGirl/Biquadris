#include <iostream>
#include <vector>
#include <string>
#include "block.h"

Block::Block(int x, int y, int angle, bool isHeavy, int heavyCount, char name):
xCoord{x}, yCoord{y}, rotateAngle{angle}, heavy{isHeavy}, howHeavy{heavyCount}, name{name} {}



int Block::getXcoord() {
    return xCoord;
}




int Block::getYcoord() {
    return yCoord;
}



int Block::getAngle() {
    return rotateAngle;
}




bool Block::isHeavy() {
    return heavy;
}



int Block::getHowHeavy() {
    return howHeavy;
}


char Block::getName() {
    return name;
}


void Block::setXcoord(int x) {
    this->xCoord = x;
}



void Block::setYcoord(int y) {
    this->yCoord = y;
}



void Block::setAngle(int angle) {
    this->rotateAngle = angle;
}



void Block::setHeavy(bool isHeavy) {
    this->heavy = isHeavy;
}



void Block::setHowHeavy(int heavyCount) {
    this->howHeavy = heavyCount;
}

void Block::setLevel(int level_n) {
    this->level_n = level_n;
}

int Block::getLevel() {
    return level_n;
}
