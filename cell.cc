#include "cell.h"
#include <iostream>
#include <vector>
#include <string>
#include "view.h"
#include "window.h"
#include "SpecialActions.h"
#include "Action.h"

using namespace std;


Cell::Cell(int x, int y, bool occupied, char c)
    : x{x}, y{y}, occupied{occupied}, name {c}, colour{Xwindow::Black} 
{}

void Cell::setColour() {
    if (name == ' ') {
        colour = Xwindow::Black;
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
    // colour to display NextBlock
    if (name == 'N') {
        colour = Xwindow::White;
    }
}

void Cell::display(int x_coord, int y_coord, bool isBlind) {
    if ( !view || !view->isGraphical() ) {
        return; 
    }
    cout << "isBlind: " << isBlind << endl;
    if ( isBlind && (2 <= y && y <= 8) && (6 <= x && x <= 15) ) {
        view->fillCell(graphicx + x_coord, graphicy + y_coord, 27, Xwindow::White);
    } else {
        view->fillCell(graphicx + x_coord, graphicy + y_coord, 27, colour);
    }
}

int Cell::getX() {
    return this->x; 
}


int Cell::getY() {
    return this->y; 
}   

void Cell::setDisplay(View *v) {
    this->view = v;
}

void Cell::setX(int x) {
    this->x = x;
}

void Cell::setY(int y) {
    this->y = y;
}

void Cell::setGraphics(int x, int y) {
    this->graphicx = x;
    this->graphicy = y;
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
    level_n = 0;
}

void Cell::setLevel(int level_n) {
    this->level_n = level_n;
}

int Cell::getLevel() {
    return level_n;
}

bool Cell::getOccupied() {
    return occupied;
}

void Cell::setOccupied(bool set) {
    this->occupied = set;
}


