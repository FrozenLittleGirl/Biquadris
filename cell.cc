#include "cell.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


Cell::Cell(int x, int y, bool occupied, char c): 
x{x}, y{y}, occupied{occupied}, name {c} {}


int Cell::getX() {
    return this->x; 
}


int Cell::getY() {
    return this->y; 
}


void Cell::setX(int x) {
    this->x = x;
}

void Cell::setY(int y) {
    this->y = y;
}

bool Cell::isOccupied() {
    return occupied;
}


void Cell::setName(char c) {
    this->name = c;
    occupied = true;
}


char Cell::getName() {
    return name;
}


void Cell::clearCell() {
    this->name = ' ';
    occupied = false;
}




