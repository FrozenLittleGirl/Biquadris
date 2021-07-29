#include "cell.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


Cell::Cell(size_t x, size_t y, bool occupied, char c): 
x{x}, y{y}, occupied{occupied}, name {c} {}


size_t Cell::getX() {
    return this->x; 
}


size_t Cell::getY() {
    return this->y; 
}


void Cell::setX(size_t x) {
    this->x = x;
}

void Cell::setY(size_t y) {
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
