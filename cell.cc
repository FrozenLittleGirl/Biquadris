#include "cell.h"
#include <iostream>
#include <vector>
#include <string>
#include "display.h"
#include "window.h"
using namespace std;


Cell::Cell(int x, int y, bool occupied, char c): 
x{x}, y{y}, occupied{occupied}, name {c}, colour{Xwindow::White} {
}

int Cell::getX() {
    return this->x; 
}

void Cell::setColour() {
    if (name == ' ') {
        colour = Xwindow::White;
    }
    if (name == '*') {
        colour = Xwindow::Brown;
    }
    if (name == 'J') {
        colour = Xwindow::Blue;
    }
    if (name == 'I') {
        colour = Xwindow::Red;
    }
    if (name == 'L') {
        colour = Xwindow::Yellow;
    }
    if (name == 'O') {
        colour = Xwindow::Green;
    }
    if (name == 'S') {
        colour = Xwindow::Purple;
    }
    if (name == 'Z') {
        colour = Xwindow::Cyan;
    }
    if (name == 'T') {
        colour = Xwindow::Orange;
    }
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




